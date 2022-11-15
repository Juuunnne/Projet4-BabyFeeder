#include "./hpp/App.hpp"

bool runApp = true;
SDL_Window *window;
SDL_Renderer *renderer;

bool InitSDL()
{
    bool success = true;
    const char *title = "Biberon";

    // Init SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        cout << "Failed to init SDL, Error : " << SDL_GetError() << endl;
        success = false;
    }

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

void AppLoop()
{
    SDL_Event e;
    SDL_ShowCursor(SDL_ENABLE);

    //Init All Objects
    Interface BG;
    option op;

    // Initialization of SDL
    if (InitSDL() != true)
    {
        cout << "Failed to initialize" << endl;
    } else {
        BG.setBackground(renderer);
    }

    // While App running, close window when click on X
    while (runApp)
    {
        // main loop
        UpdateDisplay();
        
        while (SDL_PollEvent(&e))
        {
            if (e.type == SDL_QUIT)
            {
                runApp = false;
                closeAll();
                break;
            }
        }
    }
}

void UpdateDisplay()
{
    SDL_RenderClear(renderer);
    //All draw function
    SDL_RenderPresent(renderer);
}