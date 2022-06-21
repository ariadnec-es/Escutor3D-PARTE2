#include "cutVoxel.hpp"

cutVoxel::cutVoxel(int x, int y, int z){
    this->x=x;
    this->y=y;
    this->z=z;
}

void cutVoxel::draw(Sculptor &t){
    t.cutVoxel(x,y,z);
}
