#include "./hpp/timer.hpp"

timer::timer()
{
    
}

timer::timer(int time) {
    temps_repere = time;
    temps = time;
    duration = 10800000;
}

timer::~timer()
{
}

void timer::updateTime(int age, int time)
{
    if (age <= 1) {
        changeDuration(1);
    } else if (1 < age <= 2) {
        changeDuration(2);
    } else {
        changeDuration(3);
    }

    temps_repere = time;
    if ((temps_repere-temps) > duration)
    {
        cout << "c'est l'heure de manger !" << endl;
    }
}

void timer::resetTimer(int time) {
    temps_repere = time;
    temps = time;
}

void timer::changeDuration(int age)
{
    switch (age)
    {
    case 1:
        duration = 10800000;
        break;
    case 2:
        duration = 7200000;
        break;
    case 3:
        duration = 14400000;
        break;
    }
}

void timer::setTimeBt (int px, int py, int w, int h, int r, int g, int b, int a) {
    this->rT.setButton(px, py, w, h, r, g, b, a);
}

void timer::drawTimerBt(SDL_Renderer *renderer)
{
    this->rT.drawButton(renderer);
}

tuple<int, int, int, int> timer::getButtons() {
    return make_tuple (rT.posx, rT.posy, rT.width, rT.height);
}