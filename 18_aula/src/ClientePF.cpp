#include "ClientePF.hpp"


ClientePF::ClientePF(const std::string nome, const float saldo, const std::string cpf): Cliente(nome, saldo) {
  this->cpf = cpf;
}

void ClientePF::setNome(const std::string nome) {
  this->nome = nome;
}

std::string ClientePF::getNome() {
  return this->nome;
}

void ClientePF::setCpf(const std::string cpf) {
  this->cpf = cpf;
}

std::string ClientePF::getCpf() {
  return this->cpf;
}
