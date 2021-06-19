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
            
			//Increases ammo by the appropriate magazine size.
            void reload() override;
			
			//validateTargetInRange throws an appropriate exception if target is not in range.
            void validateTargetInRange(const GridPoint& target) override;
			
			//attack performs the necessary checks to ensure the attack is valid but does NOT yet deal damage.
			//Throws exceptions if anything is invalid.
            void attack(const GridPoint& target, const std::shared_ptr<Character> character_in_dst) override;
			
			//dealDamage is meant to be run after attack was called successfully.
			//It is meant to be run on each character in the characters vector. (target == the point that was targeted)
			//Will deal 0 damage if needed.
            void dealDamage(Character& character, const GridPoint& target) override;
			
			//changes the coordinates or throws an appropriate exception.
            void move(const GridPoint& dst_coordinates) override;
			
			//Returns the S or s depending on the soldier's team.
            char getStringSymbol() const override;
			
			//Returns a shared pointer to an instance of Soldier identical to the current instance.
            virtual std::shared_ptr<Character> clone() const override;
    };

}

#endif //SOLDIER_H
