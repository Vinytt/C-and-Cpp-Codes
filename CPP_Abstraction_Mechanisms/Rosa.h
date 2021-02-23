//Header Rosa
#ifndef ROSA_H
#define ROSA_H
#include "Flor.h"
#include <string>

class Rosa : public Flor{
public:
  //Delcaração de métodos novos ou que sofreram override
  Rosa();
  ~Rosa();
  void morrer();
  std::string get_nome();
  void desabrochar();
  void regar();
  void presentear(std::string pessoa);
};
#endif
