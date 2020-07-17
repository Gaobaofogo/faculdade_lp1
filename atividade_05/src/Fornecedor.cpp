#include "Fornecedor.hpp"

#include <fstream>
#include <iostream>

Fornecedor::Fornecedor() {
  Fornecedor("fornecedor.csv");
}

Fornecedor::Fornecedor(std::string nomeArquivo) {
  std::ifstream arquivo_leitura(nomeArquivo);

  if (arquivo_leitura.fail()) {
    std::cout << "Arquivo " << nomeArquivo << "não encontrado." << std::endl;
    return;
  }

  std::string linha;
  std::string nome;
  int quantidade;

  while (std::getline(arquivo_leitura, linha) && linha.size()) {
    nome = linha.substr(0, linha.find(','));

    linha.erase(0, linha.find(',') + 1);

    quantidade = std::atoi(linha.c_str());

    ProdutoFornecedor novoProduto(nome, quantidade);

    this->produtos.push_back(novoProduto);
  }

}
void Fornecedor::listarProdutos() {
  for (auto it = this->produtos.begin(); it != this->produtos.end(); ++it) {
    std::cout << "Nome: " << it->nome << " - Quantidade: " << it->qntd;
    std::cout << std::endl;
  }
}

bool Fornecedor::repassarProdutos(Estabelecimento estabelecimento, std::string nomeProduto, int quantidade) {
  for (auto it = this->produtos.begin(); it != this->produtos.end(); ++it) {
    if (it->nome == nomeProduto && it->qntd - quantidade > 0) {
      it->qntd -= quantidade;
      return true;
    }
  }

  return false;
}

