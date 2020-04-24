#ifndef SKILL_H
#define SKILL_H
#include <string>
#include <vector>
#include "entities/Entity.h"
#include "textGraphics.h"

class Skill
{
    public:
        Skill();
        virtual ~Skill();

        std::string name;
        std::string description;

        std::string type;

        int energy_cost;

        virtual void use (Entity* user, std::vector <Entity*> targets);
    private:
};

#endif // SKILL_H
