#include <iostream>
#include <fstream>


bool checa_arg(char* operacao);


int main(int argc, char* argv[]) {
  if (argc == 1) {
    std::cout << "Quantidade de argumentos inferior ao esperado." << std::endl;
    std::cout << "Ex.: " << argv[0] << " add <mensagem>" << std::endl;
    return 1;
  }

  if (!checa_arg(argv[1])) {
    std::cout << "Comando " << argv[1] << " não conhecido." << std::endl;
    std::cout << "Os que estão disponíveis são: [add]" << std::endl;
    return 1;
  }

  std::string mensagem;
  std::ofstream arquivo_saida("diario", std::ios::app);

  if (argc == 2) {
    std::cout << "Digite uma mensagem: ";
    std::getline(std::cin, mensagem);
  } else {
    mensagem = std::string(argv[2]);
  }

  arquivo_saida << mensagem << std::endl;
  arquivo_saida.close();

  std::cout << "Mensagem Adicionada" << std::endl;

  return 0;
}


bool checa_arg(char* operacao) {
  return std::string(operacao) == "add";
}
