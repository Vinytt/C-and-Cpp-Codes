//Subclasse de Ferramenta: Martelo
#ifndef MARTELO_H
#define MARTELO_H

#include "Ferramenta.h"
#include <string>

class Martelo : public Ferramenta{
public:
  Martelo();
  ~Martelo();
  std::string get_nome();
  void usar();
  void fazer_revolucao();
private:
  static std::string martelo_nome;
};

#endif
