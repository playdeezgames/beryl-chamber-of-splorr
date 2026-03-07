#pragma once
#include "common.h"
class Application
{
private:
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