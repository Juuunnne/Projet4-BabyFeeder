#include "./hpp/App.hpp"

bool runApp = true;
int buttonMap[10][4] = {0};
int Age = 1;
int quantite = 500;
int maxQ = 1000;
int minQ = 5;

// Init All Objects
SDL_Rect mousePos;
Window win;
Interface BG;
option opMinus;
option opPlus;
feederButton fBPlus;
feederButton fBMinus;
timer T(SDL_GetTicks());
timer Tvomi;
// Shoppinglist inputText;

void AppLoop()
{
    Uint32 frameStart, frameTime, frameDelay = 100;
    bool closeRequest = false;

    SDL_Event e;
    SDL_ShowCursor(SDL_ENABLE);

    // Initialization of SDL
    if (win.InitSDL() != true)
    {
        cout << "Failed to initialize" << endl;
    }

    opMinus.setOption(25, 25, 40, 40, 89, 195, 247, 255);
    auto cordOp1 = opMinus.getButtons();
    setMapButton(get<0>(cordOp1), get<1>(cordOp1), get<2>(cordOp1), get<3>(cordOp1));

    opPlus.setOption(75, 25, 40, 40, 57, 128, 250, 255);
    auto cordOp2 = opPlus.getButtons();
    setMapButton(get<0>(cordOp2), get<1>(cordOp2), get<2>(cordOp2), get<3>(cordOp2));

    fBPlus.setFeeder(360, 410, 40, 40, 114, 247, 154, 255);
    auto cordOp3 = fBPlus.getButtons();
    setMapButton(get<0>(cordOp3), get<1>(cordOp3), get<2>(cordOp3), get<3>(cordOp3));

    fBMinus.setFeeder(310, 410, 40, 40, 247, 126, 126, 255);
    auto cordOp4 = fBMinus.getButtons();
    setMapButton(get<0>(cordOp4), get<1>(cordOp4), get<2>(cordOp4), get<3>(cordOp4));

    T.setTimeBt(50, 350, 100, 100, 153, 24, 31, 255);
    auto cordOp5 = T.getButtons();
    setMapButton(get<0>(cordOp5), get<1>(cordOp5), get<2>(cordOp5), get<3>(cordOp5));

    Tvomi.setTimeBt(175, 400, 50, 50, 47, 77, 45, 255);
    auto cordOp6 = Tvomi.getButtons();
    setMapButton(get<0>(cordOp6), get<1>(cordOp6), get<2>(cordOp6), get<3>(cordOp6));

    UpdateDisplay(win.getRenderer());

    // While App running, close window when click on X
    while (!closeRequest)
    {
        frameStart = SDL_GetTicks();

        // main loop
        T.updateTime(Age, SDL_GetTicks());

        while (SDL_PollEvent(&e) != 0)
        {
            // inputText.handleEvent(e, win.getRenderer());

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
    // BG.drawBaby(renderer);
    opPlus.drawOption(renderer);
    opMinus.drawOption(renderer);
    fBPlus.drawFeederButtons(renderer);
    fBMinus.drawFeederButtons(renderer);
    T.drawTimerBt(renderer);
    Tvomi.drawTimerBt(renderer);
    // inputText.render(renderer, 50, 100);
    // All draw function //
    SDL_RenderPresent(renderer);
}

void OnClick()
{
    int idButton = 0;
    idButton = onHover();
    switch (idButton)
    {
    case 0:
        cout << "bouton moins (age en mois)" << endl;
        if (Age > 0)
        {
            Age--;
            setByAge(Age);
        }
        cout << Age << " mois" << endl;
        break;
    case 1:
        cout << "bouton plus (age en mois)" << endl;
        if (Age < 12)
        {
            Age++;
            setByAge(Age);
        }
        cout << Age << " mois" << endl;
        break;
    case 2:
        cout << "Plus de lait" << endl;
        quantite = quantite + 5;
        verifyQuantity();
        cout << quantite << " mL" << endl;
        break;
    case 3:
        cout << "Moins de lait" << endl;
        quantite = quantite - 5;
        verifyQuantity();
        cout << quantite << " mL" << endl;
        break;
    case 4:
        cout << "il a manger !" << endl;
        T.resetTimer(SDL_GetTicks());
        break;
    case 5:
        cout << "il a vomi..." << endl;
        T.resetTimer(SDL_GetTicks());
        break;
    default:
        cout << "Do nothing here." << endl;
        break;
    }
}

void setMapButton(int x, int y, int w, int h)
{
    for (int i = 0; i < 10; i++)
    {
        if (buttonMap[i][0] == 0 && buttonMap[i][1] == 0 && buttonMap[i][2] == 0 && buttonMap[i][3] == 0)
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

void setByAge(int a)
{
    switch (a)
    {
    case 0:
        setQuantity(650, 800, 450);
        break;
    case 1:
        setQuantity(650, 800, 450);
        break;
    case 2:
        setQuantity(800, 900, 700);
        break;
    case 3:
        setQuantity(800, 900, 700);
        break;
    case 4:
        setQuantity(800, 900, 700);
        break;
    case 5:
        setQuantity(900, 1000, 850);
        break;
    case 6:
        setQuantity(900, 1000, 850);
        break;
    case 7:
        setQuantity(900, 1000, 850);
        break;
    case 8:
        setQuantity(900, 1000, 850);
        break;
    case 9:
        setQuantity(800, 850, 750);
        break;
    case 10:
        setQuantity(800, 850, 750);
        break;
    case 11:
        setQuantity(800, 850, 750);
        break;
    case 12:
        setQuantity(800, 850, 750);
        break;
    default:
        setQuantity(500, 1000, 0);
        break;
    }
}

void setQuantity(int q, int mx, int mn)
{
    quantite = q;
    maxQ = mx;
    minQ = mn;
}

void verifyQuantity()
{
    if (quantite > maxQ)
    {
        quantite = maxQ;
        cout << "Surcharge pondérale ?" << endl; // ttf please
    } else if (quantite < minQ)
    {
        quantite = minQ;
        cout << "Il va mourir de faim..." << endl; // ttf please
    }
}