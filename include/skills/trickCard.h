#ifndef TRICKCARD_H
#define TRICKCARD_H
#include "Skill.h"

class trickCard : public Skill
{
    public:
        trickCard();
        virtual ~trickCard();

        void use (Entity* user, std::vector <Entity*> combatants);
};

#endif // TRICKCARD_H
