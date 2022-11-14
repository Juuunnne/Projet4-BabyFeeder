#include <SDL2/SDL.h>
#include <iostream>

class feederButton
{
public:
    feederButton();
    ~feederButton();
    void setQuantity(int q, int mx, int mn);
    void setFeeder(int x, int y);

private:
    int quantity;
    int max;
    int min;
    int posTx;
    int posTy;
    int posx;
    int posy;

    void showFeeder();
    void verifyQuantity();
    void changeQuantity(bool increase, int amount);
};

/*We should associate feeder and option objects just after created it with SQ/setQuantity(int q)*/