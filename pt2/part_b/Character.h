#ifndef CHARACTER_H
#define CHARACTER_H

#include "Auxiliaries.h"
#include "Exceptions.h"
#include <memory>
#include <cmath> //For abs only. Consider replacing with an inline or something.

/*
       .---.
  ___ /_____\
 /\.-`( '.' )
/ /    \_-_/_
\ `-.-"`'V'//-.
 `.__,   |// , \
     |Ll //Ll|\ \
     |__//   | \_\
    /---|[]==| / /
    \__/ |   \/\/
    /_   | Ll_\|
     |`^"""^`|
     |   |   |
     |   |   |
     |   |   |
     |   |   |
     L___l___J
      |_ | _|
     (___|___)
*/

namespace mtm
{
    class Character
    {
        private:
            int health;
            int ammo;
            
            GridPoint position;
        protected:
            const int range;
            const int power;
            const Team team;
            void increaseAmmo(int by);
            void decreaseAmmo();
            
            Character(int health, int ammo, int range, int power, const Team& team, const GridPoint& position);
        public:
           
            void heal(int by);
            void decreaseHitPoints(int by);
            void setPosition(const GridPoint& point);
            const GridPoint& getPosition() const;
            int getPower() const;
            Team getTeam() const;
            virtual void attack(const GridPoint& target, const Character& character_in_dst) const = 0;
            virtual void reload() = 0;
            virtual void dealDamage(Character& character, const GridPoint& target) = 0;
            virtual void move(const GridPoint & dst_coordinates) = 0;
            int getHealth() const;
    };
}


#endif //CHARACTER_H
