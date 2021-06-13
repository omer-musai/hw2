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
        character.move(dst_coordinates);
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
        
        std::remove_if(characters.begin(), characters.end(), isDead);
    }

    void Game::reload(const GridPoint& coordinates)
    {
        Character &character = board.getCharacterInPoint(coordinates, characters);
        character.reload();
    }

    bool Game::isOver(Team* winningTeam=NULL) const
    {
        bool powerliftersRemain = false, crossfittersRemain = false;
        for (const std::shared_ptr<Character>& character : characters)
        {
            if (character->getTeam() == Team::POWERLIFTERS)
            {
                powerliftersRemain = true;
            }
            else
            {
                crossfittersRemain = true;
            }

            if (powerliftersRemain && crossfittersRemain)
            {
                return false;
            }
        }

        if (!powerliftersRemain || !crossfittersRemain)
        {
            if (winningTeam != NULL)
            {
                (*winningTeam) = powerliftersRemain ? Team::POWERLIFTERS : Team::CROSSFITTERS;
            }
            return true;
        }

        return false;
    }
    
    bool Game::isDead(const Character& character) const
    {
        return (character.getHealth() <= 0);
    }
}
