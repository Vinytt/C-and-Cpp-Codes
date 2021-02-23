#include "Orquidea.h"
#include <string>
#include <iostream>

Orquidea::Orquidea(){

}

Orquidea::~Orquidea(){
  std::cout << "Orquidea deletada\n";
}

void Orquidea::regar(){
  std::cout << "Orquidea esta feliz :)\n";
}

void Orquidea::morrer(){
  std::cout << "Orquidea morreu :(\n";
  this->~Orquidea();
}

std::string Orquidea::get_nome(){
  return "Orquidea";
}

void Orquidea::desabrochar(){
  std::cout << "Lindas petalas roxas!\n";
}

void Orquidea::perfume(){
  std::cout << "Hmm cheiroso!\n";
}

//Copy Constructor
Orquidea::Orquidea(const Orquidea& orqui){
  std::cout << "Orquidea: Copy Constructor\n";
}

//Copy Assignment
Orquidea& Orquidea::operator=(const Orquidea& orqui){
  std::cout << "Orquidea: Copy Assignment\n";
  return *this;
}

//Move Constructor
Orquidea::Orquidea(Orquidea&& orqui){
  std::cout << "Orquidea: Move Constructor\n";
}

//Move Assignment
Orquidea& Orquidea::operator=(Orquidea&& orqui){
  std::cout << "Orquidea: Move Assignment\n";
  return *this;
}
