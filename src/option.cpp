#include "./hpp/option.hpp"

option::option()
{
    
}

option::~option()
{
    /*Destroy surface and texture*/
}

// void option::setActive()
// {
//     switch (this->active)
//     {
//     case true:
//         this->active = false;
//         this->showOption();
//         break;

//     case false:
//         this->active = true;
//         this->showOption();
//         break;

//     default:
//         /*Do a Flip*/
//         break;
//     }
// }

// void option::showOption()
// {
//     switch (active)
//     {
//     case true:
//         /*Draw a Rect for background*/
//         /*Draw a Rect with last time you gave food*/
//         /*Draw a Rect with 4 buttons, one for <1month, one for 2->3month, one for 4->6month and one for 7->12month*/
//         break;
//     case false :
//         /*Destroy all*/
//         break;
//     default :
//         /*Verify if there is something in the surface*/
//         /*if yes destroy*/
//         /*else Do a Flip*/
//         break;
//     }
// }

// void option::linkFunction(function<void(int q, int Mx, int mn)> sq)
// {
//     this->SQ = sq;
// }

// void option::setInformation()
// {
//     switch (this->select)
//     {
//     case 1:
//         this->SQ(650, 800, 450);
//         break;
//     case 2:
//         this->SQ(700, 900, 700);
//         break;
//     case 3:
//         this->SQ(900, 1000, 850);
//         break;
//     case 4:
//         this->SQ(800, 750, 850);
//         break;
//     default:
//         this->SQ(500, 1000, 0);
//         break;
//     }
// }