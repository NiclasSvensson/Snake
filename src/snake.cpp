#include <iostream>
#include <SFML/Graphics.hpp>
#include "snake.h"
#include "constants.h"
#include "resource.h"

Segment::Segment(bool head, bool tail, int x, int y, Resource *r): head(head), tail(tail), x(x), y(y){
    resource = r;
    sprite.setOrigin(sf::Vector2f(float(HALF_SQUARE), float(HALF_SQUARE)));
}

void Segment::Draw(sf::RenderWindow &window, int xn, int yn, bool dead){
    if (next != NULL){
        next -> Draw(window, x, y, dead);
    }
    sprite.setPosition(MARGIN+x*SQUARE_WIDTH+HALF_SQUARE, MARGIN+y*SQUARE_WIDTH+HALF_SQUARE);
    if(head){
        sprite.setTexture(resource -> Snake(3, dead));
        if(xn > 0){
            sprite.setRotation(180.0f);
        } else if(xn < 0){
            sprite.setRotation(0.0f);
        } else if(yn > 0){
            sprite.setRotation(270.0f);
        } else if(yn < 0){
            sprite.setRotation(90.0f);
        }
    } else if(tail){
        sprite.setTexture(resource -> Snake(1, dead));
        if(xn > x){
            sprite.setRotation(180.0f);
        } else if(xn < x){
            sprite.setRotation(0.0f);
        } else if(yn > y){
            sprite.setRotation(270.0f);
        } else if(yn < y){
            sprite.setRotation(90.0f);
        }
    } else if(xn - (next -> x) == 0 || yn - (next -> y) == 0) {
        sprite.setTexture(resource -> Snake(0, dead));
        if (xn - (next -> x) == 0){
            sprite.setRotation(90.0f);
        } else {
            sprite.setRotation(0.0f);
        }
    } else {
        sprite.setTexture(resource -> Snake(2, dead));
        if(xn > x){
            if (y > (next -> y)){
                sprite.setRotation(90.0f);
            } else {
                sprite.setRotation(180.0f);
            }
        } else if(xn < x){
            if (y > (next -> y)){
                sprite.setRotation(0.0f);
            } else {
                sprite.setRotation(270.0f);
            }
        } else if(yn > y){
            if (x > (next -> x)){
                sprite.setRotation(270.0f);
            } else {
                sprite.setRotation(180.0f);
            }
        } else if(yn < y){
            if (x > (next -> x)){
                sprite.setRotation(0.0f);
            } else {
                sprite.setRotation(90.0f);
            }
        }
    }
    window.draw(sprite);
}

void Segment::Move(int xn, int yn){
    if(next != NULL) {
        next -> Move(x, y);
    }
    x = xn; y = yn;
}

Snake::Snake(int x, int y, Resource *r){
    resource = r;
    head = new Segment(true, false, x, y, r);
    head -> next = new Segment(false, false, x+1, y, r);
    head -> next -> next = new Segment(false, true, x+2, y, r);
    head -> next -> next -> next = NULL;
    x_dir = -1; y_dir = 0;

    apple.setPosition(MARGIN+a_x*SQUARE_WIDTH, MARGIN+a_y*SQUARE_WIDTH);
    apple.setTexture(resource -> Apple());
}

void Snake::Draw(sf::RenderWindow &window){
    window.draw(apple);
    head -> Draw(window, x_dir, y_dir, dead);
}

void Snake::Move(sf::Event &event){
    int x_d = x_dir; int y_d = y_dir;
    if (event.key.code == sf::Keyboard::Up){
        x_d = 0; y_d = -1;
    } else if (event.key.code == sf::Keyboard::Down){
        x_d = 0; y_d = 1;
    } else if (event.key.code == sf::Keyboard::Left){
        x_d = -1; y_d = 0;
    } else if (event.key.code == sf::Keyboard::Right){
        x_d = 1; y_d = 0;
    }
    if (x_d + x_dir == 0 || y_d + y_dir == 0)
    {
        x_d = x_dir; y_d = y_dir;
    }
    if(clock.getElapsedTime().asSeconds() > 0.5f){
        x_dir = x_d; y_dir = y_d;
        if (((head -> x) == a_x) && ((head -> y) == a_y)){
            ++ length;
            Segment *spawn = new Segment(false, false, head -> x, head -> y, resource);
            head -> x = (head -> x) + x_dir;
            head -> y = (head -> y) + y_dir;
            spawn -> next = head -> next;
            head -> next = spawn;
            if (length < WIDTH*HEIGHT){
                Spawn_Apple();
            }
        } else {
            head -> next -> Move(head -> x, head -> y);
            head -> x = (head -> x) + x_dir;
            head -> y = (head -> y) + y_dir;
        }
        clock.restart();
    }
}

void Snake::Spawn_Apple(){
    a_x = rand() % WIDTH;
    a_y = rand() % HEIGHT;
    while (InSnake(head, a_x, a_y)){
        a_x = rand() % WIDTH;
        a_y = rand() % HEIGHT;
    }
    apple.setPosition(MARGIN+a_x*SQUARE_WIDTH, MARGIN+a_y*SQUARE_WIDTH);
}

bool Snake::InSnake(Segment *start, int x, int y){
    Segment *ptr = start;
    while(ptr != NULL){
        if (ptr -> x == x && ptr -> y == y){
            return true;
        }
        ptr = ptr -> next;
    }
    return false;
}

bool Snake::IsDead(){
    if(InSnake(head -> next, head -> x, head -> y)){
        dead = true;
        return true;
    } else if(head -> x < 0 || head -> x >= WIDTH){
        dead = true;
        return true;
    } else if(head -> y < 0 || head -> y >= HEIGHT){
        dead = true;
        return true;
    }
    return false;
}

int Snake::Length(){
    return length;
}

Snake::~Snake(){
    Segment *ptr_curr = head;
    Segment *ptr_next;
    while(ptr_curr != NULL){
        ptr_next = ptr_curr -> next;
        delete ptr_curr;
        ptr_curr = ptr_next;
    }
}