//Classe abstrata: Plantas
#ifndef PLANTAS_H
#define PLANTAS_H
#include <string>

class Plantas{
public:
  //Como métodos virutais, eles precisam ser implementados pelas subclasses (sofrem override)
  //Sempre que uma classe dá override num método (decide não usar ele como declarado na superclasse)
  //esse método deve ser DECLARADO novamente
  virtual void regar() = 0;
  virtual void morrer() = 0;
  virtual std::string get_nome() = 0;
  virtual ~Plantas(){}

  //Deletar funções de copy e move (por ser uma interface não tem construtors!)
  Plantas& operator=(const Plantas&) = delete; //Copy Assignment
  Plantas& operator=(Plantas&&) = delete; //Move Assignment
  //OBS: como tinhamos definido um destrutor próprio, não precisávamos do delete
};

#endif
