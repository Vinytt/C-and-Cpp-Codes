#include <string>
#include <iostream>
#include "Num_Complex.h"

//Construtores
Num_Complex::Num_Complex(double r, double i)
  :real{r}, imag{i}
{}

Num_Complex::Num_Complex(double r)
  :real{r}, imag{0.0}
{}

Num_Complex::Num_Complex()
  :real{0.0}, imag{0.0}
{}

//Acesso aos parâmetros
double Num_Complex::get_real(){
  return real;
}

void Num_Complex::set_real(double r){
  real = r;
}

double Num_Complex::get_imag(){
  return imag;
}

void Num_Complex::set_imag(double i){
  imag = i;
}

//Operadores
Num_Complex& Num_Complex::operator+=(Num_Complex z){
  real += z.get_real();
  imag += z.get_imag();

  return *this;
}

Num_Complex& Num_Complex::operator-=(Num_Complex z){
  real -= z.get_real();
  imag -= z.get_imag();

  return *this;
}

Num_Complex operator+(Num_Complex a, Num_Complex b){
  return a+=b;
}

Num_Complex operator-(Num_Complex a, Num_Complex b){
  return a-=b;
}

Num_Complex operator-(Num_Complex a){
  a.set_real(-a.get_real());
  a.set_imag(-a.get_imag());
  return a;
}

bool operator==(Num_Complex a, Num_Complex b){
  return (a.get_real() == b.get_real()) && (a.get_imag() == b.get_imag());
}

bool operator!=(Num_Complex a, Num_Complex b){
  return !(a==b);
}

//Imprimir valor
void Num_Complex::imprimir(){
  std::cout << "z = " << real << " + " << imag << "i\n";
}
