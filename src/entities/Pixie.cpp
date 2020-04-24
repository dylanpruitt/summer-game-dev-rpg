#include "entities/Pixie.h"
#include "skills/Skill.h"
#include "skills/Attack.h"
#include "utility.h"

Pixie::Pixie()
{
    name = "Pixie";
    health = 4;
    max_health = 4;

    attack = 1;
    defense = 1;
    magic_attack = 2;
    magic_defense = 1;

    level = 1;
    experience_points = 2;

    skills.push_back(new Attack());

    resistances.push_back("fire");
}

Pixie::~Pixie()
{
    //dtor
}

void Pixie::fundraise_AI (Entity* player) {

}

void Pixie::AI (std::vector<Entity*> combatants) {
    const int ATTACK = 0;

    int target_index = target_random_enemy (combatants);
    std::vector <Entity*> targets;
    targets.push_back (combatants [target_index]);

    this->skills [ATTACK]->use (this, targets);
}
