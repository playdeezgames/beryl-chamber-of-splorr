#include "locations.h"
#include "bluewalllocationoutfitter.h"
#include "floorlocationoutfitter.h"
std::map<LocationType, std::unique_ptr<LocationOutfitter>> Locations::_outfitters;
void Locations::Initialize()
{
    if(_outfitters.empty())
    {
        _outfitters.emplace(LocationType::BLUE_WALL, std::make_unique<BlueWallLocationOutfitter>());
        _outfitters.emplace(LocationType::FLOOR, std::make_unique<FloorLocationOutfitter>());
    }
}
const LocationOutfitter& Locations::GetOutfitter(LocationType locationType)
{
    return *_outfitters.find(locationType)->second;
}
