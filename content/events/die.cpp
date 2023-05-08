#include "die.h"

#include "actor.h"
#include "engine.h"

Die::Die(Actor& actor) : actor(actor) {}

void Die::execute(Engine& engine) {
    actor.alive = false;
    engine.dungeon.remove_actor(actor.get_position());
}