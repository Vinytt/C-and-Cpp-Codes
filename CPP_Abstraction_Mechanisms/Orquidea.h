//Header Orquidea
#ifndef ORQUIDEA_H
#define ORQUIDEA_H
#include "Flor.h"
#include <string>

class Orquidea : public Flor{
public:
  //Delcaração de métodos novos ou que sofreram override
  Orquidea();
  ~Orquidea();
  void regar();
  void morrer();
  std::string get_nome();
  void desabrochar();
  void perfume();

  //Override para re-implementar o copy/move construtor/assignment
  Orquidea(const Orquidea& orqui); //Copy Constructor
  Orquidea& operator=(const Orquidea& orqui); //Cope Assignment
  Orquidea(Orquidea&& orqui); //Move Constructor
  Orquidea& operator=(Orquidea&& orqui); //Moce Assignment
};
#endif
