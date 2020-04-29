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
#include "tileMap.h"

int main()
{
    tileMap t; for (int i = 0; i < 9; i++) { t.tiles.push_back (new Tile()); } t.map_size = 3; t.tiles[1]->battle_fought = true; t.tiles[4]->battle_fought = true; t.render ();

    Game g;
    Human pix; pix.faction = "player"; std::vector<Entity*> p; p.push_back(&pix);
    std::vector<Entity*> q;

    bool item_looping = true;
    while (item_looping) {
        std::cout << "Your items: ";
        for (unsigned int i = 0; i < p[0]->items.size(); i++) {
            std::cout << p[0]->items[i]->name;
            if (i < p[0]->items.size() - 1) { std::cout << ", "; }
        }
        std::cout << "\n[0] Confirm selection\n[1] Add Herb\n[2] Add Fireworks\n[3] Add Ice Shield" << std::endl;

        int input = utility::integer_input();

        switch(input) {
        case 0:
            item_looping = false;
            break;
        case 1:
            p[0]->items.push_back(new Herb());
            break;
        case 2:
            p[0]->items.push_back(new Fireworks());
            break;
        case 3:
            p[0]->items.push_back(new iceShield());
            break;
        }
    }
    bool entity_looping = true;
    while (entity_looping) {
        std::cout << "Enemies to battle: ";
        for (unsigned int i = 0; i < q.size(); i++) {
            std::cout << q[i]->name;
            if (i < q.size() - 1) { std::cout << ", "; }
        }
        std::cout << "\n[0] Confirm selection\n[1] Add Pixie\n[2] Add Goblin" << std::endl;

        int input = utility::integer_input();

        switch(input) {
        case 0:
            entity_looping = false;
            break;
        case 1:
            q.push_back(new Pixie());
            break;
        case 2:
            q.push_back(new Goblin());
            break;
        }
    }

    g.battle(p,q);
    int z;
    std::cin >> z;
    return 0;
}
