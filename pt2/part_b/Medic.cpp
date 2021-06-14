#include "Medic.h"

namespace mtm
{
    Medic::Medic(int health, int ammo, int range, int power, const Team& team)
        : Character(health, ammo, range, power, team){}


    void Medic::attack(const GridPoint& target, const std::shared_ptr<Character> character_in_dst)
    {
        if (character_in_dst == nullptr)
        {
            throw CellEmpty();
        }

        validateTargetInRange(target);

        if( !(character_in_dst->getPosition() == target))
        {
            throw IllegalTarget();
        }
        else if(character_in_dst->getTeam() != this->team)
        {
            decreaseAmmo();
            return;
        }  
    }

    void Medic::reload()
    {
        increaseAmmo(Medic::MAGAZINE_SIZE);
    }

    void Medic::validateTargetInRange(const GridPoint& target)
    {
       int distance = GridPoint::distance(getPosition(), target);

       if(distance == 0)
       {
           throw IllegalTarget();
       }

       else if(distance > this->range)
       {
           throw OutOfRange();
       }
    }
    
    void Medic::dealDamage(Character& character, const GridPoint& target)
    {
        if (!(character.getPosition() == target))
        {
            return;
        }
        else if(character.getTeam() == this->team)
        {
            character.heal(this->power);
        }
        else
        {
            character.decreaseHitPoints(this->power);
        }   
    }

    void Medic::move(const GridPoint & dst_coordinates)
    {
        if(GridPoint::distance(getPosition(), dst_coordinates) > MEDIC_MOVEMENT)
        {
            throw MoveTooFar();
        }

        setPosition(dst_coordinates);
    }

    char Medic::getStringSymbol() const
    {
        return team == POWERLIFTERS ? 'M' : 'm';
    }
}