#include "chunk.h"
#include <ncurses.h>

chunk::chunk(char biome, int x, int y) : biome(biome), x_coord(x), y_coord(y) {

}


void chunk::print(std::map<std::string, int> color_map, bool selected) {
    int color;
    if (selected) {
        if (biome == '0') {
            color = color_map["BLUE_SELECT"];
        } else if (biome == '1') {
            color = color_map["GREEN_SELECT"];
        }
    } else {
        if (biome == '0') {
            color = color_map["BLUE"];
        } else if (biome == '1') {
            color = color_map["GREEN"];
        }
    }
    attron(color);
    printw("%c", biome);
    attroff(color);
}


