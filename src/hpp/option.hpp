#include <SDL2/SDL.h>
#include <functional>
#include <tuple>
#include "./feederButtton.hpp"
#include "./button.hpp"

using namespace std;

class option
{
public:
//créer un struct pour chaque Button?
    Button opBt;
    int age = 0;

    option();
    ~option();
    void setOption (int px, int py, int w, int h, int r, int g, int b, int a);
    void drawOption(SDL_Renderer* renderer);
    int changeAge();
    tuple<int, int, int, int> getButtons();

private:
    bool active = false;
};