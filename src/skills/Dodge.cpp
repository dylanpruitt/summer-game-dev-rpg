#include "Dodge.h"
#include "statuses/dodgeStatus.h"

Dodge::Dodge()
{
    name = "Dodge";
    description = "Dodge the next physical attack you take.";
    type = "status";
    energy_cost = 6;
}

Dodge::~Dodge()
{
    //dtor
}

void Dodge::use (Entity* user, std::vector<Entity*> targets) {
    Skill::use(user, targets);
    user->statuses.push_back(new dodgeStatus());
}
