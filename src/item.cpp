#include "item.h"
#include "items.h"
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

