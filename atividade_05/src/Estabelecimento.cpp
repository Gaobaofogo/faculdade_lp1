#include "Estabelecimento.hpp"
#include "Produto.hpp"

#include <fstream>
#include <iostream>
#include <vector>

Estabelecimento::Estabelecimento() {
  Estabelecimento("estoque.csv");
}

Estabelecimento::Estabelecimento(const std::string& caminho_arquivo_estoque) {
  std::ifstream arquivo_estoque(caminho_arquivo_estoque);
  std::string linha;

  if (arquivo_estoque.fail()) {
    std::cerr << "Arquivo não encontrado" << std::endl;
    exit(1);
  }

  bool primeira_linha = true;
  std::vector<Produto> produtos;

  while (std::getline(arquivo_estoque, linha)) {
    if (primeira_linha) {
      primeira_linha = false;
      continue;
    }

    std::vector<std::string> produto;
    std::string valor_do_produto;

    size_t posicao;

    do {

      posicao = linha.find(',');

      if (posicao == std::string::npos) {
        valor_do_produto = linha;
        produto.push_back(valor_do_produto);

        break;
      }

      valor_do_produto = linha.substr(0, posicao);
      produto.push_back(valor_do_produto);
      linha.erase(0, posicao + 1); // + 1 para descontar a vírgula

    } while (posicao != std::string::npos);

    Produto novo_produto(
        produto.at(0),
        produto.at(1),
        produto.at(2),
        produto.at(3) + "." + produto.at(4),
        produto.at(5)
        );
    produtos.push_back(novo_produto);
  }

  this->produtos = produtos;
}

void Estabelecimento::listar() {
  for (auto it = this->produtos.begin(); it != this->produtos.end(); ++it) {
    std::cout << "\t" << it->codigo << ")" << std::endl;
    std::cout << "\tNome: " << it->nome << std::endl;
    std::cout << "\tQuantidade: " << it->quantidade << std::endl;
    std::cout << "\tPreço: R$ " << it->preco << std::endl << std::endl;
  }
}

Produto* Estabelecimento::buscaProduto(int codigo_produto) {
  for (auto it = this->produtos.begin(); it != this->produtos.end(); ++it) {
    if (it->codigo == codigo_produto) {
      return &(*it);
    }
  }

  return nullptr;
}

Produto* Estabelecimento::buscaProduto(std::string nome) {
  for (auto it = this->produtos.begin(); it != this->produtos.end(); ++it) {
    if (it->nome == nome) {
      return &(*it);
    }
  }

  return nullptr;
}
