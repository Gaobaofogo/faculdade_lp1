#include "Fornecedor.hpp"

#include <fstream>
#include <iostream>

Fornecedor::Fornecedor() {
  std::ifstream arquivo_leitura("fornecedor.csv");

  if (arquivo_leitura.fail()) {
    std::cout << "Arquivo 'fornecedor.csv' não encontrado." << std::endl;
    return;
  }

  std::string linha;
  std::string nome;
  int quantidade;

  std::getline(arquivo_leitura, linha);

  while (std::getline(arquivo_leitura, linha) && linha.size()) {
    nome = linha.substr(0, linha.find(','));

    linha.erase(0, linha.find(',') + 1);

    quantidade = std::atoi(linha.c_str());

    ProdutoFornecedor novoProduto(nome, quantidade);

    this->produtos.push_back(novoProduto);
  }
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

  std::getline(arquivo_leitura, linha);

  while (std::getline(arquivo_leitura, linha) && linha.size()) {
    nome = linha.substr(0, linha.find(','));

    linha.erase(0, linha.find(',') + 1);

    quantidade = std::atoi(linha.c_str());

    ProdutoFornecedor novoProduto(nome, quantidade);

    this->produtos.push_back(novoProduto);
  }
}

Fornecedor::~Fornecedor() {
  std::ofstream arquivo_escrita("fornecedor.csv");

  arquivo_escrita << "PRODUTO,QUANTIDADE" << std::endl;

  for (auto it = this->produtos.begin(); it != this->produtos.end(); ++it) {
    if (it->nome != "") {
      arquivo_escrita << it->nome << "," << it->qntd << std::endl;
    }
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

