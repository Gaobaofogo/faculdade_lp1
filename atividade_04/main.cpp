#include "Cliente.hpp"

#include <iostream>
#include <vector>


int main(int argc, char* argv[]) {
  std::vector<Cliente> clientes;

  std::cout << "Loja virtual 1.0" << std::endl << std::endl;

  std::cout << "Bem vindo a loja cliente X." << std::endl;
  std::cout << "Selecione uma opção:" << std::endl << std::endl;
  std::cout << "\t1) Adicionar saldo" << std::endl;
  std::cout << "\t2) Ver produtos da loja" << std::endl;
  std::cout << "\t3) Ver conteúdo da sacola" << std::endl;
  std::cout << std::endl;
  std::cout << "\t0) Encerrar as atividades do cliente X" << std::endl;

  return 0;
}
