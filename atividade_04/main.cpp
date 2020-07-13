#include "ClienteTerminal.hpp"

#include <iostream>
#include <vector>

void print_client_menu(int qntdClientes);


int main(int argc, char* argv[]) {
  ClienteTerminal clienteTerminal("estoque.csv");

  return clienteTerminal.run();
}
