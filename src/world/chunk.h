#ifndef CHUNK_H
#define CHUNK_H

#include <iostream>

class chunk {
    public:
        chunk(char biome, int x, int y);

        char biome;
        int x_coord;
        int y_coord;


        friend std::ostream& operator<<(std::ostream& os, const chunk& obj) {
            os << obj.biome;
            return os;
        }

};

#endif // !CHUNK_H
