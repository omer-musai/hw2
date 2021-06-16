#include "Sniper.h"

namespace mtm
{
    Sniper::Sniper(units_t health, units_t ammo, units_t range, units_t power, const Team& team)
        : Character(health, ammo, range, power, team)
        {
            shot_counter = 0;
        }

    void Sniper::attack(const GridPoint& target, const std::shared_ptr<Character> character_in_dst)
    {
        if (character_in_dst == nullptr)
        {
            throw CellEmpty();
        }

        validateTargetInRange(target);

        if( !(character_in_dst->getPosition() == target) || character_in_dst->getTeam() == this->team)
        {
            throw IllegalTarget();
        }
        
        decreaseAmmo();
    }

    void Sniper::reload()
    {
        increaseAmmo(Sniper::MAGAZINE_SIZE);
    }

    void Sniper::validateTargetInRange(const GridPoint& target)
    {
       units_t distance = GridPoint::distance(getPosition(), target);

       if(distance < ceil(range / DISTANCE_FACTOR) || distance > this->range)
       {
           throw OutOfRange();
       }
    }
    
    void Sniper::dealDamage(Character& character, const GridPoint& target)
    {
        if (!(character.getPosition() == target))
        {
            return;
        }

        units_t damage = this->power;
        if(shot_counter == Sniper::COMBO_FOR_BONUS - 1)
        {
            character.decreaseHitPoints(damage * IMPACT_FACTOR);
            shot_counter = 0;
        }
        else
        {
            character.decreaseHitPoints(damage);
            ++shot_counter;
        }
        
    }

    void Sniper::move(const GridPoint& dst_coordinates)
    {
        if(GridPoint::distance(getPosition(), dst_coordinates) > MOVEMENT)
        {
            throw MoveTooFar();
        }

        setPosition(dst_coordinates);
    }

    char Sniper::getStringSymbol() const
    {
        return team == POWERLIFTERS ? 'N' : 'n';
    }

    std::shared_ptr<Character> Sniper::clone() const
    {
        return std::shared_ptr<Character>(new Sniper(*this));
    }
}