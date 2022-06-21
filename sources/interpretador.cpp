#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

#include "putVoxel.hpp"
#include "cutVoxel.hpp"

#include "putBox.hpp"
#include "cutBox.hpp"

#include "putSphere.hpp"
#include "cutSphere.hpp"

#include "putEllipsoid.hpp"
#include "cutEllipsoid.hpp"

#include "interpretador.hpp"

using namespace std;

interpretador::interpretador()
{
}

vector<figurageometrica*> interpretador:: vetor (string filename){

    vector<figurageometrica*> figuras; // método para armazenamento das figuras
    ifstream arquivo;
    string stng,pp;
    stringstream ss;

    arquivo.open(filename.c_str());

    if(!arquivo.is_open()){
        exit(0);
    }

        while(getline(arquivo,stng)){

        ss.clear();
        ss.str(stng);
        ss >> pp;
        cout << pp << " ";

        if(pp.compare("dim")==0){
            ss >> dx >> dy >> dz;
        }
        else if(pp.compare("putvoxel")==0){
            int x_,y_,z_;
            ss >> x_ >> y_ >> z_ >> r >> g >> b >> a;
            figuras.push_back(new putVoxel(x_, y_, z_, r, g, b, a));
        }
        else if(pp.compare("cutvoxel")==0){
            int x_, y_, z_;
            ss >> x_ >> y_ >> z_;
            figuras.push_back(new cutVoxel(x_,y_,z_));
        }

        else if(pp.compare("putbox")==0){
            int x0; int x1; int y0; int y1; int z0; int z1;
            ss >> x0 >> x1 >> y0 >> y1 >> z0 >> z1 >> r >> g >> b >> a;
            //cout << x0<< x1 << y0 << y1 << z0 << z1 << r << g << b << a << endl;
            figuras.push_back(new putBox(x0,x1,y0, y1, z0,z1, r, g, b, a));
        }
        else if(pp.compare("cutbox")==0){
            int x0; int x1; int y0; int y1; int z0; int z1;
            ss >> x0 >> x1 >> y0 >> y1 >> z0 >> z1;
            figuras.push_back(new cutBox(x0,x1,y0, y1, z0,z1));
        }

        else if(pp.compare("putsphere")==0){
            int xcenter; int ycenter; int zcenter; int radius;
            ss >> xcenter >> ycenter >> zcenter >> radius >> r >> g >> b >> a;
            figuras.push_back(new putSphere(xcenter, ycenter, zcenter, radius, r, g, b, a));
        }
        else if(pp.compare("cutsphere")==0){
            int xcenter; int ycenter; int zcenter; int radius;
            ss >> xcenter >> ycenter >> zcenter >> radius;
            figuras.push_back(new cutSphere(xcenter, ycenter, zcenter, radius));
        }

        else if(pp.compare("putellipsoid")==0){
            int xcenter, ycenter, zcenter, rx, ry, rz;
            ss >> xcenter >> ycenter >> zcenter >> rx >> ry >> rz >> r >> g >> b >> a;
            figuras.push_back(new putEllipsoid(xcenter,ycenter,zcenter,rx,ry,rz, r, g, b, a));
        }
        else if(pp.compare("cutellipsoid")==0){
            int xcenter_, ycenter_, zcenter_, rx_, ry_, rz_;
            ss >> xcenter_ >> ycenter_ >> zcenter_ >> rx_ >> ry_ >> rz_;
            figuras.push_back(new cutEllipsoid(xcenter_,ycenter_,zcenter_,rx_,ry_,rz_));
        }
    }

    arquivo.close();
    return(figuras);
}

int interpretador::getdx(){
    return dx;
}

int interpretador::getdy(){
    return dy;
}

int interpretador::getdz(){
    return dz;
}
