#include "Item.h"
#include <iostream>

Item::Item()
{
    //ctor
}

Item::~Item()
{
    //dtor
}

void Item::use (Entity* user, std::vector <Entity*> targets) {
    std::cout << user->name << " used " << name << "!" << std::endl;
}
