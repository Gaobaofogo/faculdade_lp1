#include "ClientePJ.hpp"



ClientePJ::ClientePJ(const std::string& razaoSocial, const float saldo, const std::string& cnpj): Cliente(razaoSocial, saldo) {
  this->cnpj = cnpj;
}

std::string ClientePJ::getRazaoSocial() {
  return this->nome;
}

void ClientePJ::setRazaoSocial(const std::string& razaoSocial) {
  this->nome = razaoSocial;
}

std::string ClientePJ::getCnpj() {
  return this->cnpj;
}

void ClientePJ::setCnpj(const std::string& cnpj) {
  this->cnpj = cnpj;
}
