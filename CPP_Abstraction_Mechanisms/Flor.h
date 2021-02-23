#ifndef FLOR_H
#define FLOR_H
#include <string>
#include "Plantas.h"

class Flor : public Plantas{
public:
  //Delcaração de métodos novos ou que sofreram override
  Flor();
  ~Flor();
  void regar();
  void morrer();
  std::string get_nome();
  void desabrochar();

  //Deletar copy e move construtors:
  Flor(const Flor&) = delete; //Copy Constructor
  Flor(Flor&&) = delete; //Move Constructor
  //OBS: mais uma vez, isso não é necessário pois temos um destrutor declarado
};

#endif
