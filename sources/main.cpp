#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include "voxel.hpp"
#include "sculptor.hpp"
#include "figurageometrica.hpp"
#include "interpretador.hpp"

#include "putVoxel.hpp"
#include "cutVoxel.hpp"
#include "putBox.hpp"
#include "cutBox.hpp"
#include "putSphere.hpp"
#include "cutSphere.hpp"
#include "putEllipsoid.hpp"
#include "cutEllipsoid.hpp"

int main()
{
    Sculptor *dimensoes;

    interpretador vetor;
    vector<figurageometrica*> figura;

    figura = vetor.vetor("yoshi-02.txt"); // recebe o container que armazenou todos os processos que serão realizados

    dimensoes = new Sculptor(vetor.getdx(),vetor.getdy(), vetor.getdz()); //aloca a memória, recebendo as dimensões do desenho

    for (size_t x=0; x<figura.size();x++){ // cada processo recebe o método draw relacionado ao tipo de classe [putVoxel, cutVoxel, putBox...]
        figura[x] -> draw(*dimensoes);
    }

    dimensoes -> writeOFF((const char*)"yoshi-02.off"); //criação do arquivo .off

    for(size_t x=0; x<figura.size(); x++){ // liberando a memória
        delete figura[x];
    }

    return 0;
}
