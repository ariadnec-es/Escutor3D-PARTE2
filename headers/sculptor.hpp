#ifndef SCULPTOR_H
#define SCULPTOR_H

#include "voxel.hpp"

class Sculptor {
protected:
  Voxel ***v; // ponteiro para ponteiro para ponteiro do tipo struct Voxel

  int nx,ny,nz; // dimensões x,y e z da matriz
  float r,g,b,a; // define as cores vermelho, verde e azul para cada voxel, e transparencia
  float fix; //variável de valor fixo para auxilio da construção do arquivo .off

public:
  Sculptor(int _nx, int _ny, int _nz); //construtor responsável por iniciar classe
  ~Sculptor(); // destrutor da classe

  void setColor(float r, float g, float b, float alpha); // se refere a seleção de cor
  void putVoxel(int x, int y, int z); // se refere a ativação de um voxel em (x,y,z)
  void cutVoxel(int x, int y, int z); // se refere a desativação de um voxel em (x,y,z)

  int getx();
  int gety();
  int getz();

  void writeOFF(const char* filename);
};

#endif
