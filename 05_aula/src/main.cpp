#include <iostream>
#include <fstream>
#include "hora.h"
#define NOME_ARQUIVO "diario.txt"


bool checa_arg(char* operacao, std::string comandos[]);
void processa_comando(std::string comando, int argc, char* argv[]);
void add_mensagem(int argc, char* argv[]);
void adiciona_comentario_do_dia(std::string mensagem);
void list_mensagem();

std::string comandos[] = {"add", "list"};


int main(int argc, char* argv[]) {
  if (argc == 1) {
    std::cout << "Quantidade de argumentos inferior ao esperado." << std::endl;
    std::cout << "Ex.: " << argv[0] << " add <mensagem>" << std::endl;
    return 1;
  }

  if (!checa_arg(argv[1], comandos)) {
    std::cout << "Comando " << argv[1] << " não conhecido." << std::endl;
    std::cout << "Os que estão disponíveis são: [add, list]" << std::endl;
    return 1;
  }

  processa_comando(argv[1], argc, argv);

  return 0;
}


bool checa_arg(char* operacao, std::string comandos[]) {
  for (int i = 0; i < comandos->size(); ++i) {
    if (operacao == comandos[i]) {
      return true;
    }
  }

  return false;
}

void processa_comando(std::string comando, int argc, char* argv[]) {
  if (comando == "add") {
    add_mensagem(argc, argv);
  } else if (comando == "list") {
    list_mensagem();
  }
}

void add_mensagem(int argc, char* argv[]) {
  std::string mensagem;

  if (argc == 2) {
    std::cout << "Digite uma mensagem: ";
    std::getline(std::cin, mensagem);
  } else {
    mensagem = std::string(argv[2]);
  }

  adiciona_comentario_do_dia(mensagem);
}

void adiciona_comentario_do_dia(std::string mensagem) {
  std::ofstream arquivo_escrita(NOME_ARQUIVO, std::ios::app);
  std::ifstream arquivo_leitura(NOME_ARQUIVO);

  if (arquivo_leitura.fail() || arquivo_escrita.fail()) {
    std::cerr << "Não foi possível adicionar a mensagem no diario.";
    std::cerr << std::endl;
    std::cerr << "Arquivo inexistente ou problemas com permissões.";
    std::cerr << std::endl;
    return;
  }

  std::string linha;

  // Se o arquivo estiver vazio, já preencho com a data de hoje
  if (!std::getline(arquivo_leitura, linha)) {
    arquivo_escrita << "# " << get_current_date() << std::endl << std::endl;
    arquivo_escrita << "- " << get_current_time() << " " << mensagem << std::endl;
  } else {
    // Funcionamento da seekg:
    // http://www.cplusplus.com/reference/istream/istream/seekg/
    arquivo_leitura.seekg(std::ios::beg);
    std::getline(arquivo_leitura, linha);
    arquivo_leitura.seekg(std::ios::beg);

    // No erase, precisa descontar o tamanho do caracter espaço que é 1.
    // Assim, vai separar o começo, remover o separador escolhido que foi o
    // espaço e fica o resto da linha desejada.
    linha.erase(0, linha.find(" ") + 1);

    std::string maior_data = linha;
    std::string ultima_data;

    while(std::getline(arquivo_leitura, linha)) {
      if (linha.length() && linha.at(0) == '#') {
        ultima_data = extract_date(linha);

        if (ultima_data > maior_data) {
          maior_data = ultima_data;
        }
      }
    }

    if (maior_data == get_current_date()) {
      arquivo_escrita << "- " << get_current_time() << " " << mensagem;
      arquivo_escrita << std::endl;
    } else if (maior_data > get_current_date()) {
      std::cerr << "A data de hoje é menor do que o último dia cadastrado.";
      std::cerr << std::endl <<"Veja se seu calendário não está atrasado.";
      std::cerr << std::endl;
      return;
    } else {
      arquivo_escrita << std::endl << "# " << get_current_date() << std::endl << std::endl;
      arquivo_escrita << "- " << get_current_time() << " " << mensagem << std::endl;
    }
  }

  arquivo_escrita.close();
  arquivo_leitura.close();

  std::cout << "Mensagem Adicionada" << std::endl;
}

void list_mensagem() {
  std::ifstream arquivo_leitura(NOME_ARQUIVO);

  if (arquivo_leitura.fail()) {
    std::cerr << "Leitura do arquivo retornou erro" << std::endl;
    std::cerr << "Arquivo inexistente ou problemas com permissões.";
    std::cerr << std::endl;
  } else {
    std::string linha;

    while (std::getline(arquivo_leitura, linha)) {
      if (linha.length() && linha.at(0) == '-') {
        std::cout << linha << std::endl;
      }
    }

    arquivo_leitura.close();
  }
}
