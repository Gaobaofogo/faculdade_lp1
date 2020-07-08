#ifndef CONTA_H
#define CONTA_H

#include "Cliente.hpp"
#include "Agencia.hpp"

#include <string>


class Conta {
  public:
    Cliente cliente;
    Agencia agencia;
    float saldo;

    Conta(int numero, std::string titular, float saldo);
    ~Conta();
    static int quantidadeDeContas;
    void saca(float valor);
    void deposita(float valor);
    void transfere(float valor, Conta& outra_conta);
};

#endif
