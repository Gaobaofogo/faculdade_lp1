#include "Cliente.hpp"
#include "Estabelecimento.hpp"

#include <iostream>
#include <vector>

void print_client_menu(int qntdClientes);


int main(int argc, char* argv[]) {
  Estabelecimento estabelecimento("estoque.csv");
  std::vector<Cliente> clientes;
  Cliente cliente_1(0);
  char opcao;
  bool continuar_no_programa = true;

  clientes.push_back(cliente_1);

  std::cout << "Loja virtual 1.0" << std::endl;

  while (continuar_no_programa == true) {
    print_client_menu(clientes.size());

    std::cout << "Digite uma opção: ";
    std::cin >> opcao;

    if (opcao == '1') {
      float novo_saldo;

      std::cout << "Digite o valor a ser inserido no saldo: ";
      std::cin >> novo_saldo;

      clientes[clientes.size() - 1].saldo += novo_saldo;
      std::cout << "Saldo atual: R$ " << clientes[clientes.size() - 1].saldo << std::endl;
    } else if (opcao == '2') {
      estabelecimento.listar();
    } else if (opcao == '3') {
      if (clientes[clientes.size() - 1].sacola.size()) {
        std::cout << std::endl << "Quantidade de itens da sacola: ";
        std::cout << clientes[clientes.size() - 1].sacola.size() << std::endl;

        int i = 1;

        for (auto it = clientes[clientes.size() - 1].sacola.begin(); it != clientes[clientes.size() - 1].sacola.end(); ++it, ++i) {
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

      Produto* produto_encontrado = estabelecimento.buscaProduto(codigo_produto);

      if (produto_encontrado == nullptr) {
        std::cout << "Produto não encontrado" << std::endl << std::endl;
      } else {
        if (produto_encontrado->quantidade > 0) {
          clientes[clientes.size() - 1].compra((*produto_encontrado));
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
        clientes.push_back(novo_cliente);
      } else {
        std::cout << "Opção não conhecida" << std::endl;
      }

      clientes[clientes.size() - 1].registro(clientes.size());
    } else {
      std::cout << "Opção desconhecida pelo programa;" << std::endl;
    }
  }

  return 0;
}

void print_client_menu(int qntdClientes) {
  std::cout << std::endl;
  std::cout << "Selecione uma opção cliente " << qntdClientes << ":" << std::endl << std::endl;
  std::cout << "\t1) Adicionar saldo" << std::endl;
  std::cout << "\t2) Ver produtos da loja" << std::endl;
  std::cout << "\t3) Ver conteúdo da sacola" << std::endl;
  std::cout << "\t4) Colocar um produto na sacola" << std::endl;
  std::cout << std::endl;
  std::cout << "\t0) Encerrar as atividades do cliente " << qntdClientes << std::endl;
}
