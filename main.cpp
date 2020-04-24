#include <iostream>
#include <random>
#include "Game.h"
#include "entities/Pixie.h"
#include "entities/Goblin.h"
#include "entities/Human.h"
#include "items/Fireworks.h"
#include "items/Herb.h"
#include "items/iceShield.h"
#include "skills/useItem.h"
#include "skills/Dodge.h"
#include "utility.h"
#include "textGraphics.h"

int main()
{
    Game g;
    Human pix; pix.faction = "player"; pix.skills.push_back (new Dodge ()); pix.items.push_back(new Herb()); pix.items.push_back(new iceShield());  pix.items.push_back(new Fireworks()); std::vector<Entity*> p; p.push_back(&pix);
    std::vector<Entity*> q; q.push_back(new Pixie ()); q.push_back(new Pixie ()); q.push_back(new Goblin());
    g.battle(p,q);

    return 0;
}
