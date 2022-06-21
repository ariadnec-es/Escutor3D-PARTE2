#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <cmath>
#include <vector>

#include "sculptor.hpp"

using namespace std;

Sculptor::Sculptor(int _nx, int _ny, int _nz){ //construtor da classe Sculptor

    nx = _nx;
    ny = _ny;
    nz = _nz;
    fix = 0.5;
    r = 0.5;
    g = 0.5;
    b = 0.5;
    a = 0.5;

    v = new Voxel **[_nx];

    for(int i = 0; i < _nx; i++ ){

        v[i] = new Voxel *[_ny];
        for(int j = 0; j < _ny; j++){

            v[i][j] = new Voxel [_nz];
            for(int k = 0; k < _nz; k++){

                    this->v[i][j][k].r = 0.0;
                    this->v[i][j][k].g = 0.0;
                    this->v[i][j][k].b = 0.0;
                    this->v[i][j][k].a = 0.0;
                    this->v[i][j][k].isOn = false;
            }
        }
    }
}

// implementação do destrutor da classe Sculptor
Sculptor::~Sculptor(){

    for(int i = 0; i < nx; i++ ){

        for(int j = 0; j < ny; j++){

           delete[] v[i][j];
        }
        delete[] v[i];
    }
    delete[] v;

}

// definição das cores vermelho, verde e azul
void Sculptor::setColor(float r, float g, float b, float alpha){

    this->r = r;
    this->g = g;
    this->b = b;
    this->a = alpha;

}

//definição do método putVoxel
void Sculptor::putVoxel(int x, int y, int z){

    this->v[x][y][z].isOn = true;
    this->v[x][y][z].r = this->r;
    this->v[x][y][z].g = this->g;
    this->v[x][y][z].b = this->b;
    this->v[x][y][z].a = this->a;

}

//definição do método cutVoxel
void Sculptor::cutVoxel(int x, int y, int z){
    this->v[x][y][z].isOn = false;
}

int Sculptor::getx(){
    return nx;
}

int Sculptor::gety(){
    return nx;
}

int Sculptor::getz(){
    return nx;
}

// definição da função geradora de arquivo
void Sculptor::writeOFF(const char *filename)
{
    int quantvox = 0;
    int ref;
    ofstream arquivofinal;

    arquivofinal.open(filename);
    arquivofinal<<"OFF\n";

    // varre todos os voxel e analisa os que devem ser exibidos no .off
    for (int i = 0; i < nx; i++){
      for (int j = 0; j <ny; j++){
           for (int k = 0; k <nz; k++){
                if(v[i][j][k].isOn == true){
                quantvox++;
                }
           }
       }
    }
    arquivofinal<<quantvox * 8<<" "<<quantvox * 6 << " " << "0" << "\n"; // mostra a quantidade total de vertices, faces e arestas

    for (int a = 0; a < nx; a++){
      for (int b = 0; b < ny; b++){
           for (int c = 0; c < nz; c++){
                if(v[a][b][c].isOn == true){
                arquivofinal << a - fix << " " << b + fix << " " << c - fix << "\n" << flush;
                arquivofinal << a - fix << " " << b - fix << " " << c - fix << "\n" << flush;
                arquivofinal << a + fix << " " << b - fix << " " << c - fix << "\n" << flush;
                arquivofinal << a + fix << " " << b + fix << " " << c - fix << "\n" << flush;
                arquivofinal << a - fix << " " << b + fix << " " << c + fix << "\n" << flush;
                arquivofinal << a - fix << " " << b - fix << " " << c + fix << "\n" << flush;
                arquivofinal << a + fix << " " << b - fix << " " << c + fix << "\n" << flush;
                arquivofinal << a + fix << " " << b + fix << " " << c + fix << "\n" << flush;
                }
           }
      }
    }

    quantvox = 0;

    // descrever cada voxel
    for (int a= 0; a<nx; a++){
      for (int b = 0; b<ny; b++){
           for (int c= 0; c<nz; c++){
                if(v[a][b][c].isOn == true){
                ref = quantvox * 8;
                arquivofinal << fixed;

                // montar linha que realiza a construção das faces a partir do vertices e mostrar as propriedades rgba do voxel
                arquivofinal << "4" << " " << 0+ref << " " << 3+ref << " " << 2+ref << " " << 1+ref << " ";
                arquivofinal << setprecision(2)<<v[a][b][c].r << " " << setprecision(2)<<v[a][b][c].g <<" " << setprecision(2)<<v[a][b][c].b << " " << setprecision(2) << v[a][b][c].a << "\n";

                arquivofinal << "4" << " " << 4+ref << " " << 5+ref << " " << 6+ref << " " << 7+ref << " ";
                arquivofinal << setprecision(2)<<v[a][b][c].r << " " << setprecision(2)<<v[a][b][c].g <<" " << setprecision(2)<<v[a][b][c].b << " " << setprecision(2) << v[a][b][c].a << "\n";

                arquivofinal << "4" << " " << 0+ref << " " << 1+ref << " " << 5+ref << " " << 4+ref << " ";
                arquivofinal << setprecision(2)<<v[a][b][c].r << " " << setprecision(2)<<v[a][b][c].g <<" " << setprecision(2)<<v[a][b][c].b << " " << setprecision(2) << v[a][b][c].a << "\n";

                arquivofinal << "4" << " " << 0+ref << " " << 4+ref << " " << 7+ref << " " << 3+ref << " ";
                arquivofinal << setprecision(2)<<v[a][b][c].r << " " << setprecision(2)<<v[a][b][c].g <<" " << setprecision(2)<<v[a][b][c].b << " " << setprecision(2) << v[a][b][c].a << "\n";

                arquivofinal << "4" << " " << 3+ref << " " << 7+ref << " " << 6+ref << " " << 2+ref << " ";
                arquivofinal << setprecision(2)<<v[a][b][c].r << " " << setprecision(2)<<v[a][b][c].g <<" " << setprecision(2)<<v[a][b][c].b << " " << setprecision(2) << v[a][b][c].a << "\n";

                arquivofinal << "4" << " " << 1+ref << " " << 2+ref << " " << 6+ref << " " << 5+ref << " ";
                arquivofinal << setprecision(2)<<v[a][b][c].r << " " << setprecision(2)<<v[a][b][c].g <<" " << setprecision(2)<<v[a][b][c].b << " " << setprecision(2) << v[a][b][c].a << "\n";

                quantvox = quantvox + 1;
                }
           }
       }
    }
    arquivofinal.close();
}
