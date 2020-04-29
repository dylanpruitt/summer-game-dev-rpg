#include "tileMap.h"
#include "textGraphics.h"
#include <iostream>

tileMap::tileMap()
{
    //ctor
}

tileMap::~tileMap()
{
    //dtor
}

void tileMap::render () {
    if (tiles.size () == map_size * map_size) {
        for (unsigned int i = 0; i < map_size; i++) {
            for (unsigned int j = 0; j < map_size; j++) {
                if (tiles [j + (map_size * i)]->battle_fought) {
                    textGraphics::changeTextColor (textGraphics::LIGHT_GREEN, textGraphics::BLACK);
                } else {
                    textGraphics::changeTextColor (textGraphics::LIGHT_RED, textGraphics::BLACK);
                }
                std::cout << tiles [j + (map_size * i)]->render_character;
            }
            textGraphics::changeTextColor (textGraphics::WHITE, textGraphics::BLACK);
            std::cout << "\n";
        }
    }
}
