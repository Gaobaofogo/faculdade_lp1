#ifndef CARRO_H
#define CARRO_H

#include "Motor.hpp"

#include <string>


class Carro {
  public:
    std::string tipo;
    std::string placa;
    int numPortas;
    int velocidade;
    std::string cor;
    Motor motor;

    Carro(std::string cor);
    Carro();

    void acelera(int velocidade);
    void freia(int velocidade);
    void ligaCarro();
};

#endif
