#pragma once

#include "action.h"
#include "actor.h"
#include "engine.h"

class Attack : public Action {
public:
    Attack(Actor& defender);
    Result perform(Engine& engine) override;

private:
    Actor& defender;
};