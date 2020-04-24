#ifndef USEITEM_H
#define USEITEM_H
#include "Skill.h"

class useItem : public Skill
{
    public:
        useItem();
        virtual ~useItem();

        void use(Entity* user, std::vector<Entity*> targets);
    private:
        int return_used_item_index(Entity* user);
};

#endif // USEITEM_H
