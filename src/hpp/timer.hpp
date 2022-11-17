#pragma once
#include <time.h>
// #include <SDL2/SDL_ttf.h>
#include <iostream>
#include <tuple>
#include "./button.hpp"

using namespace std;

class timer
{
public:
    Button rT;
    clock_t temps_repere, temps;
    long int duration;

    timer();
    timer(int time);
    ~timer();
    void updateTime(int age, int time);
    void resetTimer(int time);
    void changeDuration(int age);
    void setTimeBt (int px, int py, int w, int h, int r, int g, int b, int a);
    void drawTimerBt(SDL_Renderer *renderer);
    tuple<int, int, int, int> getButtons();
private:

};