#include "./hpp/Interface.hpp"

Interface::Interface()
{
}

Interface::~Interface()
{
}

void Interface::setBackground(SDL_Renderer *renderer)
{
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderClear(renderer);
    SDL_RenderPresent(renderer);
}