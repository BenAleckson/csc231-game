#include "summon.h"

#include "engine.h"
#include "hit.h"
#include "vec.h"

Summon::Summon(Sprite& sprite, Vec direction, Actor& defender, int damage)
    : Event{3},
      sprite{sprite},
      original{sprite},
      direction{direction},
      defender{defender},
      damage{damage} {
    sprite.shift.y -= sprite.size.y / 4;
    sprite.shift.x -= sprite.size.x / 2;

    sprite.angle = 0;
}

void Summon::execute(Engine&) {
    sprite.shift += direction * 1;
}

void Summon::when_done(Engine& engine) {
    sprite = original;
    engine.events.add(Hit(defender, damage));
}