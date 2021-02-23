#include "Aluno.h"

Aluno::Aluno(int nota, std::string nome)
  :nota{nota}, nome{nome}
{}

Aluno::~Aluno(){

}

int Aluno::get_nota() const{
  return nota;
}

std::string Aluno::get_nome() const{
  return nome;
}

void Aluno::set_nota(int n){
  this->nota = n;
}

void Aluno::set_nome(std::string n){
  this->nome = n;
}

std::ostream& operator<<(std::ostream& os, const Aluno& aluno){
  return os << "\nAluno: " << aluno.get_nome() << "\nNota: " << aluno.get_nota() << "\n";
}

std::istream& operator>>(std::istream& is, Aluno& aluno){
  std::string nome;
  int nota;

  is >> nota;
  is >> nome;

  aluno = {nota, nome};

  return is;
}
