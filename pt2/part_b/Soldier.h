#ifndef SOLDIER_H
#define SOLDIER_H

#include "Character.h"

#define FACTOR_OF_IMPACT 2
#define FACTOR_OF_DISTANCE 3
#define SOLDIER_MAGAZINE 3

/*
 ,______________________________________       
|_________________,----------._ [____]  ""-,__  __....-----=====
               (_(||||||||||||)___________/   ""                |
                  `----------' Krogg98[ ))"-,                   |
                                       ""    `,  _,--....___    |
                                               `/           """"
*/

namespace mtm
{
    class Soldier : Character
    {
        private:
            static const int IMPACT_FACTOR = 2;
            static const int DISTANCE_FACTOR = 3;
            static const int MAGAZINE_SIZE = 3;
            static const int SOLDIER_MOVEMENT = 3;

        public:
            Soldier(int health, int ammo, int range, int power, const Team& team, const GridPoint& position);
            
            void reload();
            void validateTargetInRange(const GridPoint& target);
            void attack(const GridPoint& target, const Character& character_in_dst);
            void dealDamage(Character& character, const GridPoint& target);
            void move(const GridPoint & dst_coordinates);
    };

}

#endif //SOLDIER_H
