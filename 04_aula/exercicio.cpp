#include <iostream>
#include <fstream>
#define NOME_ARQUIVO "diario"


bool checa_arg(char* operacao, std::string comandos[]);
void processa_comando(std::string comando, int argc, char* argv[]);
void add_mensagem(int argc, char* argv[]);
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

  std::ofstream arquivo_saida(NOME_ARQUIVO, std::ios::app);

  if (arquivo_saida.fail()) {
    std::cerr << "Não foi possível adicionar a mensagem no diario.";
    std::cerr << std::endl;
    std::cerr << "Arquivo inexistente ou problemas com permissões.";
    std::cerr << std::endl;
  }

  arquivo_saida << mensagem << std::endl;
  arquivo_saida.close();

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
    int numero_linha = 0;

    while (std::getline(arquivo_leitura, linha)) {
      ++numero_linha;
      std::cout << numero_linha << ". " << linha << std::endl;
    }

    arquivo_leitura.close();
  }
}
