#include "Herb.h"

Herb::Herb()
{
    name = "Herb";
    description = "Heals a small amount of health";
}

Herb::~Herb()
{
    //dtor
}

void Herb::use (Entity* user, std::vector <Entity*> targets) {
    Item::use(user, targets);
    targets [0]->health += 3;
    if (targets [0]->health > targets [0]->max_health) {
        targets [0]->health = targets [0]->max_health;
    }
}
