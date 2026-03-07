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
    size_t viewColumns,
    size_t viewRows,
    const std::string& textureFilename)
    : _window(nullptr, SDL_DestroyWindow)
    , _renderer(nullptr, SDL_DestroyRenderer)
    , _texture(nullptr, SDL_DestroyTexture)
    , _frameBuffer(viewColumns, viewRows)
{
    SDL_Init(SDL_INIT_VIDEO);
    IMG_Init(IMG_INIT_PNG);
    _window.reset(SDL_CreateWindow(
            title.c_str(),
            SDL_WINDOWPOS_CENTERED,
            SDL_WINDOWPOS_CENTERED,
            screenWidth, 
            screenHeight,
            SDL_WINDOW_SHOWN));
    _renderer.reset(SDL_CreateRenderer(_window.get(), -1, 0));
    _texture.reset(IMG_LoadTexture(_renderer.get(), textureFilename.c_str()));
    SDL_RenderSetLogicalSize(_renderer.get(), viewWidth, viewHeight);
    _frameBuffer.WriteText(0,0,"Hello, world!",FrameBufferCellColor::LIGHT_GRAY, FrameBufferCellColor::DARK_GRAY);
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
    SDL_RenderClear(_renderer.get());
    //TODO: render frame buffer
    SDL_RenderPresent(_renderer.get());
}
void Application::Run()
{
    while(!quit)
    {
        Loop();
    }
}
