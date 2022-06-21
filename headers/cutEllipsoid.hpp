#ifndef CUTELLIPSOID_HPP
#define CUTELLIPSOID_HPP

#include "figurageometrica.hpp"

class cutEllipsoid: public figurageometrica
{
    int xcenter_; int ycenter_; int zcenter_; int rx_; int ry_; int rz_;

public:
    cutEllipsoid(int xcenter_, int ycenter_, int zcenter_, int rx_, int ry_, int rz_);
    void draw(Sculptor &t);
    ~cutEllipsoid(){};
};

#endif // CUTELLIPSOID_HPP
