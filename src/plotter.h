#pragma once
#include "common.h"
class Plotter
{
private:
    int _offsetX;
    int _offsetY;
    int _cellWidth;
    int _cellHeight;
    Plotter();
public:
    Plotter(
        int offsetX, 
        int offsetY, 
        int cellWidth, 
        int cellHeight):
        _offsetX(offsetX),
        _offsetY(offsetY),
        _cellWidth(cellWidth),
        _cellHeight(cellHeight)
    {
    }
    int PlotX(int column) const
    {
        return _offsetX + column * _cellWidth;
    }
    int PlotY(int row) const
    {
        return _offsetY + row * _cellHeight;
    }
};
