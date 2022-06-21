#ifndef INTERPRETADOR_HPP
#define INTERPRETADOR_HPP

#include <vector>
#include <string>

#include "figurageometrica.hpp"

using namespace std;

class interpretador
{
    int dx, dy,dz;
    float r,g,b,a;
public:
    interpretador();
    ~interpretador(){};

    //ponteiros em conteiner para a classe abstrata figurageometrica, com leitura do arquivo
    vector<figurageometrica*> vetor (string filemane);
    //retorna os valores das dimensões
    int getdx();
    int getdy();
    int getdz();

};

#endif // INTERPRETADOR_HPP
