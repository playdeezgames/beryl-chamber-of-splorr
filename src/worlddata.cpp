#include "worlddata.h"
void WorldData::Clear()
{
    _boards.clear();
    _recycledBoards.clear();
    _characters.clear();
    _recycledCharacters.clear();
    _avatar = std::nullopt;
}
size_t WorldData::CreateBoard(
    size_t columns, 
    size_t rows, 
    LocationType locationType)
{
    size_t result;
    if(_recycledBoards.empty())
    {
        result = _boards.size();
        _boards.emplace_back(columns, rows, locationType);
    }
    else
    {
        result = *_recycledBoards.begin();
        _recycledBoards.erase(result);
        _boards[result] = BoardData(columns, rows, locationType);
    }
    return result;
}
BoardData& WorldData::GetBoardData(size_t boardIndex)
{
    return _boards[boardIndex];
}
const BoardData& WorldData::GetBoardData(size_t boardIndex) const
{
    return _boards[boardIndex];
}
size_t WorldData::CreateCharacter(CharacterType characterType, size_t boardIndex, size_t locationIndex)
{
    size_t result;
    if(_recycledCharacters.empty())
    {
        result = _characters.size();
        _characters.emplace_back(characterType, boardIndex, locationIndex);
    }
    else
    {
        result = *_recycledCharacters.begin();
        _recycledCharacters.erase(result);
        _characters[result] = CharacterData(characterType, boardIndex, locationIndex);
    }
    return result;
}
CharacterData& WorldData::GetCharacterData(size_t characterIndex)
{
    return _characters[characterIndex];
}
const CharacterData& WorldData::GetCharacterData(size_t characterIndex) const
{
    return _characters[characterIndex];
}
void WorldData::SetAvatar(std::optional<size_t> avatar)
{
    _avatar = avatar;
}
std::optional<size_t> WorldData::GetAvatar() const
{
    return _avatar;
}
size_t WorldData::CreateInventory()
{
    size_t result;
    if(_recycledInventories.empty())
    {
        result = _inventories.size();
        _inventories.emplace_back();
    }
    else
    {
        result = *_recycledInventories.begin();
        _recycledInventories.erase(result);
        _inventories[result] = InventoryData();
    }
    return result;
}
size_t WorldData::CreateItem(ItemType itemType, size_t inventoryIndex)
{
    size_t result;
    if(_recycledItems.empty())
    {
        result = _items.size();
        _items.emplace_back(itemType, inventoryIndex);
    }
    else
    {
        result = *_recycledItems.begin();
        _recycledItems.erase(result);
        _items[result] = ItemData(itemType, inventoryIndex);
    }
    return result;
}
ItemData& WorldData::GetItemData(size_t itemIndex)
{
    return _items[itemIndex];
}
const ItemData& WorldData::GetItemData(size_t itemIndex) const
{
    return _items[itemIndex];
}
