#include "Conta.hpp"

Conta::Conta(int numero, std::string titular, float saldo) {
  this->numero = numero;
  this->titular = titular;
  this->saldo = saldo;
}

void Conta::saca(float valor) {
  this->saldo -= valor;
}

void Conta::deposita(float valor) {
  this->saldo += valor;
}

void Conta::transfere(float valor, Conta& outra_conta) {
  outra_conta.deposita(valor);
  this->saca(valor);
}
