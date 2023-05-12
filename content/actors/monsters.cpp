#include "monsters.h"

#include "axe.h"
#include "engine.h"
#include "explode.h"
#include "hammer_big.h"
#include "monster.h"
#include "move.h"
#include "none.h"
#include "randomness.h"
#include "rest.h"
#include "staff_red.h"
#include "summon.h"
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

std::unique_ptr<Action> necromancer_behavior(Engine& engine, Monster& me) {
    auto it = std::remove_if(std::begin(me.minions), std::end(me.minions),
                             [](const auto& actor) { return !actor->alive; });
    me.minions.erase(it, std::end(me.minions));
    if (me.is_visible() && me.minions.size() == 0) {
        std::vector<Vec> neighbors =
            engine.dungeon.neighbors(me.get_position());
        for (Vec neighbor : neighbors) {
            //  if tile is door
            Tile& tile = engine.dungeon.tiles(neighbor);
            if (!tile.is_door() && !tile.is_wall() && !tile.actor) {
                auto monster = std::make_shared<Monster>(
                    engine, Monsters::demon_tiny(), neighbor);
                engine.actors.add(monster);
                me.minions.push_back(monster);
            }
        }
        return std::make_unique<Rest>();
    }
    // default behavior when not spawning monsters
    else if (me.is_visible() && engine.hero) {
        std::vector<Vec> path = engine.dungeon.calculate_path(
            me.get_position(), engine.hero->get_position());
        if (path.size() > 1) {
            Vec direction = -1 * (path.at(1) - path.at(0));
            Vec position = me.get_position() + direction;
            Tile& tile = engine.dungeon.tiles(position);
            if (!tile.is_door() && !tile.is_wall() && !tile.actor) {
                return std::make_unique<Move>(direction);
            } else {
                return std::make_unique<Rest>();
            }
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
            std::make_shared<Staff_Red>(1), necromancer_behavior};
}

MonsterType demon_tiny() {
    int health = 1;
    return {"demon_tiny", 16, health, std::make_shared<Explode>(3),
            default_behavior};
}
}  // namespace Monsters