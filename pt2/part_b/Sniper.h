#ifndef SNIPER_H
#define SNIPER_H

#include "Character.h"

/*
  \
 /                                 />
 \__+_____________________/\/\___/ /|
 ()______________________      / /|/\
             /0 0  ---- |----    /---\
            |0 o 0 ----|| - \ --|      \
             \0_0/____/ |    |  |\      \
                         \__/__/  |      \
Bang! Bang!                       |       \
                                  |         \
                                  |__________|
*/
namespace mtm
{
    class Sniper : public Character
    {
        private:
            static const int DISTANCE_FACTOR = 2;
            static const int IMPACT_FACTOR = 2;
            static const int MAGAZINE_SIZE = 2;
            static const int SNIPER_MOVEMENT = 4;
            int shot_counter;

        public:
            Sniper(int health, int ammo, int range, int power, const Team& team, const GridPoint& position);
            
            void reload();
            void validateTargetInRange(const GridPoint& target);
            void attack(const GridPoint& target, const Character& character_in_dst);
            void dealDamage(Character& character, const GridPoint& target);
            void move(const GridPoint & dst_coordinates);
    };

}

#endif //SNIPER_H
