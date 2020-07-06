#ifndef CONTA_H
#define CONTA_H

#include <string>


class Conta {
  public:
    int numero;
    std::string titular;
    float saldo;

    Conta(int numero, std::string titular, float saldo);
    void saca(float valor);
    void deposita(float valor);
    void transfere(float valor, Conta& outra_conta);
};

#endif
