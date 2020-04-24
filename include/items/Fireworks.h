#ifndef FIREWORKS_H
#define FIREWORKS_H
#include "Item.h"

class Fireworks : public Item
{
    public:
        Fireworks();
        virtual ~Fireworks();

        void use (Entity* user, std::vector <Entity*> targets);
    protected:

    private:
};

#endif // FIREWORKS_H
