#include "inventory.h"
#include "item.h"
unsigned char Inventory::GetFrameCharacter() const
{
    auto item = Item(_worldData, *GetInventoryData().GetItemIndices().begin());
    return item.GetFrameCharacter();
}
FrameBufferCellColor Inventory::GetFrameForeground() const
{
    auto item = Item(_worldData, *GetInventoryData().GetItemIndices().begin());
    return item.GetFrameForeground();
}
void Inventory::AddItem(Item item)
{
    GetInventoryData().AddItemIndex(item.GetIndex());
    item.SetInventory(*this);
}
void Inventory::RemoveItem(Item item)
{
    GetInventoryData().RemoveItemIndex(item.GetIndex());
}
bool Inventory::HasItems() const
{
    return GetInventoryData().HasItemIndices();
}
InventoryData& Inventory::GetInventoryData()
{
    return _worldData.GetInventoryData(_index);
}
const InventoryData& Inventory::GetInventoryData() const
{
    return _worldData.GetInventoryData(_index);
}
std::vector<Item> Inventory::GetItems() const
{
    auto itemIndices = GetInventoryData().GetItemIndices();
    std::vector<Item> result;
    std::transform(
        itemIndices.begin(),
        itemIndices.end(),
        std::back_inserter(result),
        [this](size_t index){return Item(_worldData, index);});
    return result;
}

