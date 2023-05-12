#pragma once

#include "weapon.h"

class Explode : public Weapon {
public:
    Explode(int damage);
    void use(Engine& engine, Actor& attacker, Actor& defender) override;
};