#include "CloseDoor.h"

#include "actor.h"
#include "engine.h"
#include "updatefov.h"

Result CloseDoor::perform(Engine& engine) {
    // get postion of actor
    Vec position = actor->get_position();
    // search neighboring tiles
    bool closed_any_doors{false};
    std::vector<Vec> neighbors = engine.dungeon.neighbors(position);
    for (Vec neighbor : neighbors) {
        //  if tile is door
        Tile& tile = engine.dungeon.tiles(neighbor);
        if (tile.is_door()) {
            Door& door = engine.dungeon.doors.at(neighbor);
            door.close();
            closed_any_doors = true;
        }
    }
    if (closed_any_doors) {
        engine.events.add(UpdateFOV{});
        return success();
    } else {
        return failure();
    }
    //  close it
}