//Header para a subclasse árvore de planta
#ifndef ARVORE_H
#define ARVORE_H
#include "Plantas.h"
#include <string>

class Arvore : public Plantas{
public:
  //Delcaração de métodos novos ou que sofreram override
  Arvore(int idade, int tamanho);
  ~Arvore();
  void regar();
  void morrer();
  std::string get_nome();
  int get_idade();
  int get_tamanho();
private:
  int idade, tamanho;
};
#endif
