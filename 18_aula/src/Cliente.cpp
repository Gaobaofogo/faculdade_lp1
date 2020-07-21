#include "Cliente.hpp"


Cliente::Cliente() {

}

Cliente::Cliente(const std::string nome, const float saldo) {
  this->nome = nome;
  this->saldo = saldo;
}

float Cliente::getSaldo() {
  return this->saldo;
}

void Cliente::saca(const float valor) {
  this->saldo -= valor;
}

void Cliente::deposita(const float valor) {
  this->saldo += valor;
}
