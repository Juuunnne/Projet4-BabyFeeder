#include "../hpp/Feeder.hpp"
#include "../hpp/Interface.hpp"
#include "../hpp/feederButtton.hpp"
#include "../hpp/option.hpp"
#include "../hpp/button.hpp"

using namespace std;

const int SCREEN_WIDTH = 420;
const int SCREEN_HEIGHT = 600;

bool InitSDL();
void closeAll();
void AppLoop();
void UpdateDisplay();