#ifndef MEGABLAZE_H
#define MEGABLAZE_H
#include "Skill.h"

class megaBlaze : public Skill
{
    public:
        megaBlaze();
        virtual ~megaBlaze();

        void use (Entity* user, std::vector <Entity*> combatants);
};

#endif // MEGABLAZE_H
