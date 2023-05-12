#include "staff_red.h"

#include "engine.h"
#include "hit.h"
#include "lightning.h"
#include "summon.h"

Staff_Red::Staff_Red(int damage) : Weapon{"staff_red", damage} {}

void Staff_Red::use(Engine& engine, Actor& attacker, Actor& defender) {
    if (defender.team != attacker.team) {
        defender.health -= damage;
        Vec direction = defender.get_position() - attacker.get_position();
        engine.events.add(Summon{defender.get_position(), damage});
    }
}