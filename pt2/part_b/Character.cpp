#include "Character.h"

namespace mtm
{
    const GridPoint Character::NO_POSITION = GridPoint(-1, -1);
    void Character::setPosition(const GridPoint& point)
    {
        position = point;
    }
    const GridPoint& Character::getPosition() const
    {
        return position;
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

    Character::Character(int health, int ammo, int range, int power, const Team &team, const GridPoint& position)
        : health(health), ammo(ammo), range(range), power(power), team(team), position(position)
    {}
}
