#include "./hpp/button.hpp"

Button::Button()
{
}

Button::~Button()
{
}

void Button::setButton(int px, int py, int w, int h, int r, int g, int b, int a)
{
    this->posx = px;
    this->posy = py;
    this->width = w;
    this->height = h;
    this->red = r;
    this->green = g;
    this->blue = b;
    this->alpha = a;
}

void Button::drawButton(SDL_Renderer* renderer)
{
    SDL_Rect bt = {this->posx, this->posy, this->width, this->height};

    SDL_SetRenderDrawColor(renderer, this->red, this->green, this->blue, this->alpha);
    SDL_RenderDrawRect(renderer, &bt);
    SDL_RenderFillRect(renderer, &bt);
    SDL_RenderPresent(renderer);
}