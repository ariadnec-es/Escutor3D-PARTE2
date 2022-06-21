#ifndef CUTVOXEL_HPP
#define CUTVOXEL_HPP

#include "figurageometrica.hpp"

class cutVoxel: public figurageometrica
{
    int x; int y; int z;

public:
        cutVoxel(int x, int y, int z);
        ~cutVoxel(){};
        void draw(Sculptor &t);
};

#endif // CUTVOXEL_HPP
