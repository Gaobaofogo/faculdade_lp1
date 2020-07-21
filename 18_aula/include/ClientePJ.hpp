#ifndef CLIENTEPJ_HPP
#define CLIENTEPJ_HPP

#include "Cliente.hpp"

#include <string>


class ClientePJ : public Cliente {
  private:
    std::string cnpj;
  
  public:
    ClientePJ(const std::string& razaoSocial, const float saldo, const std::string& cnpj);
    std::string getRazaoSocial();
    void setRazaoSocial(const std::string& razaoSocial);
    std::string getCnpj();
    void setCnpj(const std::string& cnpj);
};

#endif
