#include "useItem.h"
#include "items/Item.h"
#include "utility.h"
#include <iostream>

useItem::useItem()
{
    name = "Use Item";
    description = "Use an item from your inventory.";
    energy_cost = 0;
}

useItem::~useItem()
{
    //dtor
}

void useItem::use (Entity *user, std::vector <Entity*> targets) {
    if (user->items.size() > 0) {
        const int BASE_DAMAGE = 1;
        Skill::use (user, targets);

        int item_index = return_used_item_index (user);
        std::vector <Entity*> player_targets = find_targets (targets, 1);

        user->items [item_index]->use (user, player_targets);
        user->items.erase (user->items.begin() + item_index);
    } else {
        std::cout << "No items to use!" << std::endl;
    }
}

int useItem::return_used_item_index (Entity* user) {
    bool looping = true; int index = 0;

    while (looping) {
        for (unsigned int i = 0; i < user->items.size(); i++) {
            std::cout << "[" << i << "] - " << user->items [i]->name << std::endl;
        }
        index = utility::integer_input ();
        if (index >= 0 && index < user->items.size ()) {
            looping = false;
        }
    }
    return index;
}
