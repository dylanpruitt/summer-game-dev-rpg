#include "entities/Goblin.h"
#include "skills/Attack.h"
#include "skills/Fire.h"
#include "utility.h"

Goblin::Goblin()
{
    name = "Goblin";
    health = 3;
    max_health = 3;

    attack = 2;
    defense = 1;
    magic_attack = 1;
    magic_defense = 0;

    level = 1;
    experience_points = 1;

    skills.push_back(new Attack());
    skills.push_back(new Fire());

    resistances.push_back("fire");
    weaknesses.push_back("ice");
}

Goblin::~Goblin()
{
    //dtor
}

void Goblin::fundraise_AI (Entity* player) {

}

void Goblin::AI (std::vector<Entity*> combatants) {
    const int ATTACK = 0, FIRE = 1;

    int target_index = target_random_enemy (combatants);
    std::vector <Entity*> targets;
    targets.push_back (combatants [target_index]);

    int random_number = utility::random_bounded (1,3);
    if (random_number < 3) {
        this->skills [ATTACK]->use (this, targets);
    } else {
        this->skills [FIRE]->use (this, targets);
    }
}

