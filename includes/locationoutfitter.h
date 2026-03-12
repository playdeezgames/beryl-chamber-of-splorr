#pragma once
#include "location.h"
#include "framebuffercellcolor.h"
class LocationOutfitter
{
private:
    unsigned char _frameCharacter;
    FrameBufferCellColor _frameForeground;
    FrameBufferCellColor _frameBackground;
    LocationOutfitter();
public:
    LocationOutfitter(
        unsigned char frameCharacter, 
        FrameBufferCellColor frameForeground, 
        FrameBufferCellColor frameBackground)
        : _frameCharacter(frameCharacter)
        , _frameForeground(frameForeground)
        , _frameBackground(frameBackground)
        {
        }
    virtual ~LocationOutfitter() = default;
    virtual void Initialize(Location location) const = 0;
    unsigned char GetFrameCharacter() const{return _frameCharacter;}
    FrameBufferCellColor GetFrameForeground() const{return _frameForeground;}
    FrameBufferCellColor GetFrameBackground() const{return _frameBackground;}
};