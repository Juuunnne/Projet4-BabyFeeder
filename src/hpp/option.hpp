#include <functional>
#include <SDL2/SDL.h>
#include "./button.hpp"

using namespace std;

class option
{
public:
    int select;

    option();
    ~option();
    void drawOptionButton(SDL_Renderer* renderer);
    void setActive();
    void showOption();

private:
    bool active = false;
 
    void setInformation();
};

/*We should associate feeder and option objects just after created it with SQ/setQuantity(int q)*/