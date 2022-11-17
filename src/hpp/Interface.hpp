#pragma once
#include <SDL2/SDL.h>
#include <iostream>
// #include "../include/SDL2/SDL_image.h"

using namespace std;

class Interface
{
public:
SDL_Surface *image;
SDL_Texture *monImage;
    Interface();
    Interface(SDL_Renderer *renderer);
    ~Interface();

    void setBackground(SDL_Renderer *renderer);
    void drawBaby(SDL_Renderer *renderer);
private:
};
