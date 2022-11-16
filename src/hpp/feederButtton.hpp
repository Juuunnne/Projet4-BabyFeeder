#pragma once
#include <SDL2/SDL.h>
#include <iostream>
#include "./button.hpp"

class feederButton
{
public:
    feederButton();
    feederButton(int px, int py);
    ~feederButton();
    void setQuantity(int q, int mx, int mn);
    void setFeeder(int x, int y);
    void drawFeeder(SDL_Renderer *renderer);

private:
    int quantity;
    int max;
    int min;
    int posTx;
    int posTy;
    int posx;
    int posy;

    
    void verifyQuantity();
    void changeQuantity(bool increase, int amount);
};