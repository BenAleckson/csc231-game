#pragma once

#include <memory>
#include <vector>

#include "actor.h"
#include "animatedsprite.h"
#include "monstertype.h"

class Monster : public Actor {
public:
    Monster(Engine& engine, const MonsterType& type, const Vec& position);
    virtual ~Monster() {}

    // orient monster towards direction
    void change_direction(const Vec& direction) override;
    void attack(Actor& defender) override;
    void update() override;
    std::unique_ptr<Action> take_turn() override;
    std::vector<Sprite> get_sprites() const override;

    // list of minons for mioions that necromancer spawns.
    std::vector<std::shared_ptr<Monster>> minions;

private:
    MonsterType type;
    AnimatedSprite sprite;
};
