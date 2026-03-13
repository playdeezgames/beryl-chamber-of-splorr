#pragma once
#include "item.h"
#include "framebuffercellcolor.h"
class ItemOutfitter
{
private:
    ItemOutfitter();
    unsigned char _frameCharacter;
    FrameBufferCellColor _frameForeground;
public:
    virtual void Initialize(Item item) const = 0;
    virtual ~ItemOutfitter() = default;
    ItemOutfitter(
        unsigned char frameCharacter, 
        FrameBufferCellColor frameForeground)
        : _frameCharacter(frameCharacter)
        , _frameForeground(frameForeground)
        {
        }
    unsigned char GetFrameCharacter() const{return _frameCharacter;}
    FrameBufferCellColor GetFrameForeground() const{return _frameForeground;}
};