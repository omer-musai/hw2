#include "Game.h"

namespace mtm
{
    Game::Game(int row, int col) :
        characters(), board(row, col)
    {}

    void Game::addCharacter(const GridPoint& coordinates, std::shared_ptr<Character> character)
    {
        board.ensureAvailablePoint(coordinates, characters);
        character->setPosition(coordinates);
        characters.push_back(character);
    }

    void Game::move(const GridPoint& src_coordinates, const GridPoint& dst_coordinates)
    {
        board.ensureAvailablePoint(dst_coordinates, this->characters);
        Character &character = board.getCharacterInPoint(src_coordinates, this->characters);
        character.setPosition(dst_coordinates);
    }


    void Game::attack(const GridPoint& src_coordinates, const GridPoint& dst_coordinates)
    {
        board.ensurePointOnBoard(src_coordinates);
        Character &character = board.getCharacterInPoint(src_coordinates, this->characters);

        
        character.attack(dst_coordinates, board.getCharacterInPoint(dst_coordinates, this->characters));
       
       
        for (std::shared_ptr<Character> characterPtr : characters)
        {
            character.dealDamage(*characterPtr, dst_coordinates);
        }
    }

    void Game::reload(const GridPoint& coordinates)
    {
        Character &character = board.getCharacterInPoint(coordinates, characters);
        character.reload();
    }

    bool Game::isOver(Team* winningTeam=NULL) const
    {
        
    }
}