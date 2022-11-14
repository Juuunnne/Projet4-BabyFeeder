#pragma once
#include <iostream>
#include <SDL2/SDL.h>
#include <ctime>

class Feeder
{
public:
    Feeder();
    ~Feeder();
    
    float GetTakingQuantity();
    float GetTakingTime();
    float MilkReduction();
    void Reminder();
    void ChangeAlertPeriod();
    

private:
    SDL_Event userInput;
    float taking_time;
    float taking_quantity;
    float alert_period;
    float current_time;

    int quantity_max;
    int quantity_min;

    float reduced_quantity;
};


