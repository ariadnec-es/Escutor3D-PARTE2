#ifndef PUTVOXEL_HPP
#define PUTVOXEL_HPP

#include "figurageometrica.hpp"
#include "sculptor.hpp"

class putVoxel: public figurageometrica
{
    int x,y,z;
public:
    putVoxel(int x, int y, int z, float r, float g, float b, float a);
    ~putVoxel(){};
    void draw(Sculptor &t);
};

#endif // PUTVOXEL_HPP
