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

        public:
            Sniper(units_t health, units_t ammo, units_t range, units_t power, const Team& team);
            
            void reload() override;
            void validateTargetInRange(const GridPoint& target) override;
            void attack(const GridPoint& target, const std::shared_ptr<Character> character_in_dst) override;
            void dealDamage(Character& character, const GridPoint& target) override;
            void move(const GridPoint& dst_coordinates) override;
            char getStringSymbol() const override;
    };

}

#endif //SNIPER_H
