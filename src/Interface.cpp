#include "./hpp/Interface.hpp"

Interface::Interface()
{
}

// Interface::Interface(SDL_Renderer *renderer)
// {
//     image = SDL_LoadBMP("../public/img/baby.png");
//     if (!image)
//     {
//         printf("Erreur de chargement de l'image : %s", SDL_GetError());
//     }

//     monImage = SDL_CreateTextureFromSurface(renderer, image);
// }

Interface::~Interface()
{
}

void Interface::setBackground(SDL_Renderer *renderer)
{
    SDL_SetRenderDrawColor(renderer, 240, 223, 242, 255);
    SDL_RenderClear(renderer);
    SDL_RenderPresent(renderer);
}

// void Interface::drawBaby(SDL_Renderer *renderer)
// {
//     SDL_Rect dest = {200 / 2 - image->w / 2, 350 / 2 - image->h / 2, 0, 0}; 
//     SDL_RenderCopy(renderer, monImage, NULL, &dest);                             
//     SDL_RenderPresent(renderer);
// }