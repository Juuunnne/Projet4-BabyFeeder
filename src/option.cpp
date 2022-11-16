#include "./hpp/option.hpp"

option::option()
{
    this->setOption();
}

option::~option()
{
}

void option::setOption() {
    this->opBt.setButton(25, 25, 25, 25, 116, 116, 116, 255);
}

void option::drawOption(SDL_Renderer* renderer, feederButton fb)
{
    this->opBt.drawButton(renderer);

    if (this->active) {
        showOption(renderer, fb);
    }    
}

void option::setActive()
{
    if (this->active == true)
    {
        this->active = false;
    }
    else
    {
        this->active = true;
    }
}

void option::showOption(SDL_Renderer* renderer, feederButton fb)
{
    if (this->active == true)
    {
        //Rect for BG
        this->bgOp = {0, 100, 420, 300};

        SDL_SetRenderDrawColor(renderer, 116, 116, 116, 255);
        SDL_RenderDrawRect(renderer, &bgOp);
        SDL_RenderFillRect(renderer, &bgOp);

        /*Draw a Rect with last time you gave food*/

        /*Draw a Rect with 4 buttons, one for <1month, one for 2->3month, one for 4->6month and one for 7->12month*/
        this->fMonth.setButton(100, 150, 20, 20, 255, 255, 255, 255);
        this->tMonth.setButton(200, 150, 20, 20, 255, 255, 255, 255);
        this->thMonth.setButton(300, 150, 20, 20, 255, 255, 255, 255);
        this->foMonth.setButton(400, 150, 20, 20, 255, 255, 255, 255);
    }
    else
    {
        /*Do a Flip*/
    }
}

void option::setInformation(feederButton fb, int select)
{
    switch (select)
    {
    case 1:
        fb.setQuantity(650, 800, 450);
        break;
    case 2:
        fb.setQuantity(700, 900, 700);
        break;
    case 3:
        fb.setQuantity(900, 1000, 850);
        break;
    case 4:
        fb.setQuantity(800, 750, 850);
        break;
    default:
        fb.setQuantity(500, 1000, 0);
        break;
    }
}