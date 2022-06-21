#ifndef PUTBOX_HPP
#define PUTBOX_HPP

#include "figurageometrica.hpp"

class putBox: public figurageometrica
{
    int x0; int x1;
    int y0; int y1;
    int z0; int z1;
public:
    putBox(int x0, int x1, int y0, int y1, int z0, int z1, float r, float g, float b, float a);
    void draw(Sculptor &t);
    ~putBox();

};

#endif // PUTBOX_HPP
