#pragma once

#include "event.h"
#include "sprite.h"
#include "vec.h"

class Actor;

class Thrust : public Event {
public:
    Thrust(Sprite& sprite, Vec direction, Actor& defender, int damage);
    void execute(Engine&) override;
    void when_done(Engine& engine) override;

private:
    Sprite& sprite;
    Sprite original;
    Vec direction;
    Actor& defender;
    int damage;
};