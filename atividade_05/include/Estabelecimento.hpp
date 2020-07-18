#ifndef ESTABELECIMENTO_HPP
#define ESTABELECIMENTO_HPP

#include "Produto.hpp"

#include <vector>
#include <string>


class Estabelecimento {
  public:
    std::string codigo;
    std::vector<Produto> produtos;
    std::string unidadeMedida;
    float preco;

    Estabelecimento();
    Estabelecimento(const std::string& caminho_arquivo_estoque);
    void listar();
    void venda(const std::string& codigo);
    Produto* buscaProduto(int codigo_produto);
    Produto* buscaProduto(std::string nome);
    void reabastecer(int codigo, int quantidade);
    void caixa();
};

#endif
