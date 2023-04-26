#include "move.h"

#include <iostream>

#include "OpenDoor.h"
#include "actor.h"
#include "engine.h"

Move::Move(Vec direction) : direction(direction) {}

Result Move::perform(Engine& engine) {
    Vec position = actor->get_position() + direction;
    actor->change_direction(direction);

    Tile& tile = engine.dungeon.tiles(position);
    if (tile.is_door()) {
        return alternative(OpenDoor{position});
    }

    if (tile.is_wall()) {
        return failure();
    }

    actor->move_to(position);
    return success();
}