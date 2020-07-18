#ifndef PRODUTOFORNECEDOR_HPP
#define PRODUTOFORNECEDOR_HPP

#include <string>

struct ProdutoFornecedor {
  std::string nome;
  int qntd;

  ProdutoFornecedor() {
    nome = "";
    qntd = 0;
  }

  ProdutoFornecedor(std::string _nome, int _qntd) {
    nome = _nome;
    qntd = _qntd;
  }
};

#endif
