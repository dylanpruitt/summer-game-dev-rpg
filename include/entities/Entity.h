#ifndef ENTITY_H
#define ENTITY_H
#include <vector>
#include <string>
#include <random>
#include "statuses/Status.h"

class Skill;

class Entity
{
    public:
        Entity();
        virtual ~Entity();

        std::string name;
        std::string faction = "enemy";

        int health = 14;
        int max_health = 14;

        int energy = 5;
        int max_energy = 10;

        int attack = 1;
        int defense = 1;

        int magic_attack = 1;
        int magic_defense = 1;

        int base_attack = 1;
        int base_defense = 1;

        int base_magic_attack = 1;
        int base_magic_defense = 1;

        int level = 0;
        int experience_points = 0;

        int gold = 0;

        std::vector <Skill*> skills;

        std::vector <Status*> statuses;

        std::vector <std::string> resistances;
        std::vector <std::string> weaknesses;

        bool is_alive ();

        bool has_status (std::string status_name);

        void remove_status (std::string status_name);

        bool is_weak_to (std::string type);

        bool is_resistant_to (std::string type);

        void damage (Entity* target, int amount, std::string type);

        void damage_magic (Entity* target, int amount, std::string type);

        virtual void AI (std::vector <Entity*> combatants);

        virtual void fundraise_AI (Entity* player);

        void print_info ();
    protected:
        int target_lowest_health_enemy (std::vector <Entity*> combatants);

        int target_highest_health_enemy (std::vector <Entity*> combatants);

        int target_random_enemy (std::vector <Entity*> combatants);

};

#endif // ENTITY_H
