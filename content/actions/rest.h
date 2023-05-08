#pragma once

#include "action.h"
#include "actor.h"

// Do nothing this turn
class Rest : public Action {
public:
    Result perform(Engine& engine) override;
};
