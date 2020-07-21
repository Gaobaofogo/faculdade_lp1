#ifndef CLIENTEPF_HPP
#define CLIENTEPF_HPP

#include "Cliente.hpp"

#include <string>


class ClientePF : public Cliente {
  private:
    std::string cpf;

  public:
    ClientePF(const std::string nome, const float saldo, const std::string cpf);

    void setNome(const std::string nome);
    std::string getNome();

    void setCpf(const std::string cpf);
    std::string getCpf();
};

#endif
