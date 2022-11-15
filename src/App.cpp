#include "./hpp/App.hpp"

bool runApp = true;

// Init All Objects
Window win;
Interface BG;
option op;

void AppLoop()
{
    SDL_Event e;
    SDL_ShowCursor(SDL_ENABLE);

    // Initialization of SDL
    if (win.InitSDL() != true)
    {
        cout << "Failed to initialize" << endl;
    }

    // While App running, close window when click on X
    while (runApp)
    {
        // main loop
        // UpdateDisplay(win.getRenderer());
        BG.setBackground(win.getRenderer());

        while (SDL_PollEvent(&e))
        {
            if (e.type == SDL_QUIT)
            {
                runApp = false;
                break;
            }
        }
    }
}

// void UpdateDisplay(SDL_Renderer *renderer)
// {
//     SDL_RenderClear(renderer);
//     BG.setBackground(win.getRenderer());
//     op.drawOptionButton(win.getRenderer());
//     // All draw function
//     SDL_RenderPresent(renderer);
// }