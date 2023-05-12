#pragma once

#include "weapon.h"

class Staff_Red : public Weapon {
public:
    Staff_Red();
    void use(Engine& engine, Actor& attacker, Actor& defender) override;
};