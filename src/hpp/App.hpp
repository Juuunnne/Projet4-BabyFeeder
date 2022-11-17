#include "./Interface.hpp"
#include "./feederButtton.hpp"
#include "./option.hpp"
#include "./button.hpp"
#include "./windows.hpp"
#include "./timer.hpp"
// #include "./Shoppinglist.hpp"

using namespace std;

void AppLoop();
void UpdateDisplay(SDL_Renderer* renderer);
void OnClick();
void setMapButton(int x, int y, int w, int h);
int onHover();
void setByAge(int a);
void setQuantity(int q, int mx, int mn);
void verifyQuantity();