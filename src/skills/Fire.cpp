#include "Fire.h"

Fire::Fire()
{
    name = "Fire";
    description = "Low damage fire attack. Targets 1 enemy.";
    type = "fire";
    energy_cost = 5;
}

Fire::~Fire()
{
    //dtor
}

void Fire::use (Entity *user, std::vector <Entity*> targets) {
    Skill::use (user, targets);
    const int BASE_DAMAGE = 1;

    if (user->faction == "player") {
        std::vector <Entity*> player_targets = user->find_targets (targets, 1);
        user->damage_magic (player_targets [0], BASE_DAMAGE, type);
    } else {
        user->damage_magic (targets [0], BASE_DAMAGE, type);
    }
}
