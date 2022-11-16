#include "./hpp/option.hpp"

option::option()
{
}

option::~option()
{
}

auto option::drawOptionButton(SDL_Renderer *renderer)
{
    struct vals
    {
        int px, py, wi, he;
    };

    if (this->active == true)
    {
        this->showOption();
    }

    Button optionBt(renderer, 20, 20, 30, 30, 106, 107, 106, 255);
    auto [x, y, w, h] = optionBt.buttonMapping();

    return vals{x, y, w, h};
}

void option::setActive()
{
    if (active == true)
    {
        this->active = false;
    }
    else
    {
        this->active = true;
    }
}

void option::showOption(SDL_Renderer* renderer)
{
    if (active == true)
    {
        //Rect for BG
        SDL_Rect bgOp = {210, 200, 420, 100};

        SDL_SetRenderDrawColor(renderer, 116, 116, 116, 255);
        SDL_RenderDrawRect(renderer, &bgOp);
        SDL_RenderFillRect(renderer, &bgOp);
        SDL_RenderPresent(renderer);

        /*Draw a Rect with last time you gave food*/
        /*Draw a Rect with 4 buttons, one for <1month, one for 2->3month, one for 4->6month and one for 7->12month*/
        Button fMonth(renderer, 100, 150, 20, 20, 255, 255, 255, 255);
        Button tMonth(renderer, 200, 150, 20, 20, 255, 255, 255, 255);
        Button thMonth(renderer, 300, 150, 20, 20, 255, 255, 255, 255);
        Button foMonth(renderer, 400, 150, 20, 20, 255, 255, 255, 255);
    }
    else
    {
        /*Do a Flip*/
    }
}

void option::setInformation(feederButton *fb)
{
    switch (this->select)
    {
    case 1:
        fb->setQuantity(650, 800, 450);
        break;
    case 2:
        fb->setQuantity(700, 900, 700);
        break;
    case 3:
        fb->setQuantity(900, 1000, 850);
        break;
    case 4:
        fb->setQuantity(800, 750, 850);
        break;
    default:
        fb->setQuantity(500, 1000, 0);
        break;
    }
}