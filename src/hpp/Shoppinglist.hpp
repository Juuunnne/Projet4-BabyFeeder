// #pragma once
// #include <SDL2/SDL.h>
// #include <SDL2/SDL_ttf.h>
// #include <iostream>
// #include <cstring>
// #include <vector>
// #include <algorithm>

// using namespace std;

// struct Product
// {
//     int product_number;
//     string product_name;
// };

// class Shoppinglist
// {
// public:
//     Shoppinglist();
//     ~Shoppinglist();

//     int getWidth();
//     int getHeight();
//     void loadFont();
//     void setColor(Uint8 red, Uint8 green, Uint8 blue);
//     void setBlendMode(SDL_BlendMode blending);
//     void addToList();
//     bool loadFromRenderedText(string textureText, SDL_Color textColor, SDL_Renderer *renderer);
//     bool loadShoplist(vector<Product> shop_list, SDL_Color textColor, SDL_Renderer *renderer);
//     void free();
//     void handleEvent(SDL_Event e, SDL_Renderer *renderer);
//     void render(SDL_Renderer *renderer, int x, int y, SDL_Rect *clip = NULL, double angle = 0.0, SDL_Point *center = NULL, SDL_RendererFlip flip = SDL_FLIP_NONE);
//     vector<Product> getShoppinglist();

//     SDL_Color textColor = {0, 0, 0, 250};

// private:
//     Product panier;
//     SDL_Surface *textSurface;
//     SDL_Texture *textTexture;
//     TTF_Font *textFont = NULL;
//     string inputText;

//     vector<Product> shop_list;

//     bool renderText = false;
//     int tWidth, tHeight;
// };
