#ifndef PUTELLIPSOID_HPP
#define PUTELLIPSOID_HPP

#include "figurageometrica.hpp"

class putEllipsoid: public figurageometrica
{
    int xcenter; int ycenter; int zcenter; int rx; int ry; int rz;
public:
    putEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz, float r, float g, float b, float a);
    void draw(Sculptor &t);
    ~putEllipsoid(){};
};

#endif // PUTELLIPSOID_HPP
