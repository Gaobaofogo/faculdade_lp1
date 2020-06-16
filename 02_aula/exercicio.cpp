#include <iostream>


bool checa_arg(char* operacao) {
  if (std::string(operacao) == "add") {
    return true;
  }

  return false;
}

int main(int argc, char* argv[]) {
  std::string mensagem;

  if (argc == 1) {
    std::cout << "Quantidade de argumentos inferior ao esperado." << std::endl;
    std::cout << "Ex.: " << argv[0] << " add <mensagem>" << std::endl;
  } else if (checa_arg(argv[1])) {
      if (argc == 2) {

      std::cout << "Digite uma mensagem: ";
      std::getline(std::cin, mensagem);

      std::cout << "Mensagem Adicionada" << std::endl;
    } else {
      mensagem = std::string(argv[2]);

      std::cout << "Mensagem adicionada" << std::endl;
    }
  } else {
    std::cout << "Comando " << argv[1] << " não conhecido." << std::endl;
    std::cout << "Os que estão disponíveis são: [add]" << std::endl;
  }

  return 0;
}
