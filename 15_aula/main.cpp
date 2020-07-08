#include "Conta.hpp"

#include <iostream>


int main(int argc, char* argv[]) {
  Conta conta_do_joao(1, "João", 100.00);
  Conta conta_da_marcia(2, "Márcia", 100.00);

  conta_do_joao.saca(20);

  std::cout << "Reais na conta do " << conta_do_joao.cliente.nome << ": " << conta_do_joao.saldo << std::endl;

  conta_do_joao.deposita(20);

  std::cout << "Reais na conta do João: " << conta_do_joao.saldo << std::endl;

  conta_do_joao.transfere(20, conta_da_marcia);

  std::cout << "Reais na conta do Marcia: " << conta_da_marcia.saldo << std::endl;
  std::cout << "Reais na conta do João: " << conta_do_joao.saldo << std::endl;

  return 0;
}
