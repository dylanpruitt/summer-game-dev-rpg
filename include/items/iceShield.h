#ifndef ICESHIELD_H
#define ICESHIELD_H
#include "Item.h"

class iceShield : public Item
{
    public:
        iceShield();
        virtual ~iceShield();

        void use(Entity* user, std::vector<Entity*> targets);
};

#endif // ICESHIELD_H
