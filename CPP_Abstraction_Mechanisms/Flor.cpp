#include "Flor.h"
#include <string>
#include <iostream>

Flor::Flor(){

}

Flor::~Flor(){
  std::cout << "Flor deletada\n";
}

void Flor::regar(){
  std::cout << "Flor esta feliz :)\n";
}

void Flor::morrer(){
  std::cout << "Flor morreu :(\n";
  this->~Flor();
}

std::string Flor::get_nome(){
  return "Flor";
}

void Flor::desabrochar(){
  std::cout << "Lindas petalas!\n";
}
