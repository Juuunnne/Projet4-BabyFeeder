#include "./hpp/windows.hpp"

Window::Window() {
    this->window = NULL;
    this->renderer = NULL;
}

Window::~Window() {
    SDL_DestroyWindow(this->window);
    SDL_DestroyRenderer(this->renderer);
    SDL_Quit();
}

SDL_Renderer* Window::getRenderer() {
    return this->renderer;
}

bool Window::InitSDL()
{
    bool success = true;
    const char *title = "Baby Feeder";

    // Init SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        printf("Failed to init SDL, Error : \n", SDL_GetError());
        success = false;
    }

    // Create window
    this->window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, this->SCREEN_WIDTH, this->SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    if (this->window == NULL)
    {
        printf("Failed to create a window SDL, Error : \n", SDL_GetError());
    }

    // Create renderer
    this->renderer = SDL_CreateRenderer(this->window, -1, SDL_RENDERER_ACCELERATED);
    if (this->renderer == NULL)
    {
        printf("Failed to create renderer, Error : \n", SDL_GetError());
    }

    return success;
}
