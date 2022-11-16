#include "./hpp/feederButtton.hpp"

feederButton::feederButton()
{
    /*Image's URL : "../public/img/feeding-bottle.png"*/
    /*Load Image and Add to the Texture*/
}

feederButton::feederButton(int px, int py, SDL_Renderer* renderer)
{
    /*Image's URL : "../public/img/feeding-bottle.png"*/
    /*Load Image and Add to the Texture*/
    this->setFeeder(px, py, renderer);
}

feederButton::~feederButton()
{
}

void feederButton::setQuantity(int q, int mx, int mn)
{
    this->quantity = q;
    this->max = mx;
    this->min = mn;
}

void feederButton::setFeeder(int x, int y, SDL_Renderer* renderer)
{
    this->posx = x;
    this->posy = y;
    this->posTx = this->posx - 0 /*img size x*/ * ((2 * 0 /*img size x*/) / 3);
    this->posTy = this->posy - 0 /*img size y*/ * ((2 * 0 /*img size y*/) / 3);
    
    feederButtonMinus.setButton(315, 400, 20, 20, 0, 0, 0, 255);
    feederButtonPlus.setButton(355, 400, 20, 20, 0, 0, 0, 255);
}

void feederButton::drawFeeder(SDL_Renderer *renderer)
{
    /*Display Image and Quantity Text (Jun please)*/

    /*Create 2 buttons for increase or reduce quantity*/
    feederButtonMinus.drawButton(renderer);
    feederButtonPlus.drawButton(renderer);
}
//(posx - (200 /2 +15))

void feederButton::verifyQuantity()
{
    if (quantity > max)
    {
        this->quantity = max;
        printf("you can't increase more"); //ttf please
    }
    if (quantity < min)
    {
        this->quantity = min;
        printf("You can't reduce more !"); //ttf please
    }
}

void feederButton::changeQuantity(bool increase, int amount)
{
    if (increase == true)
    {
        this->quantity = +amount;
        this->verifyQuantity();
    }
    else
    {
        this->quantity = -amount;
        this->verifyQuantity();
    }
}