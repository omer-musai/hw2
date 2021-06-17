#include "Character.h"

namespace mtm
{
    const GridPoint Character::NO_POSITION = GridPoint(-1, -1);

    void Character::setPosition(const GridPoint& point)
    {
        position = point;
    }
    

    void Character::increaseAmmo(units_t by)
    {
        this->ammo += by;
    }

    void Character::decreaseAmmo()
    {
        if (ammo <= 0)
        {
            throw OutOfAmmo();
        }
        --ammo;
    }

    void Character::decreaseHitPoints(units_t by)
    {
        this->health -= by;
    }

    void Character::heal(units_t by)
    {
        this->health += by;
    }

    Character::Character(units_t health, units_t ammo, units_t range, units_t power, const Team &team, const GridPoint& position)
        : health(health), ammo(ammo), range(range), power(power), team(team), position(position)
    {}


    //getters
    Team Character::getTeam() const
    {
        return team;
    }

    units_t Character::getHealth() const
    {
        return health;
    }

    const GridPoint& Character::getPosition() const
    {
        return position;
    }

    units_t Character::getAmmo() const
    {
        return ammo;
    }
    units_t Character::getRange() const
    {
        return range;
    }
    units_t Character::getPower() const
    {
        return power;
    }

    void Character::ensureInMovementRange(const GridPoint &point) const
    {
        if(GridPoint::distance(getPosition(), point) > getMovement())
        {
            throw MoveTooFar();
        }
    }
}
