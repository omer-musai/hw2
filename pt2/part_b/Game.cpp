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

        
        character.attack(dst_coordinates, board.getCharacterIfExists(dst_coordinates, this->characters));
       
       
        for (std::shared_ptr<Character> &characterPtr : characters)
        {
            character.dealDamage(*characterPtr, dst_coordinates);
        }
        
        std::vector<std::shared_ptr<Character>>::iterator new_end =
                std::remove_if(characters.begin(), characters.end(), Game::isDead);
        characters.erase(new_end, characters.end());
    }

    void Game::reload(const GridPoint& coordinates)
    {
        Character &character = board.getCharacterInPoint(coordinates, characters);
        character.reload();
    }

    bool Game::isOver(Team* winningTeam) const
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

    std::shared_ptr<Character> Game::makeCharacter(CharacterType type, Team team, units_t health, units_t ammo, units_t range, units_t power) {
        std::shared_ptr<Character> ptr = nullptr;

        if (type == SOLDIER)
        {
            ptr = std::shared_ptr<Character>(new Soldier(health, ammo, range, power, team));
        }
        else if (type == MEDIC)
        {
            ptr = std::shared_ptr<Character>(new Medic(health, ammo, range, power, team));
        }
        else //type == SNIPER
        {
            ptr = std::shared_ptr<Character>(new Sniper(health, ammo, range, power, team));
        }

        return ptr;
    }

    bool Game::isDead(const std::shared_ptr<Character>& character)
    {
        return (character->getHealth() <= 0);
    }

    std::ostream &operator<<(std::ostream &stream, const Game &game) {
        std::string boardString = game.board.generateBoardString(game.characters);
        const char* boardCString = boardString.c_str();
        printGameBoard(stream, boardCString,
          boardCString + boardString.length(), game.board.column_count);
        return stream;
    }
}
