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
  Cliente c2;
  ClientePJ cpj1("123123", "1234566678");
  ClientePJ cpj2("1231231", "123123123");

  clientes.empurrar(c1);
  clientes.empurrar(c2);
  clientesPj.empurrar(cpj1);
  clientesPj.empurrar(cpj2);

  return 0;
}
