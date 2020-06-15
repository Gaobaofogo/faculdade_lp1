#include <iostream>


// argc é a quantidade de argumentos passados para o programa, incluindo o
// próprio caminho do programa.
// argv são os argumentos passados para o programa como uma lista de lista de
// caracteres(lista de strings).
//
// Ex.: ./prog
// argc: 1
// argv: ["./prog"]
//
// Ex.: ./prog 5 ola
// argc: 3
// argv: ["./prog", "5", "ola"]
int main(int argc, char* argv[]) {
  int numero1 = 0;
  int numero2 = 0;

  std::cout << "Digite o primeiro numero: ";
  std::cin >> numero1;

  std::cout << "Digite o segundo numero: ";
  std::cin >> numero2;

  int soma = numero1 + numero2;

  std::cout << "A soma é " << soma << std::endl;

  return 0;
}
