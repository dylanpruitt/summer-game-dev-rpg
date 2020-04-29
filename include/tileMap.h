#ifndef TILEMAP_H
#define TILEMAP_H
#include <vector>
#include "tiles/Tile.h"

class tileMap
{
    public:
        tileMap();
        virtual ~tileMap();

        int map_size = 2;

        std::vector <Tile*> tiles;
        void render ();
    private:

};

#endif // TILEMAP_H
