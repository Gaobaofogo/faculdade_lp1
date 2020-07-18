#include "Cliente.hpp"
#include "Produto.hpp"

#include <fstream>
#include <iostream>


Cliente::Cliente() {
  this->saldo = 0;
}

Cliente::Cliente(float _saldo): saldo(_saldo) {

}

void Cliente::compra(Produto novo_produto) {
  if (this->saldo - novo_produto.preco < 0) {
    std::cout << "Saldo insuficiente" << std::endl;
    return;
  }

  this->sacola.push_back(novo_produto);
}

void Cliente::registro(int numero_do_cliente) {
  std::string nome_arquivo = "cliente_" + std::to_string(numero_do_cliente) + ".txt";
  std::ofstream arquivo_do_cliente_escrita(nome_arquivo);

  arquivo_do_cliente_escrita << "COD,PRODUTO,UNIDADE DE MEDIDA,PREÇO,QUANTIDADE" << std::endl;

  for (auto it = this->sacola.begin(); it != this->sacola.end();  ++it) {
    arquivo_do_cliente_escrita << it->codigo << ",";
    arquivo_do_cliente_escrita << it->nome << ",";
    arquivo_do_cliente_escrita << it->unidadeMedida << ",";
    arquivo_do_cliente_escrita << "\"R$ " << it->preco << "\"" << ",";
    arquivo_do_cliente_escrita << it->codigo << std::endl;
  }

  arquivo_do_cliente_escrita.close();
}
