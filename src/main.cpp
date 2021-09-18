#include <iostream>
#include <filesystem>
#include <SFML/Graphics.hpp>
#include "resource.h"
#include "constants.h"
#include "board.h"

int main(){
    sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Snake", sf::Style::Titlebar | sf::Style::Close);

    sf::Image icon;
    icon.loadFromFile("../assets/apple.png");
    sf::Vector2u v = icon.getSize();
    window.setIcon(v.x, v.y, icon.getPixelsPtr());

    while(true){
        Board board;
        if (!board.Draw(window)){
            break;
        }
    }

    return 0;
}