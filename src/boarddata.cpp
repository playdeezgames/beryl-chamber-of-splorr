#include "boarddata.h"
BoardData::BoardData(
    size_t columns, 
    size_t rows,
    LocationType locationType)
    : _columns(columns)
    , _rows(rows)
    , _locations()
{
    while(_locations.size() < _columns * _rows)
    {
        _locations.emplace_back(locationType);
    }
}
LocationData& BoardData::GetLocationData(size_t locationIndex)
{
    return _locations[locationIndex];
}
const LocationData& BoardData::GetLocationData(size_t locationIndex) const
{
    return _locations[locationIndex];
}
size_t BoardData::GetColumns() const
{
    return _columns;
}
size_t BoardData::GetRows() const
{
    return _rows;
}
