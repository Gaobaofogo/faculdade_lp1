#ifndef CLIENTE_HPP
#define CLIENTE_HPP

#include "Produto.hpp"
#include "vector_supermercado.hpp"

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
