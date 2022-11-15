#include <functional>
#include <SDL2/SDL.h>
#include "./button.hpp"

using namespace std;

class option
{
public:
    int select;
    function<void(int q, int mx, int mn)> SQ; /*function -> setQuantity(int q);*/

    option();
    ~option();
    void drawOptionButton(SDL_Renderer* renderer);
    void setActive();
    void showOption();
    void linkFunction(function<void(int q, int Mx, int mn)> sq);

private:
    bool active = false;
    
    void setInformation();
};

/*We should associate feeder and option objects just after created it with SQ/setQuantity(int q)*/