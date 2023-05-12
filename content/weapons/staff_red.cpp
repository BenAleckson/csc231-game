#include "staff_red.h"

#include "engine.h"
#include "summon.h"

Staff_Red::Staff_Red(int damage) : Weapon{"staff_red", 0} {}

void Staff_Red::use(Engine& engine, Actor& attacker, Actor& defender) {
    Vec direction = defender.get_position() - attacker.get_position();
    engine.events.add(Summon{sprite, direction});
}