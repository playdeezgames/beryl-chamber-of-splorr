#include "application.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
static SDL_Window* window = nullptr;//TODO: make unique_ptr
static SDL_Renderer* renderer = nullptr;//TODO: make unique_ptr
static SDL_Texture* texture = nullptr;//TODO: make unique_ptr
static bool quit = false;//TODO: make this based on a optional gamestate variable instead
void Application::CleanUp()
{
    if(texture)
    {
        SDL_DestroyTexture(texture);
        texture = nullptr;
    }
    if(renderer)
    {
        SDL_DestroyRenderer(renderer);
        renderer = nullptr;
    }
    if(window)
    {
        SDL_DestroyWindow(window);
        window = nullptr;
    }
   	IMG_Quit();
	SDL_Quit();
}
void Application::Initialize(
    const std::string& title, 
    int screenWidth, 
    int screenHeight, 
    int viewWidth, 
    int viewHeight,
    const std::string& textureFilename)
{
    SDL_Init(SDL_INIT_VIDEO);
    IMG_Init(IMG_INIT_PNG);
    window = SDL_CreateWindow(
            title.c_str(),
            SDL_WINDOWPOS_CENTERED,
            SDL_WINDOWPOS_CENTERED,
            screenWidth, 
            screenHeight,
            SDL_WINDOW_SHOWN);
    renderer = SDL_CreateRenderer(window, -1, 0);
    texture = IMG_LoadTexture(renderer, textureFilename.c_str());
    SDL_RenderSetLogicalSize(renderer, viewWidth, viewHeight);
}
void Application::Loop()
{
	SDL_Event event;
	while (SDL_PollEvent(&event)) 
	{
		if(event.type == SDL_QUIT)
		{
			quit = true;
		}
    }
    SDL_RenderClear(renderer);
    SDL_RenderPresent(renderer);
}
void Application::Run()
{
    while(!quit)
    {
        Loop();
    }
    CleanUp();
}
