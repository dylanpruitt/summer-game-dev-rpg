#include "iceShield.h"

iceShield::iceShield()
{
    name = "Ice Shield";
    description = "For the rest of the battle, makes the target resist ice attacks but weak to fire attacks.";
}

iceShield::~iceShield()
{
    //dtor
}

void iceShield::use (Entity* user, std::vector<Entity*> targets) {
    Item::use(user, targets);
    targets [0]->resistances.push_back ("ice");
    targets [0]->weaknesses.push_back ("fire");
}
