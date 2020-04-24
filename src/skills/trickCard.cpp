#include "skills/trickCard.h"
#include <iostream>

trickCard::trickCard()
{
    name = "Trick Card";
    description = "Swap weaknesses with your enemy.";
    energy_cost = 5;
}

trickCard::~trickCard()
{
    //dtor
}

void trickCard::use (Entity *user, std::vector <Entity*> targets) {
    Skill::use (user, targets);

    if (user->faction == "player") {
        std::vector <Entity*> player_targets = find_targets (targets, 1);
        std::vector <std::string> temp_weaknesses = player_targets [0]->weaknesses;
        player_targets [0]->weaknesses = user->weaknesses;
        user->weaknesses = temp_weaknesses;
        std::cout << user->name << " swapped weaknesses with " << player_targets [0]->name << "!" << std::endl;
    } else {
        std::vector <std::string> temp_weaknesses = targets [0]->weaknesses;
        targets [0]->weaknesses = user->weaknesses;
        user->weaknesses = temp_weaknesses;
        std::cout << user->name << " swapped weaknesses with " << targets [0]->name << "!" << std::endl;
    }
}
