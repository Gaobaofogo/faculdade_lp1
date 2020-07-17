#ifndef FORNECEDOR_HPP
#define FORNECEDOR_HPP

#include "Estabelecimento.hpp"
#include "ProdutoFornecedor.hpp"

#include <vector>


class Fornecedor {
  private:
    std::vector<ProdutoFornecedor> produtos;
    void diminuiProdutos();

  public:
    Fornecedor();
    Fornecedor(std::string nomeArquivo);
    void listarProdutos();
    bool repassarProdutos(Estabelecimento estabelecimento, std::string nomeProduto, int quantidade);
};

#endif
