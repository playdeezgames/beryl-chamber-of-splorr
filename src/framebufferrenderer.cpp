#include "framebufferrenderer.h"
void FrameBufferRenderer::Render(SDL_Renderer* renderer)
{
    for(auto row: std::views::iota(size_t{0}, _frameBuffer.GetRows()))
    {
        for(auto column: std::views::iota(size_t{0}, _frameBuffer.GetColumns()))
        {
            const auto& cell = _frameBuffer.GetCell(column, row);
            _tileSet.GetTile(219).Render(renderer,_plotter.PlotX(column), _plotter.PlotY(row), _palette.GetColor(cell.GetBackground()));
            _tileSet.GetTile(cell.GetCharacter()).Render(renderer,_plotter.PlotX(column), _plotter.PlotY(row), _palette.GetColor(cell.GetForeground()));
        }
    }
}
