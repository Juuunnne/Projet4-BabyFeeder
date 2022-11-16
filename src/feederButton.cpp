#include "./hpp/feederButtton.hpp"

feederButton::feederButton()
{
    /*Image's URL : "../public/img/feeding-bottle.png"*/
    /*Load Image and Add to the Texture*/
}

feederButton::feederButton(int px, int py)
{
    /*Image's URL : "../public/img/feeding-bottle.png"*/
    /*Load Image and Add to the Texture*/
    this->setFeeder(px, py);
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

void feederButton::setFeeder(int x, int y)
{
    this->posx = x;
    this->posy = y;
    this->posTx = this->posx - 0 /*img size x*/ * ((2 * 0 /*img size x*/) / 3);
    this->posTy = this->posy - 0 /*img size y*/ * ((2 * 0 /*img size y*/) / 3);
}

void feederButton::drawFeeder(SDL_Renderer *renderer)
{
    /*Display Image and Quantity Text (Jun please)*/
    /*Create 2 buttons for increase or reduce quantity*/
    Button feederButtonMinus(renderer, 315, 400, 20, 20, 0, 0, 0, 255);
    Button feederButtonPlus(renderer, 355, 400, 20, 20, 0, 0, 0, 255);
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