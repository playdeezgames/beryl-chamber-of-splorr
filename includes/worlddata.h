#pragma once
#include "common.h"
#include "boarddata.h"
#include "characterdata.h"
#include "itemdata.h"
#include "inventorydata.h"
class WorldData
{
private:
    std::vector<BoardData> _boards;
    std::set<size_t> _recycledBoards;
    std::vector<CharacterData> _characters;
    std::set<size_t> _recycledCharacters;
    std::optional<size_t> _avatar;
    std::vector<ItemData> _items;
    std::set<size_t> _recycledItems;
    std::vector<InventoryData> _inventories;
    std::set<size_t> _recycledInventories;
public:
    void Clear();
    size_t CreateBoard(size_t columns, size_t rows, LocationType locationType);
    BoardData& GetBoardData(size_t boardIndex);
    const BoardData& GetBoardData(size_t boardIndex) const;
    size_t CreateCharacter(CharacterType characterType, size_t boardIndex, size_t locationIndex);
    CharacterData& GetCharacterData(size_t characterIndex);
    const CharacterData& GetCharacterData(size_t characterIndex) const;
    void SetAvatar(std::optional<size_t> avatar);
    std::optional<size_t> GetAvatar() const;
    size_t CreateInventory();
    size_t CreateItem(ItemType itemType, size_t inventoryIndex);
};