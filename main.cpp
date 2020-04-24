#include <iostream>
#include <random>
#include "Game.h"
#include "entities/Pixie.h"
#include "utility.h"

int main()
{
    Game g;
    Pixie pix; pix.faction = "player"; std::vector<Entity*> p; p.push_back(&pix);
    Pixie pixo; std::vector<Entity*> q; q.push_back(&pixo);
    g.battle(p,q);

    return 0;
}
