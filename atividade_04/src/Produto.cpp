#include "Produto.hpp"


Produto::Produto(std::string _codigo, std::string _nome, std::string _unidadeMedida, std::string _preco, std::string _quantidade) {
  this->codigo = std::stoi(_codigo);
  this->nome = _nome;
  this->unidadeMedida =  _unidadeMedida;
  this->quantidade = std::stoi(_quantidade);

  _preco.erase(0, 3);
  _preco.erase(_preco.size() - 1, _preco.size());

  this->preco = std::stof(_preco);
}
