#include "summon.h"

#include "engine.h"
#include "hit.h"
#include "vec.h"

Summon::Summon(Sprite& sprite, Vec direction)
    : Event{3}, sprite{sprite}, original{sprite}, direction{direction} {
    sprite.shift.y -= sprite.size.y / 4;
    sprite.shift.x -= sprite.size.x / 2;

    sprite.angle = 0;
}

void Summon::execute(Engine&) {
    sprite.shift += direction * 1;
}

void Summon::when_done(Engine&) {
    sprite = original;
}