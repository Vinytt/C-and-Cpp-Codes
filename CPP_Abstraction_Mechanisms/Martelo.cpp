//implementação Martelo
#include <string>
#include <iostream>
#include "Martelo.h"

//Overriding de Funções
Martelo::Martelo(){
  std::cout << "Martelo instanciado\n";
}

Martelo::~Martelo(){
  std::cout << "Martelo destruído\n";
}

void Martelo::usar(){
  std::cout << "Martelando!\n";
}

void Martelo::fazer_revolucao(){
  std::cout << "Com o poder da foice!\n";
}

std::string Martelo::get_nome(){
  return martelo_nome;
}

std::string Martelo::martelo_nome = "Martelo";
