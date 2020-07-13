#include "ClienteTerminal.hpp"

#include <iostream>

ClienteTerminal::ClienteTerminal(const std::string& nome_arquivo) {
  Estabelecimento estabelecimento(nome_arquivo);
  Cliente primeiro_cliente(0);

  this->estabelecimento = this->estabelecimento;
  this->clientes.push_back(primeiro_cliente);
}

void ClienteTerminal::print_client_menu(int qntdClientes) {
  std::cout << std::endl;
  std::cout << "Selecione uma opção cliente " << qntdClientes << ":" << std::endl << std::endl;
  std::cout << "\t1) Adicionar saldo" << std::endl;
  std::cout << "\t2) Ver produtos da loja" << std::endl;
  std::cout << "\t3) Ver conteúdo da sacola" << std::endl;
  std::cout << "\t4) Colocar um produto na sacola" << std::endl;
  std::cout << std::endl;
  std::cout << "\t0) Encerrar as atividades do cliente " << qntdClientes << std::endl;
}

void ClienteTerminal::atualizar_saldo_do_cliente() {
  float novo_saldo;

  std::cout << "Digite o valor a ser inserido no saldo: ";
  std::cin >> novo_saldo;

  this->clientes[this->clientes.size() - 1].saldo += novo_saldo;

  std::cout << "Saldo atual: R$ " << this->clientes[this->clientes.size() - 1].saldo << std::endl;
}

int ClienteTerminal::run() {
  char opcao;
  bool continuar_no_programa = true;

  std::cout << "Loja virtual 1.0" << std::endl;

  while (continuar_no_programa == true) {
    this->print_client_menu(this->clientes.size());

    std::cout << "Digite uma opção: ";
    std::cin >> opcao;

    if (opcao == '1') {
      this->atualizar_saldo_do_cliente();
    } else if (opcao == '2') {
      this->estabelecimento.listar();
    } else if (opcao == '3') {
      if (this->clientes[this->clientes.size() - 1].sacola.size()) {
        std::cout << std::endl << "Quantidade de itens da sacola: ";
        std::cout << this->clientes[this->clientes.size() - 1].sacola.size() << std::endl;

        int i = 1;

        for (auto it = this->clientes[this->clientes.size() - 1].sacola.begin(); it != this->clientes[this->clientes.size() - 1].sacola.end(); ++it, ++i) {
          std::cout << "\tNome: " << it->nome << " - ";
          std::cout << "\tPreço: R$ " << it->preco << std::endl; 
        }
      } else {
        std::cout << "A sacola está vazia." << std::endl;
      }
    } else if (opcao == '4') {
      int codigo_produto;

      std::cout << "Digite o código do produto: ";
      std::cin >> codigo_produto;

      Produto* produto_encontrado = this->estabelecimento.buscaProduto(codigo_produto);

      if (produto_encontrado == nullptr) {
        std::cout << "Produto não encontrado" << std::endl << std::endl;
      } else {
        if (produto_encontrado->quantidade > 0) {
          this->clientes[this->clientes.size() - 1].compra((*produto_encontrado));
          produto_encontrado->quantidade -= 1;
        } else {
          std::cout << "Não temos mais o produto requisitado em estoque" << std::endl;
        }
      }
    } else if (opcao == '0') {
      char resposta;

      std::cout << "Deseja inicializar um novo cliente? [Y/n] ";
      std::cin >> resposta;

      if (resposta == 'n' || resposta == 'N') {
        continuar_no_programa = false;
      } else if (resposta == 'y' || resposta == 'Y') {

        Cliente novo_cliente(0);
        this->clientes.push_back(novo_cliente);
      } else {
        std::cout << "Opção não conhecida" << std::endl;
      }

      this->clientes[this->clientes.size() - 1].registro(this->clientes.size());
    } else {
      std::cout << "Opção desconhecida pelo programa;" << std::endl;
    }
  }

  return 0;
}
