#include "Soldier.h"

namespace mtm
{
    Soldier::Soldier(int health, int ammo, int range, int power, const Team& team)
        : Character(health, ammo, range, power, team){}
    
    void Soldier::attack(const GridPoint& target, const Character& character_in_dst)
    {
        validateTargetInRange(target);
        decreaseAmmo();
    }

    void Soldier::reload()
    {
        increaseAmmo(Soldier::MAGAZINE_SIZE);
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
        else if(GridPoint::distance(position, target) <= ceil(this->range / Soldier::DISTANCE_FACTOR))
        {
            character.decreaseHitPoints(ceil(damage / Soldier::IMPACT_FACTOR));
        }
    }

    void Soldier::move(const GridPoint & dst_coordinates)
    {
        if(GridPoint::distance(getPosition(), dst_coordinates) > SOLDIER_MOVEMENT)
        {
            throw MoveTooFar();
        }

        setPosition(dst_coordinates);
    }

}