#include "Attack.h"

Attack::Attack()
{
    name = "Attack";
    description = "A basic physical attack. Targets 1 enemy.";
    type = "physical";
    energy_cost = 3;
}

Attack::~Attack()
{
    //dtor
}

void Attack::use (Entity *user, std::vector <Entity*> targets) {
    const int BASE_DAMAGE = 1;
    Skill::use (user, targets);

    if (user->faction == "player") {
        std::vector <Entity*> player_targets = user->find_targets (targets, 1);
        user->damage (player_targets [0], BASE_DAMAGE, type);
    } else {
        user->damage (targets [0], BASE_DAMAGE, type);
    }
}
