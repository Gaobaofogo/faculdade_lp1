#ifndef CLIENTE_TERMINAL_HPP
#define CLIENTE_TERMINAL_HPP

#include "Cliente.hpp"
#include "Estabelecimento.hpp"
#include "Fornecedor.hpp"


class ClienteTerminal {
  private:
    Estabelecimento estabelecimento;
    std::vector<Cliente> clientes;
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
