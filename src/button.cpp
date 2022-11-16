#include "./hpp/button.hpp"

Button::Button()
{
}

Button::Button(SDL_Renderer *renderer, int posx, int posy, int width, int height, int r, int g, int b, int a)
{
    SDL_Rect button = {posx, posy, width, height};

    this->px = posx;
    this->py = posy;
    this->w = width;
    this->h = height;
}

Button::~Button()
{
}

auto Button::buttonMapping()
{
    struct retVals
    {
        int x;
        int y;
        int w;
        int h;
    };
    return retVals{this->px, this->py, this->w, this->h};
}
