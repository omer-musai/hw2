#include "Character.h"

namespace mtm
{
    class Game
    {
        public:
            Game(int height, int width);
            Game(const& Game other);

            Game& operator=(const Game& other);
            std::ostream& operator<<();

            ~Game() = default;


            void addCharacter(const GridPoint& coordinates, std::shared_ptr<Character> character);
            
            static std::shared_ptr<Character> makeCharacter(CharacterType type, Team team,
                units_t health, units_t ammo, units_t range, units_t power);
            
            void move(const GridPoint & src_coordinates, const GridPoint & dst_coordinates);

            void attack(const GridPoint & src_coordinates, const GridPoint & dst_coordinates);

            void reload(const GridPoint & coordinates);

            bool isOver(Team* winningTeam=NULL) const;



    }
}


