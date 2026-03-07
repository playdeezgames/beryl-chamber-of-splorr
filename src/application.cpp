#include "application.h"
#include <SDL2/SDL_image.h>
static bool quit = false;//TODO: make this based on a optional gamestate variable instead
Application::~Application()
{
   	IMG_Quit();
	SDL_Quit();
}
Application::Application(
    const std::string& title, 
    int screenWidth, 
    int screenHeight, 
    int viewWidth, 
    int viewHeight,
    const std::string& textureFilename)
    : window(nullptr, SDL_DestroyWindow)
    , renderer(nullptr, SDL_DestroyRenderer)
    , texture(nullptr, SDL_DestroyTexture)
{
    SDL_Init(SDL_INIT_VIDEO);
    IMG_Init(IMG_INIT_PNG);
    window.reset(SDL_CreateWindow(
            title.c_str(),
            SDL_WINDOWPOS_CENTERED,
            SDL_WINDOWPOS_CENTERED,
            screenWidth, 
            screenHeight,
            SDL_WINDOW_SHOWN));
    renderer.reset(SDL_CreateRenderer(window.get(), -1, 0));
    texture.reset(IMG_LoadTexture(renderer.get(), textureFilename.c_str()));
    SDL_RenderSetLogicalSize(renderer.get(), viewWidth, viewHeight);
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
    SDL_RenderClear(renderer.get());
    SDL_RenderPresent(renderer.get());
}
void Application::Run()
{
    while(!quit)
    {
        Loop();
    }
}
