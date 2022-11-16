#pragma once
#include <functional>
#include <SDL2/SDL.h>

using namespace std;

class Button
{
public:
    int posx;
    int posy;
    int width;
    int height;
    int red;
    int green;
    int blue;
    int alpha;

    Button();
    ~Button();

    void setButton(int px, int py, int w, int h, int r, int g, int b, int a);
    void drawButton(SDL_Renderer* renderer);

private:
};