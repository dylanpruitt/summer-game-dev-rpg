#include "skills/Skill.h"
#include "utility.h"
#include <iostream>

Skill::Skill()
{
    //ctor
}

Skill::~Skill()
{
    //dtor
}

void Skill::use (Entity* user, std::vector <Entity*> targets) {
    std::cout << user->name << " used " << name << "!" << std::endl;
    user->energy -= energy_cost;
}
