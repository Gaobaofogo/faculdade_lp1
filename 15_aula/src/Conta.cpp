#include "Conta.hpp"

int Conta::quantidadeDeContas = 0;

Conta::Conta(int numero, std::string titular, float saldo) {
  this->agencia.numeroDaAgencia = numero;
  this->cliente.nome = titular;
  this->saldo = saldo;
  this->quantidadeDeContas += 1;
}

Conta::~Conta() {
  this->quantidadeDeContas -= 1;
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
