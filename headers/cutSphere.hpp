#ifndef CUTSPHERE_HPP
#define CUTSPHERE_HPP

#include "figurageometrica.hpp"

class cutSphere: public figurageometrica
{
    int xcenter; int ycenter; int zcenter; int radius;
public:
    cutSphere(int xcenter, int ycenter, int zcenter, int radius);
    void draw(Sculptor &t);
    ~cutSphere(){};
};

#endif // CUTSPHERE_HPP
