#include "explode.h"

#include "engine.h"
#include "explosion.h"
#include "hit.h"

Explode::Explode(int damage) : Weapon{"none", damage} {}

void Explode::use(Engine& engine, Actor& attacker, Actor& defender) {
    std::vector<Vec> neighbors =
        engine.dungeon.neighbors(attacker.get_position());
    for (Vec neighbor : neighbors) {
        defender.health -= damage;
        engine.events.add(Explosion{neighbor, damage});
    }
    attacker.alive = false;
    engine.dungeon.remove_actor(attacker.get_position());
}