#include "Empresa.hpp"
#include "Funcionario.hpp"

#include <iostream>
#include <string>
#include <vector>


int main(int argc, char* argv[]) {
  Empresa IMD("IMD", "12.3456.789/0000-00");
  std::vector<Funcionario> funcionarios;
  int qntdFuncionarios;

  std::cout << "Número de funcionários a cadastrar: ";
  std::cin >> qntdFuncionarios;

  for (int i = 0; i < qntdFuncionarios; ++i) {
    std::string nome;
    float salario;
    std::string dataAdmissao;
    std::string departamento;

    std::cout << "Empregado " << i + 1 << std::endl;

    std::cout << "Digite o nome: ";
    std::cin >> nome;

    std::cout << "Digite o salario: ";
    std::cin >> salario;

    std::cout << "Digite a data de admissao: ";
    std::cin >> dataAdmissao;

    std::cout << "Digite o departamento: ";
    std::cin >> departamento;

    Funcionario novoFuncionario(nome, salario, dataAdmissao);
    novoFuncionario.setEmpresa(IMD);
    novoFuncionario.setDepartamento(departamento);

    funcionarios.push_back(novoFuncionario);
  }

  for (auto it = funcionarios.begin(); it != funcionarios.end(); ++it) {
    if (it->getDepartamento() == "Ensino") {
      it->aumentoDeSalario(10);
    }
  }

  return 0;
}
