#ifndef SNIPER_H
#define SNIPER_H

#include "Character.h"

#define DISTANCE_FACTOR 2
#define SNIPER_MAGAZINE 2
#define IMPACT_FACTOR 2

namespace mtm
{
    class Sniper : Character
    {
        private:
            int shot_counter;

        public:
            Sniper(int health, int ammo, int range, int power, const Team& team, const GridPoint& position, int shot_counter);
            
            void reload();
            void validateTargetInRange(const GridPoint& target);
            void attack(const GridPoint& target, Character& character_in_dst);
            void dealDamage(Character& character, const GridPoint& target);
    };

}

#endif //SNIPER_H
