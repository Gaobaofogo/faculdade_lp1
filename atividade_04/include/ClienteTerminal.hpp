#ifndef CLIENTE_TERMINAL_HPP
#define CLIENTE_TERMINAL_HPP

#include "Estabelecimento.hpp"
#include "Cliente.hpp"


class ClienteTerminal {
  private:
    Estabelecimento estabelecimento;
    std::vector<Cliente> clientes;

  public:
    ClienteTerminal(const std::string& nome_arquivo);
    int run();
};

#endif
