#include "./hpp/App.hpp"

bool runApp = true;
int buttonMap[10][3] = {0};

// Init All Objects
Window win;
Interface BG;
option op;
feederButton fdB;

void AppLoop()
{
    Uint32 frameStart, frameTime, frameDelay = 60;
    bool closeRequest = false;

    SDL_Event e;
    SDL_ShowCursor(SDL_ENABLE);

    // Initialization of SDL
    if (win.InitSDL() != true)
    {
        cout << "Failed to initialize" << endl;
    }

    UpdateDisplay(win.getRenderer());

    // While App running, close window when click on X
    while (!closeRequest)
    {
        frameStart = SDL_GetTicks();

        // main loop

        while (SDL_PollEvent(&e) != 0)
        {
            if (e.type == SDL_MOUSEBUTTONDOWN)
            {
                OnClick();
                UpdateDisplay(win.getRenderer());
            }

            if (e.type == SDL_QUIT)
            {
                closeRequest = true;
                break;
            }
        }

        frameTime = SDL_GetTicks() - frameStart;
        if (frameTime < frameDelay)
        {
            SDL_Delay(frameDelay - frameTime);
        }
    }
}

void UpdateDisplay(SDL_Renderer *renderer)
{
    // SDL_RenderClear(renderer);
    BG.setBackground(renderer);
    auto [x, y, w, h] = op.drawOptionButton(renderer);
    setMapButton(x, y, w, h);
    fdB.drawFeeder(renderer);
    // All draw function
    // SDL_RenderPresent(renderer);
}

void OnClick() {
    //calcul si la souris est sur un bouton

    if (canClick == true) {
        switch (index) {

        }
    }
}

void setMapButton(int x, int y, int w, int h) {

    for (int i = 0; i<10; i++) {
        if (buttonMap[i][0] == 0) {
            buttonMap[i][0] = x;
            buttonMap[i][1] = y;
            buttonMap[i][2] = w;
            buttonMap[i][3] = h;
        }
    }
}