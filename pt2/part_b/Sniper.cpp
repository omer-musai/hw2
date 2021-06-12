#include "Sniper.h"

namespace mtm
{
    Sniper::Sniper(int health, int ammo, int range, int power, const Team& team, const GridPoint& position, int shot_counter)
        : Character(health, ammo, range, power, team, position)
        {
            shot_counter = 0;
        }
    
    void Sniper::attack(const GridPoint& target, Character& character_in_dst)
    {  
        validateTargetInRange(target);

        if( !(character_in_dst.getPosition() == target) || character_in_dst.getTeam() == this->team)
        {
            throw IllegalTarget();
        }
        
        decreaseAmmo();
    }

    void Sniper::reload()
    {
        increaseAmmo(SNIPER_MAGAZINE);
    }

    void Sniper::validateTargetInRange(const GridPoint& target)
    {
       const GridPoint& position = getPosition();
       int distance =  GridPoint::distance(position, target);

       if( distance < ceil(range / DISTANCE_FACTOR) || distance > this->range)
       {
           throw OutOfRange();
       }
    }
    
    void Sniper::dealDamage(Character& character, const GridPoint& target)
    {   
        int damage = this->power;
        if(shot_counter == 3)
        {
            character.decreaseHitPoints(damage * IMPACT_FACTOR);
            shot_counter = 0;
        }
        else
        {
            character.decreaseHitPoints(damage);
            shot_counter++;
        }
        
    }
    
}