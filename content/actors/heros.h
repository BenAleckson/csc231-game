#pragma once

#include "CloseDoor.h"
#include "herotype.h"
#include "move.h"
#include "none.h"
#include "rest.h"

namespace Heros {
// REaction = std::function<std::unique_ptr<Action>()>
const std::unordered_map<std::string, Reaction> keybindings = {
    {"Left",
     []() {
         return std::make_unique<Move>(Vec{-1, 0});
     }},
    {"Right",
     []() {
         return std::make_unique<Move>(Vec{1, 0});
     }},
    {"Up",
     []() {
         return std::make_unique<Move>(Vec{0, 1});
     }},
    {"Down",
     []() {
         return std::make_unique<Move>(Vec{0, -1});
     }},
    {"Space", []() { return std::make_unique<Rest>(); }},
    {"C", []() { return std::make_unique<CloseDoor>(); }}};

constexpr int default_speed{8};
const HeroType nobody{
    "knight", default_speed, 1, std::make_shared<None>(), {keybindings}};

}  // namespace Heros
