#ifndef CUTBOX_HPP
#define CUTBOX_HPP

#include "figurageometrica.hpp"

class cutBox : public figurageometrica
{
    int x0; int x1;
    int y0; int y1;
    int z0; int z1;
public:
    cutBox(int x0, int x1, int y0, int y1, int z0, int z1);
    ~cutBox(){};
    void draw(Sculptor &t);
};

#endif // CUTBOX_HPP
