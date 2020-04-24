#ifndef ICE_H
#define ICE_H
#include "Skill.h"

class Ice : public Skill
{
    public:
        Ice();
        virtual ~Ice();

        void use (Entity* user, std::vector<Entity*> targets);
    protected:

    private:
};

#endif // ICE_H
