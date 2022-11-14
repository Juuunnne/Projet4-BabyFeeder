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

    void iitMenu();
    void displayMenu();
    void loadMedia();
    void display_time();
    void setBackground(SDL_Renderer *renderer);
    void drawButton(SDL_Renderer *renderer, const int SCREEN_WIDTH,const int SCREEN_HEIGHT);
    bool onHover(SDL_Renderer *renderer,const int SCREEN_WIDTH,const int SCREEN_HEIGHT);
    void clickRender(SDL_Renderer *renderer);
    bool clicked();

private:
    SDL_Rect register_button;
    SDL_Rect reduce_button;
    SDL_Rect mousePoint;
    SDL_Surface *registerButtonText;
    SDL_Surface *layer2;
    SDL_Surface *layer3;
    //Font Style
    TTF_Font *Sans = TTF_OpenFont("OpenSans-Bold.ttf",20);
    SDL_Color Black{0,0,0};
}; 



