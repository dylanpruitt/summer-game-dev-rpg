#ifndef PIXIE_H
#define PIXIE_H
#include "Entity.h"
#include <vector>

class Pixie: public Entity
{
    public:
        Pixie();
        virtual ~Pixie();

        void fundraise_AI (Entity* player);

        void AI (std::vector<Entity*> combatants);
    protected:

    private:
};

#endif // PIXIE_H
