#include "Empresa.hpp"

Empresa::Empresa() {

}


Empresa::Empresa(const std::string& _nome, const std::string& _cnpj) {
  this->nome = _nome;
  this->cnpj = _cnpj;
}
