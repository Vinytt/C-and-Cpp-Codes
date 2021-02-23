//Definicao da classe Gatin:
#include <string>
#include <iostream>
using namespace std; //Lembrando que string esta dentro de std!

class Gatin{
public:
  Gatin(string cor, int peso);
  void miar();
  string get_cor();
  int get_peso();
  static string dono;
private:
  string cor;
  int peso;
};
