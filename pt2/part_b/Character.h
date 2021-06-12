#ifndef CHARACTER_H
#define CHARACTER_H

#include "Auxiliaries.h"
#include "Exceptions.h"
#include <memory>
#include <cmath> //For abs only. Consider replacing with an inline or something.

namespace mtm
{
    class Character
    {
        private:
            int health;
            int ammo;
            Team team;
            GridPoint position;
        protected:
            const int range;
            const int power;

            void increaseAmmo(int by);
            void decreaseAmmo();
            Character(int health, int ammo, int range, int power, const Team& team, const GridPoint& position);
        public:
            /*
            Soldier& soldier = characters[0]*;
            AttackHandler& handler = soldier.attack(point);
            for(Character character : characters)
            {
                character.takeDamage(handler.calculateDamage(character));
            }
            */

            void setPosition(const GridPoint& point);
            const GridPoint& getPosition() const;
            int getPower() const;
            virtual void attack(const GridPoint& target) const = 0;
            virtual void reload() = 0;
    };
}


#endif //CHARACTER_H
