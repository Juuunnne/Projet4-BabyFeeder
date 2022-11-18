# Projet4-BabdyFeeder

Use __Make__ to compile and launch the program

```
Main.cpp -> call the app

App.cpp : 
void AppLoop() is the game loop and call all the class and fonction. 
void UpdateDisplay(SDL_rendere *renderer) draw the graphic part and update it.
void OnClick() call the fonction need with a mousse click.
void setMapButton(int x, int y, int w, int h) save all the x/y/width/height of everyclickable button in a 2D array.
int onHover() follow the mousse mouvement and return the ID of the button if the mousse is on one. 

Interface.cpp : 
void Interface::setBackground(SDL_Renderer *renderer) load the backround color and draw it.

button.cpp : 
void Button::setButton(int px, int py, int w, int h, int r, int g, int b, int a) create an object for the creation of a button.
void Button::drawButton(SDL_Renderer* renderer) draw the button with SDL2

feederButton.cpp : 
void feederButton::setFeeder (int px, int py, int w, int h, int r, int g, int b, int a) is use to call Button::setButton and create a button for the feeder part.
void feederButton::drawFeederButtons(SDL_Renderer *renderer) is use to call Button::drawButton and draw the button on SDL2.
void feederButton::verifyQuantity() is here verifi if the quantity in the feeder 
void feederButton::changeQuantity(bool increase, int amount) is use after a click on the minus or plus button for the feeder.
tuple<int, int, int, int> feederButton::getButtons() get the position, widht and height of thhe button

option.cpp :
void option::setOption (int px, int py, int w, int h, int r, int g, int b, int a) is use to call Button::setButton and create a button for the option part.
void option::drawOption(SDL_Renderer* renderer) is use to call Button::drawButton and draw the button on SDL2.
int option::changeAge() get the position, widht and height of thhe button
timer.cpp :
timer::timer(int time) new constructor to set all the timer
void timer::updateTime(int age, int time) update the time in fonction of the age of the baby
void timer::resetTimer(int time) set the vatriable to make a clock.
void timer::changeDuration(int age) define the duration between  each feeding time
void timer::setTimeBt (int px, int py, int w, int h, int r, int g, int b, int a) set the but to reset the timer
void timer::drawTimerBt(SDL_Renderer *renderer) drwn the button for the timer
tuple<int, int, int, int> timer::getButtons() get the position, widht and height of thhe button

windows.cpp :bool Window::InitSDL() init the SDL part and return if everything was good. 
```       
