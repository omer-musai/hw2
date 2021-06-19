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
            static const units_t DISTANCE_FACTOR = 2;
            static const units_t IMPACT_FACTOR = 2;
            static const units_t MAGAZINE_SIZE = 2;
            static const units_t MOVEMENT = 4;
            static const int COMBO_FOR_BONUS = 3;
            int shot_counter;
			//Returns the movement range.
            int getMovement() const override;

        public:
            Sniper(units_t health, units_t ammo, units_t range, units_t power, const Team& team);
            
			//Increases ammo by the appropriate magazine size.
            void reload() override;
			
			//validateTargetInRange throws an exception if target is not in range.
            void validateTargetInRange(const GridPoint& target) override;
			
			//attack performs the necessary checks to ensure the attack is valid but does NOT yet deal damage.
			//Throws exceptions if anything is invalid.
            void attack(const GridPoint& target, const std::shared_ptr<Character> character_in_dst) override;
			
			//dealDamage is meant to be run after attack was called successfully.
			//It is meant to be run on each character in the characters vector. (target == the point that was targeted)
			//Will deal 0 damage if needed.
            void dealDamage(Character& character, const GridPoint& target) override;
            void move(const GridPoint& dst_coordinates) override;
			
			//Returns the N or n depending on the sniper's team.
            char getStringSymbol() const override;
            
			//Returns a shared pointer to an instance of Sniper identical to the current instance.
            virtual std::shared_ptr<Character> clone() const override;
    };
}

#endif //SNIPER_H
