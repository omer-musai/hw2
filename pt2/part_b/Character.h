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
            const units_t range;
            const units_t power;
            const Team team;
            GridPoint position;
            
        protected:
            static const GridPoint NO_POSITION;
            void increaseAmmo(units_t by);
			
			//Decreases ammo or throws an OutOfAmmo if it is already 0.
            void decreaseAmmo();
			
			//validateTargetInRange throws an exception if target is not in range.
			//This will take unique class-based aiming circumstances into consideration (e.g.: soldier can only shoot in straight lines).
            virtual void validateTargetInRange(const GridPoint& target) = 0;
            
            units_t getAmmo() const;
            units_t getRange() const;
            units_t getPower() const;
			
			//Returns the movement range.
            virtual int getMovement() const = 0;

            Character(units_t health, units_t ammo, units_t range, units_t power, const Team& team,
                      const GridPoint& position = NO_POSITION);
        public:
			//Increases health.
            void heal(units_t by);
			
			//Decreases health.
            void decreaseHitPoints(units_t by);
			
            void setPosition(const GridPoint& point);
			
			//This throws an appropriate exception if given point is not within the character's movement range.
            void ensureInMovementRange(const GridPoint& point) const;
			
			//attack performs the necessary checks to ensure the attack is valid but does NOT yet deal damage.
			//Throws exceptions if anything is invalid.
            virtual void attack(const GridPoint& target, const std::shared_ptr<Character> character_in_dst) = 0;
			
			//Increases ammo by the appropriate magazine size.
            virtual void reload() = 0;
			
			//dealDamage is meant to be run after attack was called successfully.
			//It is meant to be run on each character in the characters vector. (target == the point that was targeted)
			//Will deal 0 damage if needed.
            virtual void dealDamage(Character& character, const GridPoint& target) = 0;
			
			//changes the coordinates or throws an appropriate exception.
            virtual void move(const GridPoint& dst_coordinates) = 0;
			
			//getStringSymbol returns the s, n or m for Soldier, Sniper and Medic respectively, and the caps is determined by the team.
            virtual char getStringSymbol() const = 0;
			
			//Returns a shared pointer to an instance of the appropriate Character subclass identical to the current instance.
            virtual std::shared_ptr<Character> clone() const = 0;

            const GridPoint& getPosition() const;
            Team getTeam() const;
            units_t getHealth() const;

            virtual ~Character() = default;

            
    };
}


#endif //CHARACTER_H
