#include "Fireworks.h"
#include "utility.h"
#include <iostream>

Fireworks::Fireworks()
{
    name = "Fireworks";
    description = "Deals a small amount of fire damage 0-3 times to an enemy.";
}

Fireworks::~Fireworks()
{
    //dtor
}

void Fireworks::use (Entity* user, std::vector<Entity*> targets) {
    const int BASE_DAMAGE = 1;
    int number_of_attacks = utility::random_bounded(0, 3);

    for (int i = 0; i < number_of_attacks; i++) {
        user->damage_magic (targets [0], BASE_DAMAGE, "fire");
    }

    std::cout << "Hit " << number_of_attacks << " times!" << std::endl;
}
