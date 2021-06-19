#ifndef BOARD_H
#define BOARD_H

#include <vector>
#include <memory>
#include "Character.h"
#include "Auxiliaries.h"
#include "Exceptions.h"

namespace mtm
{
	//This class handles general board-related utilities.
    class Board
    {
          private:
            int row_count;
            int column_count;
            static const char BOARD_STRING_NO_CHARACTER = ' ';
			//True if point is on board, else false.
            bool isOnBoard(const GridPoint& point) const;
			//True if point has a character on it, else false. If point isn't on board, false.
            bool isOccupied(const GridPoint& point, const std::vector<std::shared_ptr<Character>> &characters) const;
        public:
            Board() = delete;
            Board(const Board& other) = default;
			
            int getRowCount() const;
            int getColumnCount() const;

            Board(int row_count, int column_count);
			
			//This generates a string in the format required by printGameBoard.
			std::string generateBoardString(const std::vector<std::shared_ptr<Character>>& characters) const;
			
			//Throws an appropriate exception if point is occupied (or not on board): intended to be used with Game::move.
            void ensureAvailablePoint(const GridPoint& point, const std::vector<std::shared_ptr<Character>> &characters) const;
			//Throws an appropriate exception if point isn't on board.
            void ensurePointOnBoard(const GridPoint& point) const;
			
			//Returns a pointer to the character if they exist, else nullptr.
            std::shared_ptr<Character> getCharacterIfExists(const GridPoint& point, const std::vector<std::shared_ptr<Character>> &characters) const;
			
			//Returns a reference to the character if they exist, else an appropriate exception.
            Character& getCharacterInPoint(const GridPoint& point, std::vector<std::shared_ptr<Character>> &characters) const;
      
    };
}

#endif //BOARD_H
