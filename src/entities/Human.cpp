#include "Human.h"
#include "skills/Attack.h"
#include "skills/useItem.h"

Human::Human()
{
    name = "Human";
    health = 8;
    max_health = 8;

    attack = 2;
    defense = 1;
    magic_attack = 1;
    magic_defense = 1;

    level = 0;
    experience_points = 0;

    skills.push_back(new Attack());
    skills.push_back(new useItem());
}

Human::~Human()
{
    //dtor
}
