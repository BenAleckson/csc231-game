#include "lightning.h"

#include "engine.h"
#include "hit.h"
#include "tile.h"

Lightning::Lightning(Vec position, int damage)
    : position(position), damage(damage) {}

void Lightning::execute(Engine& engine) {
    if (frame_count == 0) {
        sprite = engine.graphics.get_animated_sprite("lightning", 1);
        sprite.shift(Vec{0, 15});
        number_of_frames = sprite.number_of_frames();
    }

    engine.camera.add_overlay(position,
                              sprite.get_sprite());  // draw current frame
    sprite.update();                                 // move to next frame
}

void Lightning::when_done(Engine& engine) {
    Tile& tile = engine.dungeon.tiles(position);
    if (tile.actor) {
        engine.events.add(Hit{*tile.actor, damage});
    }
}