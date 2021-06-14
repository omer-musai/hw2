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
            static const int MEDIC_MOVEMENT = 5;
            

        public:
            Medic(int health, int ammo, int range, int power, const Team& team, const GridPoint& position);
            
            void reload();
            void validateTargetInRange(const GridPoint& target);
            void attack(const GridPoint& target, const Character& character_in_dst);
            void dealDamage(Character& character, const GridPoint& target);
            void move(const GridPoint & dst_coordinates);
    };

}

#endif //MEDIC_H
