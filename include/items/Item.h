#ifndef ITEM_H
#define ITEM_H
#include <vector>
#include "Entity.h"

class Item
{
    public:
        Item();
        virtual ~Item();

        std::string name;
        std::string description;

        virtual void use (Entity* user, std::vector <Entity*> targets);
    protected:

    private:
};

#endif // ITEM_H
