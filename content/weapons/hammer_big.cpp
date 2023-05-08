#include "hammer_big.h"

#include "engine.h"
#include "hit.h"
#include "swing.h"

Hammer_Big::Hammer_Big(int damage) : Weapon{"hammer_big", damage} {}

void Hammer_Big::use(Engine& engine, Actor& attacker, Actor& defender) {
    if (defender.team != attacker.team) {
        defender.health -= damage;
        Vec direction = defender.get_position() - attacker.get_position();
        engine.events.add(Swing{sprite, direction, defender, damage});
    }
}