#include "Funcionario.hpp"

Funcionario::Funcionario(const std::string& _nome, const float& _salario, const std::string& _dataAdmissao) {
  this->nome = _nome;
  this->salario = _salario;
  this->dataAdmissao = _dataAdmissao;
}

void Funcionario::setEmpresa(Empresa _empresa) {
  this->empresa = _empresa;
}

std::string Funcionario::getDepartamento() {
  return this->departamento;
}

void Funcionario::setDepartamento(const std::string _departamento) {
  this->departamento = _departamento;
}

void Funcionario::aumentoDeSalario(float porcentagem_aumento) {
  this->salario += (this->salario * porcentagem_aumento)/100;
}

float Funcionario::getSalario() {
  return this->salario;
}
