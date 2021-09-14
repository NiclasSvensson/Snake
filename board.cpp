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
    snake = new Snake(2,2,resource);
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