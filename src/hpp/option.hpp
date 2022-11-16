#include <SDL2/SDL.h>
#include <functional>
#include "./feederButtton.hpp"
#include "./button.hpp"

using namespace std;

class option
{
public:
//créer un struct pour chaque Button?
    Button opBt;
    SDL_Rect bgOp;
    Button fMonth;
    Button tMonth;
    Button thMonth;
    Button foMonth;

    option();
    ~option();
    void setOption();
    void drawOption(SDL_Renderer* renderer, feederButton fb);
    void setActive();
    void showOption(SDL_Renderer* renderer, feederButton fb);
    void setInformation(feederButton fb, int select);


private:
    bool active = false;
};