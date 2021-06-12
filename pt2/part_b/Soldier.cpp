#include "Soldier.h"

namespace mtm
{
    Soldier::Soldier(int health, int ammo, int range, int power, const Team& team, const GridPoint& position)
        : Character(health, ammo, range, power, team, position){}
    
    void Soldier::attack(const GridPoint& target)
    {  
        validateTargetInRange(target);
        

    }

    void Soldier::reload()
    {
        increaseAmmo(3);
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
    
    
}