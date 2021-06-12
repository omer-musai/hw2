#ifndef SOLDIER_H
#define SOLDIER_H

#include "Character.h"

#define FACTOR_OF_IMPACT 2
#define FACTOR_OF_DISTANCE 3
#define SOLDIER_MAGAZINE 3

namespace mtm
{
    class Soldier : Character
    {
        private:
            

        public:
            Soldier(int health, int ammo, int range, int power, const Team& team, const GridPoint& position);
            
            void reload();
            void validateTargetInRange(const GridPoint& target);
            void attack(const GridPoint& target, Character& character_in_dst);
            void dealDamage(Character& character, const GridPoint& target);
    };

}

#endif //SOLDIER_H
