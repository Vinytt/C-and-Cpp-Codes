#include "Arvore.h"
#include <string>
#include <iostream>

Arvore::Arvore(int indade, int tamanho):
  idade{idade}, tamanho{tamanho}{}

Arvore::~Arvore(){
  std::cout << "Arvore deletada\n";
}

void Arvore::regar(){
  std::cout << "Arvore feliz :)\n";
}

void Arvore::morrer(){
  std::cout << "Arvore morreu :(\n";
  this->~Arvore();
}

std::string Arvore::get_nome(){
  return "Arvore";
}

int Arvore::get_idade(){
  return idade;
}

int Arvore::get_tamanho(){
  return tamanho;
}
