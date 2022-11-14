#include "./hpp/feederButtton.hpp"

feederButton::feederButton() {
    /*Image's URL : "../public/img/feeding-bottle.png"*/
    /*Load Image and Add to the Texture*/
}

feederButton::~feederButton() {
    /*Destroy Image and Texture*/
}

void feederButton::setQuantity(int q, int mx, int mn) {
    this->quantity = q;
    this->max = mx;
    this->min= mn;
}

void feederButton::setFeeder(int x, int y) {
    this->posx = x;
    this->posy = y;
    this->posTx = this->posx - NULL/*img size x*/ * ((2* NULL/*img size x*/) / 3);
    this->posTy = this->posy - NULL/*img size y*/ * ((2* NULL/*img size y*/) / 3);

    showFeeder();
}

void feederButton::showFeeder() {
    /*Display Image and Quantity Text*/
    /*Create 2 buttons for increase or reduce quantity*/
}

void feederButton::verifyQuantity() {
    if (quantity > max) {
        this->quantity = max;
        printf("you can't increase more");
    }
    if (quantity < min) {
        this->quantity = min;
        printf("You can't reduce more !");
    }
}

void feederButton::changeQuantity(bool increase, int amount) {
    switch (increase) {
        case true :
            this->quantity =+ amount;
            this->verifyQuantity();
            break;
        case false :
            this->quantity =- amount;
            this->verifyQuantity();
            break;
        default :
            this->verifyQuantity();
            break;
    }
}