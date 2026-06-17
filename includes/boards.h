#pragma once
#include "common.h"
#include "boardtype.h"
#include "boardoutfitter.h"
class Boards
{
private:
    static std::map<BoardType, std::unique_ptr<BoardOutfitter>> _boardOutfitters;
public:
    static void Initialize();
    static const BoardOutfitter& GetOutfitter(BoardType boardType);
};