#include "Medic.h"

namespace mtm
{
    Medic::Medic(units_t health, units_t ammo, units_t range, units_t power, const Team& team)
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
        else if(character_in_dst->getTeam() != this->getTeam())
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
       units_t distance = GridPoint::distance(getPosition(), target);

       if(distance == 0)
       {
           throw IllegalTarget();
       }

       else if(distance > this->getRange())
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
        else if(character.getTeam() == this->getTeam())
        {
            character.heal(this->getPower());
        }
        else
        {
            character.decreaseHitPoints(this->getPower());
        }   
    }

    void Medic::move(const GridPoint& dst_coordinates)
    {
        if(GridPoint::distance(getPosition(), dst_coordinates) > MOVEMENT)
        {
            throw MoveTooFar();
        }

        setPosition(dst_coordinates);
    }

    char Medic::getStringSymbol() const
    {
        return getTeam() == POWERLIFTERS ? 'M' : 'm';
    }

     std::shared_ptr<Character> Medic::clone() const
    {
        return std::shared_ptr<Character>(new Medic(*this));
    }
}