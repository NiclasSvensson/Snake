#include <iostream>
#include <SFML/Graphics.hpp>
#include "resource.h"
#include "constants.h"

Resource::Resource(){
    sf::IntRect rect(0,0,SQUARE_WIDTH,SQUARE_WIDTH);

    snake_image = sf::Image();
    snake_image.loadFromFile("assets/snake.png");
    snake = new sf::Texture[4];
    for (int i = 0; i < 4; i++){
        rect.top = i * 32;
        snake[i] = sf::Texture();
        snake[i].loadFromImage(snake_image, rect);
    } 

    apple = sf::Texture();
    apple.loadFromFile("assets/apple.png");

    gras_image = sf::Image();
    gras_image.loadFromFile("assets/gras.png");
    gras = new sf::Texture[4];
    rect.top = 0;
    for (int i = 0; i < 4; i++){
        rect.top = i * 32;
        gras[i] = sf::Texture();
        gras[i].loadFromImage(gras_image, rect);
    } 

    snake_dead_image = sf::Image();
    snake_dead_image.loadFromFile("assets/snake_dead.png");
    snake_dead = new sf::Texture[4];
    rect.top = 0;
    for (int i = 0; i < 4; i++){
        rect.top = i * 32;
        snake_dead[i] = sf::Texture();
        snake_dead[i].loadFromImage(snake_dead_image, rect);
    } 
}

sf::Texture& Resource::Apple(){
    return apple;
}

sf::Texture& Resource::Gras(int i){
    return gras[i];
}

sf::Texture& Resource::Snake(int i, bool dead){
    if(!dead){
        return snake[i];
    } else {
        return snake_dead[i];
    }
}

Resource::~Resource(){
    delete [] snake;
    delete [] snake_dead;
    delete [] gras;
}