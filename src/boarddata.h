#pragma once
#include "common.h"
#include "locationdata.h"
class BoardData
{
private:
    size_t _columns;
    size_t _rows;
    std::vector<LocationData> _locations;
    BoardData();
public:
    BoardData(size_t columns, size_t rows, LocationType locationType);
    LocationData& GetLocationData(size_t locationIndex);
    const LocationData& GetLocationData(size_t locationIndex) const;
    size_t GetColumns() const;
    size_t GetRows() const;
};