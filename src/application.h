#pragma once
#include "common.h"
class Application
{
private:
    static void CleanUp();
public:
    static void Initialize(
        const std::string& title, 
        int screenWidth, 
        int screenHeight, 
        int viewWidth, 
        int viewHeight,
        const std::string& textureFilename);
    static void Loop();
    static void Run();
};