#include "Soldier.h"

namespace mtm
{
    Soldier::Soldier(int health, int ammo, int range, int power, const Team& team, const GridPoint& position)
        : Character(health, ammo, range, power, team, position){}
    
    void Soldier::attack(const GridPoint& target, Character& character_in_dst)
    {  
        validateTargetInRange(target);
        decreaseAmmo();
    }

    void Soldier::reload()
    {
        increaseAmmo(SOLDIER_MAGAZINE);
    }

    void Soldier::validateTargetInRange(const GridPoint& target)
    {
       const GridPoint& position = getPosition();

       if((target.row != position.row && target.col != position.col)
            || GridPoint::distance(position, target) > this->range)
       {
           throw OutOfRange();
       }
    }
    
    void Soldier::dealDamage(Character& character, const GridPoint& target)
    {   
        if(character.getTeam() == this->team)
        {
            return;
        }

        int damage = this->power;
        const GridPoint& position = getPosition();
       
        if(position == target)
        {
            character.decreaseHitPoints(damage);
        }
        else if(GridPoint::distance(position, target) <= ceil(this->range / FACTOR_OF_DISTANCE))
        {
            character.decreaseHitPoints(ceil(damage / FACTOR_OF_IMPACT));
        }
    }
    
}