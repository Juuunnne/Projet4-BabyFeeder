#include "./hpp/feederButtton.hpp"

feederButton::feederButton()
{
    /*Image's URL : "../public/img/feeding-bottle.png"*/
    /*Load Image and Add to the Texture*/
}

feederButton::~feederButton()
{
}

void feederButton::setFeeder (int px, int py, int w, int h, int r, int g, int b, int a) {
    this->fButton.setButton(px, py, w, h, r, g, b, a);
}

void feederButton::drawFeederButtons(SDL_Renderer *renderer)
{
    this->fButton.drawButton(renderer);
}

void feederButton::drawFeeder(SDL_Renderer *renderer) {
    //Draw image and ttf
} //(posx - (200 /2 +15))

tuple<int, int, int, int> feederButton::getButtons() {
    return make_tuple (fButton.posx, fButton.posy, fButton.width, fButton.height);
}