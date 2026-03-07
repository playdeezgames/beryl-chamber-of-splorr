#pragma once
#include "common.h"
#include <SDL2/SDL.h>
#include "framebuffer.h"
#include "tile.h"
class Application
{
private:
    std::unique_ptr<SDL_Window, void(*)(SDL_Window*)> _window;
    std::unique_ptr<SDL_Renderer, void(*)(SDL_Renderer*)> _renderer;
    std::unique_ptr<SDL_Texture, void(*)(SDL_Texture*)> _texture;
    FrameBuffer _frameBuffer;
    std::vector<Tile> _tiles;
    int _viewCellWidth;
    int _viewCellHeight;
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
        int viewCellWidth,
        int viewCellHeight,
        const std::string& textureFilename);
    ~Application();
    void Loop();
    void Run();
};