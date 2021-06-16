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
            Board(const Board& other) = default;

            Board(int row_count, int column_count);
            const int column_count;
            const int row_count;

        std::string generateBoardString(const std::vector<std::shared_ptr<Character>> characters) const;

            void ensureAvailablePoint(const GridPoint& point, const std::vector<std::shared_ptr<Character>> &characters) const;
            void ensurePointOnBoard(const GridPoint& point) const;
            Character& getCharacterInPoint(const GridPoint& point, std::vector<std::shared_ptr<Character>> &characters) const;
            std::shared_ptr<Character> getCharacterIfExists(const GridPoint& point, const std::vector<std::shared_ptr<Character>> &characters) const;
            
            //The following two methods will throw exceptions to signal illegal actions.
            /*void attack(Character& attacker, const GridPoint& target) const;
            void move(Character& mover, const GridPoint& target) const;
            void addCharacter(Character& character, const GridPoint& point) const;*/
        private:
            static const char BOARD_STRING_NO_CHARACTER = ' ';
            static bool isLegalPoint(const GridPoint& point);
            bool isOnBoard(const GridPoint& point) const;
            bool isOccupied(const GridPoint& point, const std::vector<std::shared_ptr<Character>> &characters) const;
    };
}

#endif //BOARD_H
