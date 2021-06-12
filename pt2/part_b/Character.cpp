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

    void Character::increaseAmmo(int by)
    {

    }

    void Character::decreaseAmmo()
    {
        if (ammo <= 0)
        {
            throw OutOfAmmo();
        }

        --ammo;
    }
}
