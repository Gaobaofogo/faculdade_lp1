#include "Estabelecimento.hpp"
#include "Produto.hpp"
#include "vector_supermercado.hpp"

#include <fstream>
#include <iostream>
#include <map>
#include <vector>

Estabelecimento::Estabelecimento() {
  std::ifstream arquivo_estoque("estoque.csv");
  std::string linha;

  if (arquivo_estoque.fail()) {
    std::cerr << "Arquivo não encontrado" << std::endl;
    exit(1);
  }

  bool primeira_linha = true;
  vector_supermercado<Produto> produtos;

  while (std::getline(arquivo_estoque, linha)) {
    if (primeira_linha) {
      primeira_linha = false;
      continue;
    }

    vector_supermercado<std::string> produto;
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

Estabelecimento::Estabelecimento(const std::string& caminho_arquivo_estoque) {
  std::ifstream arquivo_estoque(caminho_arquivo_estoque);
  std::string linha;

  if (arquivo_estoque.fail()) {
    std::cerr << "Arquivo não encontrado" << std::endl;
    exit(1);
  }

  bool primeira_linha = true;
  vector_supermercado<Produto> produtos;

  while (std::getline(arquivo_estoque, linha)) {
    if (primeira_linha) {
      primeira_linha = false;
      continue;
    }

    vector_supermercado<std::string> produto;
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
void Estabelecimento::venda(const std::string& codigo) {
  vector_supermercado<std::map<std::string, std::string>> vendas = this->leituraDoEstoque();
  bool naoEncontrouProduto = true;

  for (size_t i = 0; i < vendas.size(); ++i) {
    if (vendas[i]["CÓDIGO"] == codigo) {
      naoEncontrouProduto = false;
      int quantidade_vendida = std::stoi(vendas[i]["QUANTIDADE_VENDIDA"]) + 1;
      float total_ganho = std::stof(vendas[i]["TOTAL_GANHO"]) + std::stof(vendas[i]["PREÇO"]);

      vendas[i]["QUANTIDADE_VENDIDA"] = std::to_string(quantidade_vendida);
      vendas[i]["TOTAL_GANHO"] += std::to_string(total_ganho);
    }
  }

  if (naoEncontrouProduto) {
    std::map<std::string, std::string> venda;
    int codigo_para_pesquisa = std::stoi(codigo);

    Produto* produtoEmEstoque = this->buscaProduto(codigo_para_pesquisa);

    venda["CÓDIGO"] = std::to_string(produtoEmEstoque->codigo);
    venda["NOME"] = produtoEmEstoque->nome;
    venda["PREÇO"] = std::to_string(produtoEmEstoque->preco);
    venda["QUANTIDADE_VENDIDA"] = "1";
    venda["TOTAL_GANHO"] = std::to_string(produtoEmEstoque->preco);

    vendas.push_back(venda);
  }

  this->escreveCaixaNoDisco(vendas);
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

void Estabelecimento::reabastecer(int codigo, int quantidade) {
  for (auto it = this->produtos.begin(); it != this->produtos.end(); ++it) {
    if (it->codigo == codigo) {
      it->quantidade += quantidade;
      break;
    }
  }
}
void extraiVendaDaLinha(std::string& linha, std::map<std::string, std::string>& dadosDaVenda) {
  dadosDaVenda["CÓDIGO"] = linha.substr(0, linha.find(","));
  linha.erase(0, linha.find(",") + 1);

  dadosDaVenda["NOME"] = linha.substr(0, linha.find(","));
  linha.erase(0, linha.find(",") + 1);

  dadosDaVenda["PREÇO"] = linha.substr(0, linha.find(","));
  linha.erase(0, linha.find(",") + 1);

  dadosDaVenda["QUANTIDADE_VENDIDA"] = linha.substr(0, linha.find(","));
  linha.erase(0, linha.find(",") + 1);

  dadosDaVenda["TOTAL_GANHO"] = linha;
}

vector_supermercado<std::map<std::string, std::string>> Estabelecimento::leituraDoEstoque() {
  std::fstream arquivo_leitura("estoque.csv");
  vector_supermercado<std::map<std::string, std::string>> produtosVendidos;

  if (!arquivo_leitura.fail()) {
    std::string linha;

    std::getline(arquivo_leitura, linha);
    std::map<std::string, std::string> venda;

    while (std::getline(arquivo_leitura, linha)) {
      extraiVendaDaLinha(linha, venda);

      produtosVendidos.push_back(venda);
    }
  }

  return produtosVendidos;
}

void Estabelecimento::escreveCaixaNoDisco(const vector_supermercado<std::map<std::string, std::string>>& vendas) {
  std::ofstream arquivoCaixa("caixa.csv");

  arquivoCaixa << "CÓDIGO,NOME,PREÇO,QUANTIDE_VENDIDA,TOTAL_GANHO" << std::endl;

  for (size_t i = 0; i < vendas.size(); ++i) {
    std::cout << vendas[i]["CÓDIGO"] << ",";
    std::cout << vendas[i]["NOME"] << ",";
    std::cout << vendas[i]["PREÇO"] << ",";
    std::cout << vendas[i]["QUANTIDADE_VENDIDA"] << ",";
    std::cout << vendas[i]["TOTAL_GANHO"] << std::endl;
  }

  arquivoCaixa.close();
}

