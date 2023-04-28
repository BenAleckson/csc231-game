#include "engine.h"
#include "heros.h"
#include "monsters.h"

int main() {
    std::string filename{"settings.txt"};
    Settings settings = read_settings(filename);
    Engine engine{settings};

    for (int i{0}; i < 5; ++i) {
        engine.create_monster(Monsters::goblin());
        engine.create_monster(Monsters::zombie_big());
        engine.create_monster(Monsters::muddy());
    }

    engine.create_hero(Heros::nobody);
    engine.run();
}
