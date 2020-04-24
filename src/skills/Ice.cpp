#include "Ice.h"

Ice::Ice()
{
    name = "Ice";
    description = "Low damage ice attack. Targets 1 enemy.";
    type = "ice";
    energy_cost = 5;
}

Ice::~Ice()
{
    //dtor
}

void Ice::use (Entity *user, std::vector <Entity*> targets) {
    Skill::use (user, targets);
    const int BASE_DAMAGE = 1;

    if (user->faction == "player") {
        std::vector <Entity*> player_targets = user->find_targets (targets, 1);
        user->damage_magic (player_targets [0], BASE_DAMAGE, type);
    } else {
        user->damage_magic (targets [0], BASE_DAMAGE, type);
    }
}
