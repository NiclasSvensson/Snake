#include <iostream>
#include <SFML/Graphics.hpp>
#include <time.h>
#include "board.h"
#include "constants.h"
#include "resource.h"
#include "snake.h"

Board::Board(){
    resource = new Resource();
    list = new sf::Sprite[WIDTH*HEIGHT];

    int x = 0; int y = 0;
    for (int i = 0; i < WIDTH*HEIGHT; i++){
        if (x >= WIDTH)
        {
            x = 0; ++y;
        }
        list[i] = sf::Sprite(resource -> Gras(rand() % 4));
        list[i].setPosition(MARGIN+x*SQUARE_WIDTH, MARGIN+y*SQUARE_WIDTH);
        ++x;
    }
    snake = new Snake(int(WIDTH/2-1), int(HEIGHT/2), resource);

    restart_sprite = sf::Sprite();
    restart_sprite.setTexture(resource -> Restart());
    restart_sprite.setScale(3.0f, 3.0f);
    restart_sprite.setPosition(MARGIN, MARGIN + HEIGHT*SQUARE_WIDTH + BETWEEN);
    restart_bound = restart_sprite.getGlobalBounds();
}

bool Board::Restart(sf::RenderWindow &window, sf::Event &event){
    sf::Vector2i mouse_position = sf::Mouse::getPosition(window);
    if (restart_bound.contains(mouse_position.x, mouse_position.y)){
        if (event.type == sf::Event::MouseButtonReleased && event.mouseButton.button == sf::Mouse::Left){
            return true;
        }
        restart_sprite.setColor(COLOR_FADE);
    } else {
        restart_sprite.setColor(COLOR_NO_FADE);
    }
    window.draw(restart_sprite);
    return false;
}

bool Board::Draw(sf::RenderWindow &window){
    while (window.isOpen()){
        window.clear(BACKGROUND_COLOR);
        sf::Event event;
        while (window.pollEvent(event)){
            if (event.type == sf::Event::Closed)
                window.close();
        }
        for (int i = 0; i < WIDTH*HEIGHT; i++){
            window.draw(list[i]);
        }
        if(snake -> IsDead()){
            
        } else if(snake -> Length() == WIDTH*HEIGHT){

        } else {
            snake -> Move(event);
        }
        if (Restart(window, event)){
            return true;
        }
        snake -> Draw(window);
        window.display();
    }
    return false;
}

Board::~Board(){
    delete snake;
    delete [] list;
    delete resource;
}