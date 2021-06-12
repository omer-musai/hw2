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
            
            GridPoint position;
        protected:
            const int range;
            const int power;
            const Team team;
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
            void decreaseHitPoints(int by);
            void setPosition(const GridPoint& point);
            const GridPoint& getPosition() const;
            int getPower() const;
            Team getTeam() const;
            virtual void attack(const GridPoint& target, Character& character_in_dst) const = 0;
            virtual void reload() = 0;
            virtual void dealDamage(Character& character, const GridPoint& target) = 0;
    };
}


#endif //CHARACTER_H
