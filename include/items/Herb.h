#ifndef HERB_H
#define HERB_H
#include "Item.h"

class Herb : public Item
{
    public:
        Herb();
        virtual ~Herb();

        void use (Entity* user, std::vector<Entity*> targets);
};

#endif // HERB_H
