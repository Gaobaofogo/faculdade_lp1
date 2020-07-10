#include "Cliente.hpp"

#include <iostream>
#include <vector>

void print_client_menu(int qntdClientes);

int main(int argc, char* argv[]) {
  std::vector<Cliente> clientes;
  Cliente cliente_1(0);
  char opcao;
  bool continuar_no_programa = true;

  clientes.push_back(cliente_1);

  std::cout << "Loja virtual 1.0" << std::endl << std::endl;

  while (continuar_no_programa == true) {
    print_client_menu(clientes.size());

    std::cout << "Digite uma opção: ";
    std::cin >> opcao;

    if (opcao == '1') {
    } else if (opcao == '2') {
    } else if (opcao == '3') {
    } else if (opcao == '0') {
      char resposta;

      std::cout << "Deseja inicializar um novo cliente? [Y/n] ";
      std::cin >> resposta;

      if (resposta == 'n' || resposta == 'N') {
        continuar_no_programa = false;
      } else if (resposta == 'y' || resposta == 'Y') {
        Cliente novo_cliente(0);
        clientes.push_back(novo_cliente);
      }
    } else {
      std::cout << "Opção desconhecida pelo programa;" << std::endl;
    }
  }

  return 0;
}

void print_client_menu(int qntdClientes) {
  std::cout << "Bem vindo a loja cliente " << qntdClientes << "." << std::endl;
  std::cout << "Selecione uma opção:" << std::endl << std::endl;
  std::cout << "\t1) Adicionar saldo" << std::endl;
  std::cout << "\t2) Ver produtos da loja" << std::endl;
  std::cout << "\t3) Ver conteúdo da sacola" << std::endl;
  std::cout << std::endl;
  std::cout << "\t0) Encerrar as atividades do cliente " << qntdClientes << std::endl;
}
