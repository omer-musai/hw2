#include "Character.h"

namespace mtm
{
    void Character::setPosition(const GridPoint& point)
    {
        position = point;
    }
    const GridPoint& Character::getPosition() const
    {
        return position;
    }

    int Character::getPower() const
    {
        return this->power;
    }

    Team Character::getTeam() const
    {
        return this->team;
    }

    void Character::increaseAmmo(int by)
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

    void Character::decreaseHitPoints(int by)
    {
        this->health -= by;
    }

    int Character::getHealth() const
    {
        return this->health;
    }

    void Character::heal(int by)
    {
        this->health += by;
    }
}
