#ifndef RESOURCE
#define RESOURCE

class Resource{
private:
    sf::Image snake_image;
    sf::Texture *snake;
    sf::Texture apple;
    sf::Image gras_image;
    sf::Texture *gras;
    sf::Image snake_dead_image;
    sf::Texture *snake_dead;
public:
    Resource();
    sf::Texture& Apple();
    sf::Texture& Gras(int i);
    sf::Texture& Snake(int i, bool dead);
    ~Resource();
};

#endif