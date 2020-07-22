#ifndef SUPERMERCADO_HPP
#define SUPERMERCADO_HPP

#include "Estabelecimento.hpp"
#include "Fornecedor.hpp"


class Supermercado : public Estabelecimento {
  public:
    Fornecedor fornecedor;

    Supermercado();
    void venda(int codigo);
    void listar();
    void reabastecer(int codigo, int quantidade);

  private:
    void escreveCaixaNoDisco(const vector_supermercado<std::map<std::string, std::string>>& vendas);
    vector_supermercado<std::map<std::string, std::string>> leituraDoEstoque();
};

#endif
