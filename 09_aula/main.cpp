#include "App.h"

int main(int argc, char* argv[]) {
  App aplicativo("diario.md");
  return aplicativo.run(argc, argv);
}
