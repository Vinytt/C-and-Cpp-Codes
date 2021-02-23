#ifndef ALUNO_H
#define ALUNO_H
#include <string>
#include <iostream>
//#include <fstream>

class Aluno {
public:
  //Construtores
  Aluno(int nota, std::string nome);

  //Destrutores
  ~Aluno();

  //Getters
  int get_nota() const;
  std::string get_nome() const;

  //Setters
  void set_nota(int n);
  void set_nome(std::string n);

private:
  int nota;
  std::string nome;
};

//Input & Output
std::ostream& operator<<(std::ostream& os, const Aluno& aluno);
std::istream& operator>>(std::istream& is, Aluno& aluno);

#endif
