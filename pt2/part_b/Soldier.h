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
            static const units_t IMPACT_FACTOR = 2;
            static const units_t DISTANCE_FACTOR = 3;
            static const units_t MAGAZINE_SIZE = 3;
            static const units_t MOVEMENT = 3;
            int getMovement() const override;

        public:
            Soldier(units_t health, units_t ammo, units_t range, units_t power, const Team& team);
            
            void reload() override;
            void validateTargetInRange(const GridPoint& target) override;
            void attack(const GridPoint& target, const std::shared_ptr<Character> character_in_dst) override;
            void dealDamage(Character& character, const GridPoint& target) override;
            void move(const GridPoint& dst_coordinates) override;
            char getStringSymbol() const override;

            virtual std::shared_ptr<Character> clone() const override;
    };

}

#endif //SOLDIER_H
