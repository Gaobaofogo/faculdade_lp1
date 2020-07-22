#ifndef CLIENTE_TERMINAL_HPP
#define CLIENTE_TERMINAL_HPP

#include "Cliente.hpp"
#include "Supermercado.hpp"
#include "Fornecedor.hpp"
#include "vector_supermercado.hpp"


class ClienteTerminal {
  private:
    Supermercado supermercado;
    vector_supermercado<Cliente> clientes;
    Fornecedor fornecedor;

  public:
    ClienteTerminal(const std::string& nome_arquivo);
    int run();
    void print_client_menu(int qntdClientes);
    void atualizar_saldo_do_cliente();
    void exibirSacola();
    void colocarProdutoNaSacola();
    bool encerrarAtividadeDoCliente();
    void abastecerEstoque();
};

#endif
