#include "./hpp/App.hpp"

bool runApp = true;
int buttonMap[10][4] = {0};
int ageMonth = 0;

// Init All Objects
SDL_Rect mousePos;
Window win;
Interface BG;
option opMinus;
option opPlus;
feederButton fdB(400, 400, win.getRenderer());

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
    opMinus.setOption(25, 25, 25, 25, 116, 116, 116, 255);
    auto cordOp1 = opMinus.getButtons();
    setMapButton(get<0>(cordOp1), get<1>(cordOp1), get<2>(cordOp1), get<3>(cordOp1));

    opPlus.setOption(75, 25, 25, 25, 116, 116, 116, 255);
    auto cordOp = opPlus.getButtons();
    setMapButton(get<0>(cordOp), get<1>(cordOp), get<2>(cordOp), get<3>(cordOp));


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
    SDL_RenderClear(renderer);
    BG.setBackground(renderer);
    opPlus.drawOption(renderer, fdB);
    opMinus.drawOption(renderer, fdB);
    fdB.drawFeeder(renderer);
    // All draw function
    SDL_RenderPresent(renderer);
}

void OnClick()
{
    int idButton = 0;
    idButton = onHover();
    switch (idButton) {
        case 0 :
            cout << "boutn moins" << endl;
            ageMonth =- opMinus.changeAge();
            break;
        case 1 :
            cout << "bouton plus" << endl;
            ageMonth =+ opMinus.changeAge();
            break;
        default :
            cout << "pas possible frere" << endl;
            break;
    }
}

void setMapButton(int x, int y, int w, int h)
{
    for (int i = 0; i < 10; i++)
    {
        cout << buttonMap[i][0] << endl;
        if (buttonMap[i][0] == 0)
        {
            buttonMap[i][0] = x;
            buttonMap[i][1] = y;
            buttonMap[i][2] = w;
            buttonMap[i][3] = h;
            break;
        }
    }
}

int onHover()
{
    mousePos.x = 0;
    mousePos.y = 0;
    SDL_GetMouseState(&mousePos.x, &mousePos.y);

    for (int i = 0; i < 10; i++)
    {
        if (mousePos.x >= buttonMap[i][0] && mousePos.x <= buttonMap[i][0] + buttonMap[i][2])
        {
            if (mousePos.y >= buttonMap[i][1] && mousePos.y <= buttonMap[i][1] + buttonMap[i][3])
            {
                return i;
                break;
            }
        }
    }

    return 11;
}