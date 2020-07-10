#ifndef ESTABELECIMENTO_H
#define ESTABELECIMENTO_H

#include "Produto.hpp"

#include <vector>
#include <string>


class Estabelecimento {
  public:
    std::string codigo;
    std::vector<Produto> produtos;
    std::string unidadeMedida;
    float preco;

    Estabelecimento(const std::string& caminho_arquivo_estoque);
    void listar();
    void venda(const std::string& codigo);
    void caixa();
};

#endif
