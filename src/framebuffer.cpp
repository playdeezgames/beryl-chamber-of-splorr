#include "framebuffer.h"
FrameBuffer::FrameBuffer(size_t columns, size_t rows)
    : _cells()
    , _columns(columns)
    , _rows(rows)
{
    //TODO: use a back inserter?
    while(_cells.size() <_columns * _rows)
    {
        _cells.emplace_back();
    }
}
size_t FrameBuffer::GetColumns() const
{
    return _columns;
}
size_t FrameBuffer::GetRows() const
{
    return _rows;
}
FrameBufferCell& FrameBuffer::GetCell(size_t column, size_t row)
{
    return _cells[column + row * _columns];
}
const FrameBufferCell& FrameBuffer::GetCell(size_t column, size_t row) const
{
    return _cells[column + row * _columns];
}
void FrameBuffer::SetCell(
    size_t column, 
    size_t row, 
    std::optional<unsigned char> character, 
    std::optional<FrameBufferCellColor> foreground, 
    std::optional<FrameBufferCellColor> background)
{
    auto& cell = GetCell(column, row);
    cell.SetCharacter(character.value_or(cell.GetCharacter()));
    cell.SetForeground(foreground.value_or(cell.GetForeground()));
    cell.SetBackground(background.value_or(cell.GetBackground()));
}
void FrameBuffer::Fill(
    size_t column, 
    size_t row, 
    size_t columns, 
    size_t rows, 
    std::optional<unsigned char> character, 
    std::optional<FrameBufferCellColor> foreground, 
    std::optional<FrameBufferCellColor> background)
{
    for(size_t c : std::views::iota(column, column + columns))
    {
        for(size_t r : std::views::iota(row, row + rows))
        {
            SetCell(c, r, character, foreground, background);
        }
    }    
}
void FrameBuffer::WriteText(
    size_t column, 
    size_t row, 
    const std::string& text, 
    std::optional<FrameBufferCellColor> foreground, 
    std::optional<FrameBufferCellColor> background)
{
    for(auto character: text)
    {
        SetCell(
            column++,
            row,
            character,
            foreground,
            background);
    }
}
