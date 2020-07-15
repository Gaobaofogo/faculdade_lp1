#include "Fila.hpp"
#include "Cliente.hpp"
#include "ClientePJ.hpp"

#include <iostream>
#include <string>
#include <vector>


int main(int argc, char* argv[]) {
  Fila<Cliente> clientes;
  Fila<ClientePJ> clientesPj;
  Cliente c1;
  c1.nome = "Jonas";
  Cliente c2;
  c2.nome = "Henrique";
  ClientePJ cpj1("123123", "1234566678");
  ClientePJ cpj2("1231231", "123123123");

  clientes.empurrar(c1);
  clientes.empurrar(c2);
  clientesPj.empurrar(cpj1);
  clientesPj.empurrar(cpj2);
  
  std::cout << clientes.primeiro().nome << std::endl;
  clientes.extrair();
  std::cout << clientes.primeiro().nome << std::endl;

  return 0;
}
