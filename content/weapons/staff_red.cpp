#include "staff_red.h"

#include "engine.h"
#include "hit.h"
#include "swing.h"

Staff_Red::Staff_Red(int damage) : Weapon{"staff_red", damage} {}

void Staff_Red::use(Engine& engine, Actor& attacker, Actor& defender) {
    if (defender.team != attacker.team) {
        defender.health -= damage;
        Vec direction = defender.get_position() - attacker.get_position();
        engine.events.add(Swing{sprite, direction, defender, damage});
    }
}