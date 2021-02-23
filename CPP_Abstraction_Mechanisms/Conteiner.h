#ifndef CONTEINER_H
#define CONTEINER_H

class Conteiner{
public:
  //Destrutor
  virtual ~Conteiner(){}

  //Operadores
  //virtual double& operator[](int i) = 0;

  //Getters
  virtual int get_tamanho() const = 0;

  //Funcionalidades
  //virtual void add_elem(double x) = 0;

};

#endif
