#ifndef BOARD_H
#define BOARD_H

#include <vector>
#include <memory>
#include "Character.h"
#include "Auxiliaries.h"
#include "Exceptions.h"

namespace mtm
{
    class Board
    {
        public:
            Board() = delete;
            Board(const Board& other) = delete;

            Board(int column_count, int row_count);

            void ensureAvailablePoint(const GridPoint& point, const std::vector<std::shared_ptr<Character>> &characters) const;
            void ensurePointOnBoard(const GridPoint& point) const;
            Character& Board::getCharacterInPoint(const GridPoint& point, std::vector<std::shared_ptr<Character>> &characters) const;
            
            //The following two methods will throw exceptions to signal illegal actions.
            /*void attack(Character& attacker, const GridPoint& target) const;
            void move(Character& mover, const GridPoint& target) const;
            void addCharacter(Character& character, const GridPoint& point) const;*/
        private:
            int column_count;
            int row_count;
            static bool isLegalPoint(const GridPoint& point);
            bool isOnBoard(const GridPoint& point) const;
            bool isOccupied(const GridPoint& point, const std::vector<std::shared_ptr<Character>> &characters) const;
            std::shared_ptr<Character> getCharacterIfExists(const GridPoint& point, const std::vector<std::shared_ptr<Character>> &characters) const;
    };
}

#endif //BOARD_H
