#ifndef GOBLIN_H
#define GOBLIN_H
#include "Entity.h"
#include <vector>

class Goblin : public Entity
{
    public:
        Goblin();
        virtual ~Goblin();

        void fundraise_AI (Entity* player);

        void AI (std::vector<Entity*> combatants);
    protected:

    private:
};

#endif // GOBLIN_H
