#include <string>
#include <iostream>

class Num_Complex{
public:
  //Construtores:
  Num_Complex(double r, double i);
  Num_Complex(double r);
  Num_Complex(); //Por não requerer nenhum parâmetro, esse é tido como o construtor padrão (default)

  //Acesso a parâmetros
  double get_real();
  void set_real(double r);
  double get_imag();
  void set_imag(double i);

  //Operadores (esses precisam de uma referência ao objeto que as chama, por isso "&")
  Num_Complex& operator+=(Num_Complex z);
  Num_Complex& operator-=(Num_Complex z);

  //Imprimir valor
  void imprimir();

private:
  double real, imag;
};

//OBS: Operadores que não refereciam um objeto que os chamam não precisam ser definidos
//dentro da Classe:
Num_Complex operator+(Num_Complex a, Num_Complex b); //Soma 2 complexos
Num_Complex operator-(Num_Complex a, Num_Complex b); //Subtrai b de a (- binário)
Num_Complex operator-(Num_Complex a); //retorna -a (- unário)
bool operator==(Num_Complex a, Num_Complex b);
bool operator!=(Num_Complex a, Num_Complex b);
