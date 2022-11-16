#pragma once
#include <functional>
#include <SDL2/SDL.h>

class Button
{
public:
    int px;
    int py;
    int w;
    int h;

    Button();
    Button(SDL_Renderer *renderer, int posx, int posy, int width, int height, int r, int g, int b, int a);
    ~Button();
    auto buttonMapping();

private:
};