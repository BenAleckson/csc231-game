#pragma once

#include "weapon.h"

class Hammer_Big : public Weapon {
public:
    Hammer_Big(int damage);
    void use(Engine& engine, Actor& attacker, Actor& defender) override;
};