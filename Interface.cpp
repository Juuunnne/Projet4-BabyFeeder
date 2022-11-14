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

void Interface::drawButton(SDL_Renderer *renderer, const int SCREEN_WIDTH, const int SCREEN_HEIGHT)
{
    register_button.x = 100;
    register_button.y = SCREEN_HEIGHT / 2;
    register_button.w = SCREEN_WIDTH / 2;
    register_button.h = SCREEN_WIDTH / 4;

    SDL_RenderClear(renderer);
    SDL_SetRenderDrawColor(renderer, 32, 178, 170, 250);
    SDL_RenderDrawRect(renderer, &register_button);
    SDL_RenderFillRect(renderer, &register_button);
    SDL_RenderPresent(renderer);

    
}

bool Interface::onHover(SDL_Renderer *renderer, const int SCREEN_WIDTH, const int SCREEN_HEIGHT)
{
    mousePoint.x = 1;
    mousePoint.y = 1;
    SDL_GetMouseState(&mousePoint.x, &mousePoint.y);

    if (mousePoint.x >= register_button.x && mousePoint.x <= (register_button.x + SCREEN_WIDTH / 2))
    {
        if (mousePoint.y >= register_button.y && mousePoint.y <= (register_button.y + SCREEN_HEIGHT / 4))
        {
            return true;
        }
    }
    return false;
}

void Interface::clickRender(SDL_Renderer *renderer)
{

    
    SDL_Texture *buttonText;
    if (clicked())
    {
        SDL_RenderClear(renderer);
        registerButtonText = TTF_RenderText_Solid(Sans, "Register", Black);
        buttonText = SDL_CreateTextureFromSurface(renderer, registerButtonText);
        SDL_QueryTexture(buttonText,NULL,NULL,&register_button.x,&register_button.y);
        SDL_RenderCopy(renderer, buttonText, NULL, &register_button);
        SDL_RenderPresent(renderer);
        
    }
}

bool Interface::clicked(){
    return true;
}