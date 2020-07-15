#include "ClientePJ.hpp"


ClientePJ::ClientePJ() {

}

ClientePJ::ClientePJ(const std::string& razaoSocial, const std::string& cnpj) {
  this->razaoSocial = razaoSocial;
  this->cnpj = cnpj;
}

std::string ClientePJ::getRazaoSocial() {
  return this->razaoSocial;
}

void ClientePJ::setRazaoSocial(const std::string& razaoSocial) {
  this->razaoSocial = razaoSocial;
}

std::string ClientePJ::getCnpj() {
  return this->cnpj;
}

void ClientePJ::setCnpj(const std::string& cnpj) {
  this->cnpj = cnpj;
}