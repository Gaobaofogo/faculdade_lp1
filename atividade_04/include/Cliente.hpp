#ifndef CLIENTE_H
#define CLIENTE_H

#include <string>
#include <vector>


class Cliente {
  public:
    float saldo;
    std::vector<std::string> sacola;

    Cliente(float _saldo);
    void compra(std::string produto, float preco);
    void verSacola();
    void registro();
};

#endif
