#include "Rosa.h"
#include <string>
#include <iostream>

Rosa::Rosa(){

}

Rosa::~Rosa(){
  std::cout << "Rosa deletada\n";
}

void Rosa::regar(){
  std::cout << "Rosa esta feliz :)\n";
}

void Rosa::morrer(){
  std::cout << "Rosa morreu :(\n";
  this->~Rosa();
}

std::string Rosa::get_nome(){
  return "Rosa";
}

void Rosa::desabrochar(){
  std::cout << "Lindas petalas rosas!\n";
}

void Rosa::presentear(std::string pessoa){
  std::cout << pessoa << " adorou a rosa!\n";
}
