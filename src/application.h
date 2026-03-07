#pragma once
#include "common.h"
class Application
{
private:
    void CleanUp();
public:
    void Initialize(
        const std::string& title, 
        int screenWidth, 
        int screenHeight, 
        int viewWidth, 
        int viewHeight,
        const std::string& textureFilename);
    void Loop();
    void Run();
};