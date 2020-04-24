#include "skills/resistFire.h"

resistFire::resistFire()
{
    name = "Resist:Fire";
    description = "Makes the target resistant to fire damage.";
    type = "support";
    energy_cost = 5;
}

resistFire::~resistFire()
{
    //dtor
}

void resistFire::use (Entity *user, std::vector <Entity*> targets) {
    Skill::use (user, targets);

    if (user->faction == "player") {
        std::vector <Entity*> player_targets = find_targets (targets, 1);
        player_targets [0]->resistances.push_back ("fire");
    } else {
        targets [0]->resistances.push_back ("fire");
    }
}
