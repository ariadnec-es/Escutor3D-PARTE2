#ifndef PUTSPHERE_HPP
#define PUTSPHERE_HPP

#include "figurageometrica.hpp"

class putSphere: public figurageometrica
{
    int xcenter; int ycenter; int zcenter; int radius;
public:
    putSphere(int xcenter, int ycenter, int zcenter, int radius, float r, float g, float b, float a);
    void draw(Sculptor &t);
    ~putSphere(){};
};

#endif // PUTSPHERE_HPP
