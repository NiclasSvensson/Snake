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
    public:
        Board();
        bool Draw(sf::RenderWindow &window);
        ~Board();
};

#endif