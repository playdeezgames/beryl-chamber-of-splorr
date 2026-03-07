#pragma once
#include "common.h"
#include <SDL2/SDL.h>
#include "framebuffer.h"
class Application
{
private:
    std::unique_ptr<SDL_Window, void(*)(SDL_Window*)> _window;
    std::unique_ptr<SDL_Renderer, void(*)(SDL_Renderer*)> _renderer;
    std::unique_ptr<SDL_Texture, void(*)(SDL_Texture*)> _texture;
    FrameBuffer _frameBuffer;
    Application();
public:
    Application(
        const std::string& title, 
        int screenWidth, 
        int screenHeight, 
        int viewWidth, 
        int viewHeight,
        size_t viewColumns,
        size_t viewRows,
        const std::string& textureFilename);
    ~Application();
    void Loop();
    void Run();
};