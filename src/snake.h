#include "resource.h"

#ifndef SNAKE
#define SNAKE

class Segment{
    private:
        bool head;
        bool tail;
        sf::Sprite sprite;
        sf::Vector2f v;
        sf::Vector2f u;
        Resource* resource;
    public:
        Segment *next;
        int x, y;
        Segment(bool head, bool tail, int x, int y, Resource *r);
        void Draw(sf::RenderWindow &window, int xn, int yn, bool dead);
        void Move(int xn, int yn);
};

class Snake{
    private:
        int x_dir, y_dir;
        int a_x = 1, a_y = 1;
        int length = 3;
        bool dead = false;
        Segment *head;
        Resource *resource;
        sf::Clock clock;
        sf::Sprite apple;
    public:
        Snake(int x, int y, Resource *r);
        void Draw(sf::RenderWindow &window);
        void Move(sf::Event &event);
        void Spawn_Apple();
        bool InSnake(Segment *start, int x, int y);
        bool IsDead();
        int Length();
        ~Snake();
};

#endif