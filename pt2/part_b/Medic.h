#ifndef MEDIC_H
#define MEDIC_H

#include "Character.h"

/*
\_________________/
|       | |       |
|       | |       |
|       | |       |
|_______| |_______|
|_______   _______|
|       | |       |
|       | |       |
 \      | |      /
  \     | |     /
   \    | |    /
    \   | |   /
     \  | |  /
      \ | | /
       \| |/
        \_/
*/
namespace mtm
{
    class Medic : public Character
    {
        private:
            static const int MAGAZINE_SIZE = 5;
            static const int MOVEMENT = 5;
            

        public:
            Medic(int health, int ammo, int range, int power, const Team& team);
            
            void reload() override;
            void validateTargetInRange(const GridPoint& target) override;
            void attack(const GridPoint& target, const std::shared_ptr<Character> character_in_dst) override;
            void dealDamage(Character& character, const GridPoint& target) override;
            void move(const GridPoint & dst_coordinates) override;
            char getStringSymbol() const override;
    };

}

#endif //MEDIC_H
