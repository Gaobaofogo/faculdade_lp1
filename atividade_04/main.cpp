#include "Cliente.hpp"
#include "Estabelecimento.hpp"

#include <iostream>
#include <vector>

void print_client_menu(int qntdClientes);


int main(int argc, char* argv[]) {
  Estabelecimento estabelecimento("estoque.csv");
  std::vector<Cliente> clientes;
  std::vector<Produtos> sacola;
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

      std::cout << "Digite o novo saldo: ";
      std::cin >> novo_saldo;

      clientes[clientes.size() - 1].saldo = novo_saldo;
    } else if (opcao == '2') {
      estabelecimento.listar();
    } else if (opcao == '3') {
    } else if (opcao == '4') {
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
    } else {
      std::cout << "Opção desconhecida pelo programa;" << std::endl;
    }
  }

  return 0;
}

void print_client_menu(int qntdClientes) {
  std::cout << std::endl;
  std::cout << "Selecione uma opção cliente " << qntdClientes << ":" << std::endl << std::endl;
  std::cout << "\t1) Modificar saldo" << std::endl;
  std::cout << "\t2) Ver produtos da loja" << std::endl;
  std::cout << "\t3) Ver conteúdo da sacola" << std::endl;
  std::cout << "\t4) Por na sacola um item" << std::endl;
  std::cout << std::endl;
  std::cout << "\t0) Encerrar as atividades do cliente " << qntdClientes << std::endl;
}
