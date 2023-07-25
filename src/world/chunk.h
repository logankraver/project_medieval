#ifndef CHUNK_H
#define CHUNK_H

#include <iostream>
#include <map>
#include <string>

class chunk {
    public:
        chunk(char biome, int x, int y);

        char biome;
        int x_coord;
        int y_coord;


        void print(std::map<std::string, int> color_map, bool selected = false);


        friend std::ostream& operator<<(std::ostream& os, const chunk& obj) {
            os << obj.biome;
            return os;
        }

};

#endif // !CHUNK_H
