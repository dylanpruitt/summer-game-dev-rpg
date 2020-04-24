#include "entities/Entity.h"
#include "skills/Skill.h"
#include "textGraphics.h"
#include "utility.h"
#include <iostream>

Entity::Entity()
{
    //ctor
}

Entity::~Entity()
{
    //dtor
}

bool Entity::is_alive () {
    if (health > 0) {
        return true;
    } else {
        return false;
    }
}

bool Entity::has_status (std::string status_name) {
    for (int i = 0; i < statuses.size (); i++) {
        if (statuses [i]->name == status_name) {
            return true;
        }
    }

    return false;
}

void Entity::remove_status (std::string status_name) {
    for (int i = 0; i < statuses.size (); i++) {
        if (statuses [i]->name == status_name) {
            statuses.erase (statuses.begin () + i);
            return;
        }
    }
}

void Entity::damage (Entity* target, int amount, std::string type) {
    if (target->has_status("dodge")) {
        std::cout << target->name;
        textGraphics::changeTextColor (textGraphics::colors::LIGHT_YELLOW, textGraphics::colors::BLACK); std::cout << " dodged ";
        textGraphics::changeTextColor (textGraphics::colors::WHITE, textGraphics::colors::BLACK); std::cout << "the attack!" << std::endl;
        target->remove_status ("dodge");
    } else {
        int damage = amount + attack;

        if (target->is_weak_to (type)) {
            damage *= 1.5;
            textGraphics::changeTextColor (textGraphics::colors::LIGHT_RED, textGraphics::colors::BLACK); std::cout << "WEAK";
            textGraphics::changeTextColor (textGraphics::colors::WHITE, textGraphics::colors::BLACK); std::cout << "! ";
        } else {
            damage -= target->defense;
        }

        if (target->is_resistant_to (type)) {
            damage *= 0.5;
            textGraphics::changeTextColor (textGraphics::colors::LIGHT_YELLOW, textGraphics::colors::BLACK); std::cout << "RESIST";
            textGraphics::changeTextColor (textGraphics::colors::WHITE, textGraphics::colors::BLACK); std::cout << "! ";
        }

        if (damage > 0) {
            std::cout << target->name + " took ";
            textGraphics::changeTextColor (textGraphics::colors::LIGHT_RED, textGraphics::colors::BLACK); std::cout << damage;
            textGraphics::changeTextColor (textGraphics::colors::WHITE, textGraphics::colors::BLACK); std::cout << " damage!" << std::endl;
            target->health -= damage;
        } else {
            std::cout << target->name + " took no damage." << std::endl;
        }
    }
}

void Entity::damage_magic (Entity* target, int amount, std::string type) {
    int damage = amount + magic_attack;

    if (target->is_weak_to (type)) {
        damage *= 1.5;
        textGraphics::changeTextColor (textGraphics::colors::LIGHT_RED, textGraphics::colors::BLACK); std::cout << "WEAK";
        textGraphics::changeTextColor (textGraphics::colors::WHITE, textGraphics::colors::BLACK); std::cout << "! ";
    } else {
        damage -= target->magic_defense;
    }

    if (target->is_resistant_to (type)) {
        damage *= 0.5;
        textGraphics::changeTextColor (textGraphics::colors::LIGHT_YELLOW, textGraphics::colors::BLACK); std::cout << "RESIST";
        textGraphics::changeTextColor (textGraphics::colors::WHITE, textGraphics::colors::BLACK); std::cout << "! ";
    }

    if (damage > 0) {
        std::cout << target->name + " took ";
        textGraphics::changeTextColor (textGraphics::colors::LIGHT_RED, textGraphics::colors::BLACK); std::cout << damage;
        textGraphics::changeTextColor (textGraphics::colors::WHITE, textGraphics::colors::BLACK); std::cout << " damage!" << std::endl;
        target->health -= damage;
    } else {
        std::cout << target->name + " took no damage." << std::endl;
    }
}

bool Entity::is_weak_to (std::string type) {
    for (unsigned int i = 0; i < weaknesses.size (); i++) {
        if (type == weaknesses [i]) {
            return true;
        }
    }
    return false;
}

bool Entity::is_resistant_to (std::string type) {
    for (unsigned int i = 0; i < resistances.size (); i++) {
        if (type == resistances [i]) {
            return true;
        }
    }
    return false;
}

