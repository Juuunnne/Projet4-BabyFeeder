#include "./hpp/option.hpp"

option::option()
{
}

option::~option()
{
}

void option::setOption (int px, int py, int w, int h, int r, int g, int b, int a) {
    this->opBt.setButton(px, py, w, h, r, g, b, a);
}

void option::drawOption(SDL_Renderer* renderer)
{
    this->opBt.drawButton(renderer);    
}

int option::changeAge() {
    return 5;
}

tuple<int, int, int, int> option::getButtons() {
    return make_tuple (opBt.posx, opBt.posy, opBt.width, opBt.height);
}