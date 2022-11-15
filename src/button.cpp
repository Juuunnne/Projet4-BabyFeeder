#include "./hpp/button.hpp"

Button::Button() {

}

Button::Button(SDL_Renderer *renderer, int posx, int posy, int width, int height, int r, int g, int b, int a) {
    SDL_Rect button = {posx, posy, width, height};

    SDL_SetRenderDrawColor(renderer, r, g, b, a);
    SDL_RenderDrawRect(renderer, &button);
    SDL_RenderFillRect(renderer, &button);
}

Button::~Button() {

}

