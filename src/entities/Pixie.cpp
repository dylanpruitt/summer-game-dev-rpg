#include "entities/Pixie.h"
#include "skills/Attack.h"
#include "skills/Ice.h"
#include "utility.h"

Pixie::Pixie()
{
    name = "Pixie";
    health = 2;
    max_health = 2;

    attack = 1;
    defense = 1;
    magic_attack = 2;
    magic_defense = 1;

    level = 1;
    experience_points = 1;

    skills.push_back(new Attack());
    skills.push_back(new Ice());

    resistances.push_back("ice");
}

Pixie::~Pixie()
{
    //dtor
}

void Pixie::fundraise_AI (Entity* player) {

}

void Pixie::AI (std::vector<Entity*> combatants) {
    const int ATTACK = 0, ICE = 1;

    int target_index = target_random_enemy (combatants);
    std::vector <Entity*> targets;
    targets.push_back (combatants [target_index]);

    int random_number = utility::random_bounded (1,3);
    if (random_number < 3) {
        this->skills [ATTACK]->use (this, targets);
    } else {
        this->skills [ICE]->use (this, targets);
    }
}
