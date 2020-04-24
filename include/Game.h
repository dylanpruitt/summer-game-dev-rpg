#ifndef GAME_H
#define GAME_H
#include <vector>
#include "entities/Entity.h"

class Game
{
    public:
        Game();
        virtual ~Game();

        void battle (std::vector <Entity*> players, std::vector <Entity*> encounter);
    private:
        bool faction_members_remain (std::string faction, std::vector <Entity*> combatants);

        void display_combatant_information (std::vector <Entity*> players, std::vector <Entity*> encounter);

        void display_skills (Entity* player);
};

#endif // GAME_H
