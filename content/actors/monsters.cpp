#include "monsters.h"

#include "axe.h"
#include "engine.h"
#include "hammer_big.h"
#include "monster.h"
#include "move.h"
#include "none.h"
#include "randomness.h"
#include "rest.h"
#include "staff_red.h"
#include "sword.h"
#include "wander.h"

namespace Monsters {
std::unique_ptr<Action> default_behavior(Engine& engine, Monster& me) {
    // if moster can see hero -> pursue!
    if (me.is_visible() && engine.hero) {
        std::vector<Vec> path = engine.dungeon.calculate_path(
            me.get_position(), engine.hero->get_position());
        if (path.size() > 1) {
            Vec direction = path.at(1) - path.at(0);
            return std::make_unique<Move>(direction);
        }
    }

    // if monster can't see hero
    if (probability(75)) {
        return std::make_unique<Wander>();
    }
    return std::make_unique<Rest>();
}

constexpr int default_speed{8};

MonsterType goblin() {
    int health = 1;
    return {"goblin", 16, health, std::make_shared<Axe>(1), default_behavior};
}

MonsterType zombie_big() {
    int health = 5;
    return {"zombie_big", 4, health, std::make_shared<Hammer_Big>(1),
            default_behavior};
}

MonsterType orc() {
    int health = 2;
    return {"orc", default_speed, health, std::make_shared<Sword>(1),
            default_behavior};
}

MonsterType necromancer() {
    int health = 1;
    return {"necromancer", default_speed, health,
            std::make_shared<Staff_Red>(1), default_behavior};
}
}  // namespace Monsters