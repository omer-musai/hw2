#ifndef CHARACTER_H
#define CHARACTER_H

#include "Auxiliaries.h"
#include "Exceptions.h"
#include <memory>

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
            units_t health;
            units_t ammo;
            
            GridPoint position;
        protected:
            static const GridPoint NO_POSITION;
            const units_t range;
            const units_t power;
            const Team team;
            void increaseAmmo(units_t by);
            void decreaseAmmo();
            virtual void validateTargetInRange(const GridPoint& target) = 0;
            
            Character(units_t health, units_t ammo, units_t range, units_t power, const Team& team,
                      const GridPoint& position = NO_POSITION);
        public:
            void heal(units_t by);
            void decreaseHitPoints(units_t by);
            void setPosition(const GridPoint& point);
            const GridPoint& getPosition() const;
            Team getTeam() const;
            virtual void attack(const GridPoint& target, const std::shared_ptr<Character> character_in_dst) = 0;
            virtual void reload() = 0;
            virtual void dealDamage(Character& character, const GridPoint& target) = 0;
            virtual void move(const GridPoint& dst_coordinates) = 0;
            units_t getHealth() const;
            virtual char getStringSymbol() const = 0;
            virtual std::shared_ptr<Character> clone() const = 0;
    };
}


#endif //CHARACTER_H
