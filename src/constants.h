#ifndef CONSTANTS
#define CONSTANTS

const int WIDTH = 12;
const int HEIGHT = 12;

const int MARGIN = 40;
const int SQUARE_WIDTH = 32;
const int BETWEEN = 15;
const int HALF_SQUARE = float(SQUARE_WIDTH/2);
const int WINDOW_WIDTH = WIDTH*SQUARE_WIDTH + 2*MARGIN;
const int WINDOW_HEIGHT = HEIGHT*SQUARE_WIDTH + 2*MARGIN + 65;

const sf::Color BACKGROUND_COLOR(0, 121, 44, 255);
const sf::Color COLOR_FADE(255, 255, 255, 100);
const sf::Color COLOR_NO_FADE(255, 255, 255, 255);

#endif