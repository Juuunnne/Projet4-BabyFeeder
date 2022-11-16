#include <SDL2/SDL.h>
#include "./feederButtton.hpp"
#include "./button.hpp"

using namespace std;

class option
{
public:
    int select;

    option();
    ~option();
    auto drawOptionButton(SDL_Renderer* renderer);
    void setActive();
    void showOption();
    void setInformation(feederButton* fb);

private:
    bool active = false;
};