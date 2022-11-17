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

// void option::setInformation(feederButton fb, int select)
// {
//     switch (select)
//     {
//     case 1:
//         fb.setQuantity(650, 800, 450);
//         break;
//     case 2:
//         fb.setQuantity(700, 900, 700);
//         break;
//     case 3:
//         fb.setQuantity(900, 1000, 850);
//         break;
//     case 4:
//         fb.setQuantity(800, 750, 850);
//         break;
//     default:
//         fb.setQuantity(500, 1000, 0);
//         break;
//     }
// }

tuple<int, int, int, int> option::getButtons() {
    return make_tuple (opBt.posx, opBt.posy, opBt.width, opBt.height);
}