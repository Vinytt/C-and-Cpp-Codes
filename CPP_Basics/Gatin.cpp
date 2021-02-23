//Implementação da classe Gatin
#include "Gatin.h"
#include <iostream>
#include <string>
using namespace std;

constexpr int peso_min = 0;

//Construtor
Gatin::Gatin(string cor, int peso)
  :cor{cor}, peso{peso}
{
  static_assert(sizeof(peso)>2, "Peso muito pequeno!\n");
}

//Miar
void Gatin::miar(){
  cout << "Miau!\n";
}

//Getters
string Gatin::get_cor(){
  return cor;
}

int Gatin::get_peso(){
  return peso;
}

//Variável estática
string Gatin::dono = "Nathan";
