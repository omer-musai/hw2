#include <iostream>
#include <memory>
#include <vector>

#include "Character.h"
#include "Auxiliaries.h"
#include "Board.h"


namespace mtm
{
    class Game
    {
        private:
            std::vector<std::shared_ptr<Character>> characters;
            Board board;
            
        public:
            Game() = delete;
            Game(int height, int width);
            Game(const Game& other) = default;

            Game& operator=(const Game& other) = default;
            friend std::ostream& operator<<(std::ostream& stream, Game& game);

            ~Game() = default;


            void addCharacter(const GridPoint& coordinates, std::shared_ptr<Character> character);
            
            static std::shared_ptr<Character> makeCharacter(CharacterType type, Team team,
                units_t health, units_t ammo, units_t range, units_t power);
            
            void move(const GridPoint & src_coordinates, const GridPoint & dst_coordinates);

            void attack(const GridPoint & src_coordinates, const GridPoint & dst_coordinates);

            void reload(const GridPoint & coordinates);

            bool isOver(Team* winningTeam=NULL) const;
    };
}
