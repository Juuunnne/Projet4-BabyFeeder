#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <iostream>

using namespace std;

class Interface
{
public:
    Interface();
    ~Interface();

    void setBackground(SDL_Renderer *renderer);

private:
};
