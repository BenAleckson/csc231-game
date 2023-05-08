#include "rest.h"

#include <iostream>

#include "actor.h"

Result Rest::perform(Engine&) {
    if (actor->health < actor->max_health) {
        actor->health += 1;
    }
    return success();
}
