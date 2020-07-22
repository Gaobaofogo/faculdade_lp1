#ifndef ESTABELECIMENTO_HPP
#define ESTABELECIMENTO_HPP

#include "Produto.hpp"
#include "vector_supermercado.hpp"

#include <map>
#include <string>
#include <vector>


class Estabelecimento {
  public:
    vector_supermercado<Produto> produtos;
    std::string unidadeMedida;
    float preco;

    Estabelecimento();
    Estabelecimento(const std::string& caminho_arquivo_estoque);
    void listar();
    void venda(int codigo);
    Produto* buscaProduto(int codigo_produto);
    Produto* buscaProduto(std::string nome);
    void caixa();

  protected:
    vector_supermercado<std::map<std::string, std::string>> leituraDoEstoque();
    void escreveCaixaNoDisco(const vector_supermercado<std::map<std::string, std::string>>& vendas);
};

#endif
