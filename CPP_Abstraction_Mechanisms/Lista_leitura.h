#ifndef LISTA_LEITURA_H
#define LISTA_LEITURA_H

#include <string>
#include <iostream>
using namespace std;

class Lista_leitura{
public:
  Lista_leitura(int tamanho);
  ~Lista_leitura(); //Destrutor, definida no arquivo .cpp
  void imprimir_lista();
  void adicionar_autor(string autor);
private:
  string *autores;
  int proxIndice;
  int tamanho;
};
#endif
