#ifndef FORNECEDOR_HPP
#define FORNECEDOR_HPP

#include "Estabelecimento.hpp"

#include <vector>


class Fornecedor {
  private:
    std::vector<ProdutoFornecedor> produtos;
    void diminuiProdutos();

  public:
    Fornecedor(std::string nomeArquivo);
    void listarProdutos();
    void repassarProdutos(Estabelecimento estabelecimento);
};

#endif
