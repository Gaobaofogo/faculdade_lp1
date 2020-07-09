#ifndef ESTABELECIMENTO_H
#define ESTABELECIMENTO_H

#include <string>


class Estabelecimento {
  public:
    std::string codigo;
    std::string produto;
    std::string unidadeMedida;
    float preco;

    void listar();
    void venda(const std::string& codigo);
    void caixa();
};

#endif
