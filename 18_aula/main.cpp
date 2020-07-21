#include "ClientePF.hpp"
#include "ClientePJ.hpp"

#include <iostream>


int main(int argc, char* argv[]) {
  ClientePF clientepf("Antonio", 50, "000.000.000-00");
  ClientePJ clientepj("Cia e Compania", 100, "1241234");

  clientepf.deposita(50);

  std::cout << clientepf.getSaldo() << std::endl;

  return 0;
}
