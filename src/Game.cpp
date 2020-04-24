#include "Game.h"
#include "skills/Skill.h"
#include "textGraphics.h"
#include "utility.h"
#include <iostream>

Game::Game()
{
    //ctor
}

Game::~Game()
{
    //dtor
}

void Game::battle (std::vector <Entity*> players, std::vector <Entity*> encounter) {
    std::vector <Entity*> combatants;

    for (int i = 0; i < players.size (); i++) { combatants.push_back (players [i]); }
    for (int i = 0; i < encounter.size (); i++) { combatants.push_back (encounter [i]); }

    while (faction_members_remain ("player", combatants) && faction_members_remain ("enemy", combatants)) {
        for (int i = 0; i < players.size (); i++) {
            if (players [i]->is_alive () && faction_members_remain ("enemy", combatants)) {
                players [i]->energy += 3;
                if (players [i]->energy > players [i]->max_energy) {
                    players [i]->energy = players [i]->max_energy;
                }

                std::vector <Status*> remaining_statuses;
                for (int j = 0; j < players [i]->statuses.size (); j++) {
                    players [i]->statuses [j]->on_parent_turn (players [i]);
                    players [i]->statuses [j]->turns_left--;

                    if (players [i]->statuses [j]->turns_left > 0) {
                        remaining_statuses.push_back (players [i]->statuses [j]);
                    }
                }
                players [i]->statuses.swap (remaining_statuses);

                std::cout << "\n- - -- ==< " << players [i]->name << "'s turn >== -- - -" << std::endl;
                display_combatant_information (players, encounter);
                display_skills (players [i]);

                int skill_index = -1;
                bool looping = true;
                while (looping) {
                    skill_index = utility::integer_input ();
                    if (skill_index >= 0 && skill_index < players [i]->skills.size ()) {
                        if (players [i]->energy >= players [i]->skills [skill_index]->energy_cost) {
                            looping = false;
                        } else {
                            std::cout << "Not enough energy!" << std::endl;
                        }
                    }

                }

                players [i]->skills [skill_index]->use (players [i], combatants);

        }
        }

        for (int i = 0; i < encounter.size (); i++) {
            if (encounter [i]->is_alive ()) {
                encounter [i]->energy += 3;
                std::vector <Status*> remaining_statuses;
                for (int j = 0; j < encounter [i]->statuses.size (); j++) {
                    encounter [i]->statuses [j]->on_parent_turn (encounter [i]);
                    encounter [i]->statuses [j]->turns_left--;

                    if (encounter [i]->statuses [j]->turns_left > 0) {
                        remaining_statuses.push_back (encounter [i]->statuses [j]);
                    }
                }
                encounter [i]->statuses.swap (remaining_statuses);
                encounter [i]->AI (combatants);
            }
        }
    }

    if (faction_members_remain ("player", combatants)) {
        std::cout << "You won!" << std::endl;

        int experience_total = 0;
        for (int i = 0; i < encounter.size (); i++) {
            experience_total += encounter [i]->experience_points;
        }

        for (int i = 0; i < players.size (); i++) {
            players [i]->experience_points += experience_total;
            for (int j = 0; j < players [i]->statuses.size (); j++) {
                players [i]->statuses [j]->on_battle_end (players [i]);
            }
            players [i]->statuses.clear ();
        }
    }
}

bool Game::faction_members_remain (std::string faction, std::vector <Entity*> combatants) {
    bool members_alive = false;

    for (int i = 0; i < combatants.size (); i++) {
        if (combatants [i]->health > 0 && combatants [i]->faction == faction) { members_alive = true; }
    }

    return members_alive;
}

void Game::display_combatant_information (std::vector <Entity*> players, std::vector <Entity*> encounter) {
    for (int i = 0; i < players.size (); i++) {
        std::cout << players [i]->name << " (Health ";
        textGraphics::changeTextColor (textGraphics::colors::LIGHT_RED, textGraphics::colors::BLACK); std::cout << players [i]->health;
        textGraphics::changeTextColor (textGraphics::colors::WHITE, textGraphics::colors::BLACK); std::cout << " / ";
        textGraphics::changeTextColor (textGraphics::colors::LIGHT_RED, textGraphics::colors::BLACK); std::cout << players [i]->max_health;
        textGraphics::changeTextColor (textGraphics::colors::WHITE, textGraphics::colors::BLACK); std::cout << " Energy ";

        textGraphics::changeTextColor (textGraphics::colors::LIGHT_YELLOW, textGraphics::colors::BLACK); std::cout << players [i]->energy;
        textGraphics::changeTextColor (textGraphics::colors::WHITE, textGraphics::colors::BLACK); std::cout << " / ";
        textGraphics::changeTextColor (textGraphics::colors::LIGHT_YELLOW, textGraphics::colors::BLACK); std::cout << players [i]->max_energy;
        textGraphics::changeTextColor (textGraphics::colors::WHITE, textGraphics::colors::BLACK); std::cout << ")" << std::endl;
    }
    std::cout << "vs." << std::endl;
        for (int i = 0; i < encounter.size (); i++) {
        std::cout << encounter [i]->name << " (Health ";
        textGraphics::changeTextColor (textGraphics::colors::LIGHT_RED, textGraphics::colors::BLACK); std::cout << encounter [i]->health;
        textGraphics::changeTextColor (textGraphics::colors::WHITE, textGraphics::colors::BLACK); std::cout << " / ";
        textGraphics::changeTextColor (textGraphics::colors::LIGHT_RED, textGraphics::colors::BLACK); std::cout << encounter [i]->max_health;
        textGraphics::changeTextColor (textGraphics::colors::WHITE, textGraphics::colors::BLACK); std::cout << ")" << std::endl;
    }
}

void Game::display_skills (Entity* player) {
    std::cout << "Skills:" << std::endl;

    for (int j = 0; j < player->skills.size (); j++) {
        std::cout << "[";
        textGraphics::changeTextColor (textGraphics::colors::RED, textGraphics::colors::BLACK); std::cout << j;
        textGraphics::changeTextColor (textGraphics::colors::WHITE, textGraphics::colors::BLACK);
        std::cout << "] - " << player->skills [j]->name << " (";

        textGraphics::changeTextColor (textGraphics::colors::YELLOW, textGraphics::colors::BLACK);
        std::cout << player->skills [j]->energy_cost;
        textGraphics::changeTextColor (textGraphics::colors::WHITE, textGraphics::colors::BLACK);
        std::cout << ") : " << player->skills [j]->description << std::endl;
    }
}
