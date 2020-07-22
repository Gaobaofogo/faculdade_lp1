#ifndef FORNECEDOR_HPP
#define FORNECEDOR_HPP

#include "Estabelecimento.hpp"
#include "ProdutoFornecedor.hpp"
#include "vector_supermercado.hpp"

#include <vector>


class Fornecedor {
  private:
    vector_supermercado<ProdutoFornecedor> produtos;
    void diminuiProdutos();

  public:
    Fornecedor();
    ~Fornecedor();
    Fornecedor(std::string nomeArquivo);
    void listarProdutos();
    bool repassarProdutos(Estabelecimento estabelecimento, std::string nomeProduto, int quantidade);
};

#endif
