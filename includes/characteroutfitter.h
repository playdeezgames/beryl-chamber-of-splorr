#pragma once
#include "character.h"
#include "framebuffercellcolor.h"
class CharacterOutfitter
{
private:
    CharacterOutfitter();
    unsigned char _frameCharacter;
    FrameBufferCellColor _frameForeground;
public:
    virtual void Initialize(Character character) const = 0;
    virtual void DoTurn(Character character) const = 0;
    virtual ~CharacterOutfitter() = default;
    CharacterOutfitter(
        unsigned char frameCharacter, 
        FrameBufferCellColor frameForeground)
        : _frameCharacter(frameCharacter)
        , _frameForeground(frameForeground)
        {
        }
    unsigned char GetFrameCharacter() const{return _frameCharacter;}
    FrameBufferCellColor GetFrameForeground() const{return _frameForeground;}
};