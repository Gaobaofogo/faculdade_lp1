#ifndef CLIENTEPJ_HPP
#define CLIENTEPJ_HPP

#include <string>


class ClientePJ {
  private:
    std::string razaoSocial;
    std::string cnpj;
  
  public:
    ClientePJ();
    ClientePJ(const std::string& razaoSocial, const std::string& cnpj);
    std::string getRazaoSocial();
    void setRazaoSocial(const std::string& razaoSocial);
    std::string getCnpj();
    void setCnpj(const std::string& cnpj);
};

#endif