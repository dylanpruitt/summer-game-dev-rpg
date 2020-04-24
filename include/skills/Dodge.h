#ifndef DODGE_H
#define DODGE_H
#include "Skill.h"

class Dodge : public Skill
{
    public:
        Dodge();
        virtual ~Dodge();

        void use (Entity* user, std::vector<Entity*> targets);
};

#endif // DODGE_H
