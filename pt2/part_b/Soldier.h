#ifndef SOLDIER_H
#define SOLDIER_H

#include "Character.h"

namespace mtm
{
    class Soldier : Character
    {
        private:
            

        public:
            Soldier(int health, int ammo, int range, int power, const Team& team, const GridPoint& position);
            
            void reload();
            void validateTargetInRange(const GridPoint& target);
            void attack(const GridPoint& target);
    };

}

#endif //SOLDIER_H
