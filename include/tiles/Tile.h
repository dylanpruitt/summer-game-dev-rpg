#ifndef TILE_H
#define TILE_H
#include <vector>
#include "entities/Entity.h"

class Tile
{
    public:
        Tile();
        virtual ~Tile();

        char render_character = ',';

        std::string name;

        std::vector<Entity*> encounter;

        bool battle_fought = false;

    protected:

    private:
};

#endif // TILE_H
