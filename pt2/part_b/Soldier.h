#ifndef SOLDIER_H
#define SOLDIER_H

#include "Character.h"


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
    class Soldier : public Character
    {
        private:
            static const int IMPACT_FACTOR = 2;
            static const int DISTANCE_FACTOR = 3;
            static const int MAGAZINE_SIZE = 3;
            static const int SOLDIER_MOVEMENT = 3;

        public:
            Soldier(int health, int ammo, int range, int power, const Team& team);
            
            void reload() override;
            void validateTargetInRange(const GridPoint& target) override;
            void attack(const GridPoint& target, const std::shared_ptr<Character> character_in_dst) override;
            void dealDamage(Character& character, const GridPoint& target) override;
            void move(const GridPoint & dst_coordinates) override;
            char getStringSymbol() const override;
    };

}

#endif //SOLDIER_H
