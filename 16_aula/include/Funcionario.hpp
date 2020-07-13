#ifndef FUNCIONARIO_HPP
#define FUNCIONARIO_HPP

#include "Empresa.hpp"


class Funcionario {
  private:
    std::string nome;
    Empresa empresa;
    std::string departamento;
    float salario;
    std::string dataAdmissao;

  public:
    Funcionario(const std::string& _nome, const float& salario, const std::string& dataAdmissao);
    void setEmpresa(Empresa _empresa);
    std::string getDepartamento();
    void setDepartamento(const std::string _departamento);
    void aumentoDeSalario(float porcentagem_aumento);
    float getSalario();
};

#endif
