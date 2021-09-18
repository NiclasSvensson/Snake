#include "resource.h"
#include "snake.h"

#ifndef BOARD
#define BOARD

class Board {
    private:
        Resource* resource;
        sf::Sprite* list;
        Snake* snake;
        sf::Clock clock;
        sf::Sprite restart_sprite;
        sf::FloatRect restart_bound;
    public:
        Board();
        bool Restart(sf::RenderWindow &window, sf::Event &event);
        bool Draw(sf::RenderWindow &window);
        ~Board();
};

#endif