#pragma once
#include <SDL2/SDL.h>
#include <iostream>
#include <tuple>
#include "./button.hpp"

class feederButton
{
public:
    Button fButton;

    feederButton();
    ~feederButton();
    void setQuantity(int q, int mx, int mn);
    void setFeeder(int px, int py, int w, int h, int r, int g, int b, int a);
    void drawFeederButtons(SDL_Renderer *renderer);
    void drawFeeder(SDL_Renderer *renderer);
    tuple<int, int, int, int> getButtons();

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