#include "./hpp/Feeder.hpp"

float Feeder::GetTakingQuantity(){ return taking_quantity; }

float Feeder::GetTakingTime(){ return taking_time; }

float Feeder::MilkReduction(){
    reduced_quantity = quantity_max - taking_quantity;

    return reduced_quantity;
}

void Feeder::Reminder(){
    //Renderer le temps sur le SDL_Rect
}

void Feeder::ChangeAlertPeriod(){
    //Change alert period 
    while (1)
    {
        while (SDL_PollEvent(&userInput))
        {
            switch (userInput.type)
            {
            case 'A':
                /* code */
                break;
            
            default:
                break;
            }
        }
        
    }
    
}





Feeder::Feeder(){}
Feeder::~Feeder(){}