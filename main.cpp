#include <iostream>
#include <random>
#include "Game.h"
#include "entities/Pixie.h"
#include "items/Fireworks.h"
#include "skills/useItem.h"
#include "utility.h"

int main()
{
    Game g;
    Pixie pix; pix.faction = "player"; pix.skills.push_back (new useItem()); pix.items.push_back(new Fireworks());  pix.items.push_back(new Fireworks()); std::vector<Entity*> p; p.push_back(&pix);
    Pixie pixo; std::vector<Entity*> q; q.push_back(&pixo);
    g.battle(p,q);

    return 0;
}
