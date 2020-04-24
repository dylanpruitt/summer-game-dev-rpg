#ifndef RESISTFIRE_H
#define RESISTFIRE_H
#include "Skill.h"

class resistFire : public Skill
{
    public:
        resistFire();
        virtual ~resistFire();

        void use (Entity* user, std::vector <Entity*> combatants);
};

#endif // RESISTFIRE_H
