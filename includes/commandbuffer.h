#pragma once
#include "common.h"
#include "commandtype.h"
class CommandBuffer
{
private:
    std::queue<CommandType> _queue;
public:
    void Write(CommandType command);
    std::optional<CommandType> Read();
};