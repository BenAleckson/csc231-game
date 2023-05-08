#include "sword.h"

#include "engine.h"
#include "hit.h"
#include "thrust.h"

Sword::Sword(int damage) : Weapon{"sword", damage} {}

void Sword::use(Engine& engine, Actor& attacker, Actor& defender) {
    if (defender.team != attacker.team) {
        defender.health -= damage;
        Vec direction = defender.get_position() - attacker.get_position();
        engine.events.add(Thrust{sprite, direction, defender, damage});
    }
}