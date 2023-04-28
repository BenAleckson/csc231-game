#include "wander.h"

#include "actor.h"
#include "engine.h"
#include "move.h"
#include "randomness.h"
#include "rest.h"
#include "vec.h"

Result Wander::perform(Engine& engine) {
    // get current pos and neighbors
    Vec position = actor->get_position();
    std::vector<Vec> neighbors = engine.dungeon.neighbors(position);
    // randomize neighbors
    shuffle(std::begin(neighbors), std::end(neighbors));
    for (Vec neighbor : neighbors) {
        // for each one, find a wall and non occupy tile
        Tile& tile = engine.dungeon.tiles(neighbor);
        if (!tile.is_wall() && !tile.actor) {
            Vec direction = neighbor - position;
            return alternative(Move{direction});
        }
    }

    // if no good tile
    // rest
    return alternative(Rest{});
}