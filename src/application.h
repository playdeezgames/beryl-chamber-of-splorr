#pragma once
#include "common.h"
#include <SDL2/SDL.h>
class Application
{
private:
    std::unique_ptr<SDL_Window, void(*)(SDL_Window*)> window;
    std::unique_ptr<SDL_Renderer, void(*)(SDL_Renderer*)> renderer;
    std::unique_ptr<SDL_Texture, void(*)(SDL_Texture*)> texture;
    Application();
public:
    Application(
        const std::string& title, 
        int screenWidth, 
        int screenHeight, 
        int viewWidth, 
        int viewHeight,
        const std::string& textureFilename);
    ~Application();
    void Loop();
    void Run();
};