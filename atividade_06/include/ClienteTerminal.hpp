#ifndef CLIENTE_TERMINAL_HPP
#define CLIENTE_TERMINAL_HPP

#include "Cliente.hpp"
#include "Supermercado.hpp"
#include "vector_supermercado.hpp"


class ClienteTerminal {
  private:
    Supermercado supermercado;
    vector_supermercado<Cliente> clientes;

  public:
    ClienteTerminal(const std::string& nome_arquivo);
    int run();
    void executarSupermercado();
    void executarRestaurante();
    void print_client_menu(int qntdClientes);
    void exibirMenuRestaurante();
    void atualizar_saldo_do_cliente();
    void exibirSacola();
    void exibirMenu();
    void colocarProdutoNaSacola();
    bool encerrarAtividadeDoCliente();
    void abastecerEstoque();
};

#endif
