#include "Board.h"

namespace mtm
{
    Board::Board(int column_count, int row_count)
        : column_count(column_count), row_count(row_count)
    {}

    void Board::ensurePointOnBoard(const GridPoint& point) const
    {
        if (!isLegalPoint(point))
        {
            throw IllegalArgument();
        }
        if (!isOnBoard(point))
        {
            throw IllegalCell();
        }
    }

    void Board::ensureAvailablePoint(const GridPoint& point, const std::vector<std::shared_ptr<Character>> &characters) const
    {
        ensurePointOnBoard(point);

        if (isOccupied(point, characters))
        {
            throw CellOccupied();
        }
    }

    bool Board::isLegalPoint(const GridPoint& point)
    {
        return point.col >= 0 && point.row >= 0;
    }

    bool Board::isOnBoard(const GridPoint& point) const
    {
        return (isLegalPoint(point)
            && point.col < column_count && point.row < row_count);
    }

    std::shared_ptr<Character> Board::getCharacterIfExists(const GridPoint& point, const std::vector<std::shared_ptr<Character>> &characters) const
    {
        if (!isOnBoard(point))
        {
            return nullptr;
        }
        
        for (const std::shared_ptr<Character>& characterPtr : characters)
        {
            if (characterPtr->getPosition() == point)
            {
                return characterPtr;
            }
        }

        return nullptr;
    }

    Character& Board::getCharacterInPoint(const GridPoint& point, std::vector<std::shared_ptr<Character>> &characters) const
    {
        std::shared_ptr<Character> characterPtr = getCharacterIfExists(point, characters);
        if (characterPtr == nullptr)
        {
            throw CellEmpty();
        }

        return *characterPtr;
    }

    bool Board::isOccupied(const GridPoint& point, const std::vector<std::shared_ptr<Character>> &characters) const
    {
        return getCharacterIfExists(point, characters) != nullptr;
    }
}
