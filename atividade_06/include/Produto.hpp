#ifndef PRODUTO_H
#define PRODUTO_H

#include <string>


struct Produto {
  int codigo;
  std::string nome;
  std::string unidadeMedida;
  float preco;
  int quantidade;

  Produto();
  Produto(std::string _codigo, std::string _nome, std::string _unidadeMedida, std::string _preco, std::string _quantidade);
};

#endif
