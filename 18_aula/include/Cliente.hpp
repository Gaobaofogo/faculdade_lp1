#ifndef CLIENTE_HPP
#define CLIENTE_HPP

#include <string>


class Cliente {
  protected:
    std::string nome;
    float saldo;

  public:
    Cliente();
    Cliente(const std::string nome, const float saldo);

    float getSaldo();
    void saca(const float valor);
    void deposita(const float valor);
};

#endif
