#pragma once
#include <SDL2/SDL.h>

class Button
{
public:
    Button();
    Button(SDL_Renderer *renderer, int posx, int posy, int width, int height, int r, int g, int b, int a);
    ~Button();

private:

};