#include "Fornecedor.hpp"

#include <fstream>
#include <iostream>


Fornecedor::Fornecedor(std::string nomeArquivo) {
  std::ifstream arquivo_leitura(nomeArquivo);

  if (arquivo_leitura.fail()) {
    std::cout << "Arquivo " << nomeArquivo << "não encontrado." << std::endl;
    return;
  }

  std::string linha;
  std::nome;
  int quantidade;

  while (std::getline(arquivo_leitura, linha)) {
    nome = linha.substr(0, linha.find(','));

    linha.erase(0, linha.find(',') + 1);

    quantidade = std::atoi(linha);

    ProdutoFornecedor novoProduto(nome, quantidade);

    this->produtos.push_back(novoProduto);
  }

  void listarProdutos() {
    for (auto it = this->produtos.begin(); it != this->produtos.end(); ++it) {
      std::cout << "Nome: " << it->nome " - Quantidade: " << it->quantidade;
      std::cout << std::endl;
    }
  }

  void repassarProdutos(Estabelecimento estabelecimento) {

      if (produtoEncontrado != nullptr) {
        ProdutoFornecedor->quantidade += it->quantidade;
      }
}
