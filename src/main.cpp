#include "./hpp/Feeder.hpp"
#include "./hpp/Interface.hpp"
#include "./hpp/feederButtton.hpp"
#include "./hpp/option.hpp"
#include "./hpp/button.hpp"

const int SCREEN_WIDTH = 420;
const int SCREEN_HEIGHT = 600;
bool runApp = true;

SDL_Window *window = NULL;
SDL_Renderer *renderer = NULL;

bool init();
void closeAll();

using namespace std;

bool init()
{
    bool success = true;
    const char *title = "Biberon";
    // Init SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        cout << "Failed to init SDL, Error : " << SDL_GetError() << endl;
        success = false;
    }else TTF_Init();
    // Create window
    window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    if (window == NULL)
    {
        cout << "Faile to create, Error : " << SDL_GetError() << endl;
    }
    // Create renderer
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (renderer == NULL)
    {
        cout << "Failed to create renderer, Error : " << SDL_GetError() << endl;
    }

    return success;
}

void closeAll()
{
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
}

int main()
{
    SDL_Event e;
    SDL_ShowCursor(SDL_ENABLE);
    //Interface whiteBG;
    option op(renderer);
    
    // Initialization of SDL
    if (init() != true)
    {
        cout << "Failed to initialize" << endl;
    }
    else
    {
        //whiteBG.setBackground(renderer);    
    }
    // While App running, close window when click on X
    while (runApp)
    {
        while (SDL_PollEvent(&e))
        {
            if (e.type == SDL_QUIT)
            {
                runApp = false;
            }
        }
    }
    return 0;
}