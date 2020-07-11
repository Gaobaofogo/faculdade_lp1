#ifndef CLIENTE_H
#define CLIENTE_H

#include "Produto.hpp"

#include <string>
#include <vector>


class Cliente {
  public:
    float saldo;
    std::vector<Produto> sacola;

    Cliente(float _saldo);
    void compra(Produto novo_produto);
    void verSacola();
    void registro(int numero_do_cliente);
};

#endif