void Entity::print_info () {
    std::cout << name << " (" << health << "/" << max_health << ")" << std::endl;
    std::cout << "ATTACK  " << attack << "\nDEFENSE " << defense << "\nMAGIC   " << magic_attack << "\nMAG.DEF " << magic_defense << std::endl;

    std::cout << "SKILLS:" << std::endl;
        for (unsigned int i = 0; i < skills.size (); i++) {
            std::cout << " - " << skills [i]->name << ": " << skills [i]->description << std::endl;
        }
    std::cout << "RESISTANCES:" << std::endl;
        for (unsigned int i = 0; i < resistances.size (); i++) {
            std::cout << " - " << resistances [i] << std::endl;
        }
    std::cout << "WEAKNESSES:" << std::endl;
        for (unsigned int i = 0; i < weaknesses.size (); i++) {
            std::cout << " - " << weaknesses [i] << std::endl;
        }
}

std::vector <Entity*> Entity::find_targets (std::vector <Entity*> combatants, int number_of_targets) {
    std::vector <Entity*> targets;
    std::vector <int> valid_target_indices;

    for (unsigned int j = 0; j < combatants.size (); j++) {
        if (combatants [j]->is_alive ()) {
            valid_target_indices.push_back (j);
        }
    }

    while (targets.size () < number_of_targets) {
        int target_index = get_player_target (combatants);
        targets.push_back (combatants [target_index]);
    }

    return targets;
}

int Entity::get_player_target (std::vector <Entity*> combatants) {
    std::vector <int> valid_target_indices;
    unsigned int target_index = 0;

    for (unsigned int j = 0; j < combatants.size (); j++) {
        if (combatants [j]->is_alive ()) {
            valid_target_indices.push_back (j);
        }
    }

    if (valid_target_indices.size () > 1) {
        std::cout << "Choose a target:" << std::endl;
        for (unsigned int j = 0; j < valid_target_indices.size (); j++) {
            std::cout << "[";
            textGraphics::changeTextColor (textGraphics::colors::RED, textGraphics::colors::BLACK); std::cout << j;
            textGraphics::changeTextColor (textGraphics::colors::WHITE, textGraphics::colors::BLACK);
            std::cout << "] - " << combatants [valid_target_indices [j]]->name << " (";
            textGraphics::changeTextColor (textGraphics::colors::AQUA, textGraphics::colors::BLACK); std::cout << combatants [valid_target_indices [j]]->health;
            textGraphics::changeTextColor (textGraphics::colors::WHITE, textGraphics::colors::BLACK); std::cout << " HP): ";
            std::cout << combatants [valid_target_indices [j]]->faction << std::endl;
        }

        bool index_is_valid = false;

        while (!index_is_valid) {
            target_index = utility::integer_input ();
            if (target_index >= 0 && target_index < valid_target_indices.size ()) {
                index_is_valid = true;
            }
        }
    }

    return valid_target_indices [target_index];
}


void Entity::AI (std::vector <Entity*> combatants) {
    textGraphics::changeTextColor (textGraphics::colors::LIGHT_RED, textGraphics::colors::BLACK); std::cout << "[!] " << name << " AI not implemented!";
    textGraphics::changeTextColor (textGraphics::colors::WHITE, textGraphics::colors::BLACK);
}

void Entity::fundraise_AI (Entity* player) {

}

int Entity::target_lowest_health_enemy (std::vector <Entity*> combatants) {
    int lowest_health_value = 100;
    int target_index = 0;

    for (int i = 0; i < combatants.size (); i++) {
        if (!(combatants [i]->faction == faction)) {
            if (combatants [i]->health < lowest_health_value && combatants [i]->health > 0) {
                lowest_health_value = combatants [i]->health;
                target_index = i;
            }
        }
    }

    return target_index;
}

int Entity::target_highest_health_enemy (std::vector <Entity*> combatants) {
    int highest_health_value = 0;
    int target_index = 0;

    for (int i = 0; i < combatants.size (); i++) {
        if (!(combatants [i]->faction == faction)) {
            if (combatants [i]->health > highest_health_value) {
                highest_health_value = combatants [i]->health;
                target_index = i;
            }
        }
    }

    return target_index;
}

int Entity::target_random_enemy (std::vector <Entity*> combatants) {
    std::vector <int> valid_indices;

    for (int i = 0; i < combatants.size (); i++) {
        if (!(combatants [i]->faction == faction) && combatants [i]->is_alive ()) {
            valid_indices.push_back (i);
        }
    }

    int random_index = 0;

    if (valid_indices.size () > 1) {
        random_index = rand () % valid_indices.size ();
    }

    return valid_indices [random_index];
}
