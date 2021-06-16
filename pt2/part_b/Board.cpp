#include "Board.h"

namespace mtm
{
    Board::Board(int row_count, int column_count)
        : row_count(row_count), column_count(column_count)
    {
        if(row_count < 0 || column_count < 0)
        {
            throw IllegalArgument();
        }
    }

    void Board::ensurePointOnBoard(const GridPoint& point) const
    {
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

    bool Board::isOnBoard(const GridPoint& point) const
    {
        return (point.col >= 0 && point.row >= 0
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

    std::string Board::generateBoardString(const std::vector<std::shared_ptr<Character>>& characters) const
    {
        std::string boardString;

        for (int row = 0; row < row_count; ++row)
        {
            for (int column = 0; column < column_count; ++column)
            {
                std::shared_ptr<Character> character
                    = getCharacterIfExists(GridPoint(row, column), characters);
                if (character == nullptr)
                {
                    boardString += BOARD_STRING_NO_CHARACTER;
                }
                else
                {
                    boardString += character->getStringSymbol();
                }
            }
        }

        return boardString;
    }
}
