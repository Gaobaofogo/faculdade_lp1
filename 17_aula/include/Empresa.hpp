#ifndef EMPRESA_HPP
#define EMPRESA_HPP

#include <string>


class Empresa {
  private:
    std::string nome;
    std::string cnpj;

  public:
    Empresa();
    Empresa(const std::string& _nome, const std::string& _cnpj);
};

#endif
