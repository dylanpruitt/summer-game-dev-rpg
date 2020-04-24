#ifndef PIXIE_H
#define PIXIE_H
#include "Entity.h"

class Pixie: public Entity
{
    public:
        Pixie();
        virtual ~Pixie();

        void fundraise_AI (Entity* player);
    protected:

    private:
};

#endif // PIXIE_H
