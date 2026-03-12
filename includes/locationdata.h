#pragma once
#include "common.h"
#include "locationtype.h"
class LocationData
{
private:
    LocationType _locationType;
    std::optional<size_t> _characterIndex;
    std::optional<size_t> _inventoryIndex;
    LocationData();
public:
    LocationData(LocationType locationType);
    void SetLocationType(LocationType locationType);
    LocationType GetLocationType() const;
    std::optional<size_t> GetCharacterIndex() const;
    void SetCharacterIndex(std::optional<size_t> characterIndex);
    std::optional<size_t> GetInventoryIndex() const;
    void SetInventoryIndex(std::optional<size_t> inventoryIndex);
};