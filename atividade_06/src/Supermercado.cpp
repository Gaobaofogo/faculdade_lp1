#include "Supermercado.hpp"

#include <fstream>
#include <iostream>


Supermercado::Supermercado() {
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

void Supermercado::reabastecer(int codigo, int quantidade) {
  for (auto it = this->produtos.begin(); it != this->produtos.end(); ++it) {
    if (it->codigo == codigo) {
      it->quantidade += quantidade;
      break;
    }
  }
}

void Supermercado::listar() {
  for (auto it = this->produtos.begin(); it != this->produtos.end(); ++it) {
    std::cout << "\t" << it->codigo << ")" << std::endl;
    std::cout << "\tNome: " << it->nome << std::endl;
    std::cout << "\tQuantidade: " << it->quantidade << std::endl;
    std::cout << "\tPreço: R$ " << it->preco << std::endl << std::endl;
  }
}

void Supermercado::venda(int codigo) {
  vector_supermercado<std::map<std::string, std::string>> vendas = this->leituraDoEstoque();
  bool naoEncontrouProduto = true;

  for (size_t i = 0; i < vendas.size(); ++i) {
    if (vendas[i]["CÓDIGO"] == std::to_string(codigo)) {
      naoEncontrouProduto = false;
      int quantidade_vendida = std::stoi(vendas[i]["QUANTIDADE_VENDIDA"]) + 1;
      float total_ganho = std::stof(vendas[i]["TOTAL_GANHO"]) + std::stof(vendas[i]["PREÇO"]);

      vendas[i]["QUANTIDADE_VENDIDA"] = std::to_string(quantidade_vendida);
      vendas[i]["TOTAL_GANHO"] = std::to_string(total_ganho);
    }
  }

  if (naoEncontrouProduto) {
    std::map<std::string, std::string> venda;
    int codigo_para_pesquisa = codigo;

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

vector_supermercado<std::map<std::string, std::string>> Supermercado::leituraDoEstoque() {
  std::fstream arquivo_leitura("caixa_supermercado.csv");
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

void Supermercado::escreveCaixaNoDisco(const vector_supermercado<std::map<std::string, std::string>>& vendas) {
  std::ofstream arquivoCaixa("caixa_supermercado.csv");

  arquivoCaixa << "CÓDIGO,NOME,PREÇO,QUANTIDE_VENDIDA,TOTAL_GANHO" << std::endl;

  for (size_t i = 0; i < vendas.size(); ++i) {
    arquivoCaixa << vendas[i]["CÓDIGO"] << ",";
    arquivoCaixa << vendas[i]["NOME"] << ",";
    arquivoCaixa << vendas[i]["PREÇO"] << ",";
    arquivoCaixa << vendas[i]["QUANTIDADE_VENDIDA"] << ",";
    arquivoCaixa << vendas[i]["TOTAL_GANHO"] << std::endl;
  }

  arquivoCaixa.close();
}
