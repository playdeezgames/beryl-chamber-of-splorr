#include "item.h"
#include "items.h"
#include "inventory.h"
void Item::Initialize()
{
    Items::GetOutfitter(GetItemType()).Initialize(*this);
}
ItemType Item::GetItemType() const
{
    return GetItemData().GetItemType();
}
ItemData& Item::GetItemData()
{
    return _worldData.GetItemData(_index);
}
const ItemData& Item::GetItemData() const
{
    return _worldData.GetItemData(_index);
}
unsigned char Item::GetFrameCharacter() const
{
    return Items::GetOutfitter(GetItemType()).GetFrameCharacter();
}
FrameBufferCellColor Item::GetFrameForeground() const
{
    return Items::GetOutfitter(GetItemType()).GetFrameForeground();
}
void Item::SetInventory(Inventory inventory)
{
    GetItemData().SetInventoryIndex(inventory.GetIndex());
}
Inventory Item::GetInventory() const
{
    return Inventory(_worldData, GetItemData().GetInventoryIndex());
}

