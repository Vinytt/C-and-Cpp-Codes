#ifndef NOVA_LISTA_LEITURA_H
#define NOVA_LISTALEITURA_H

#include <string>
#include <iostream>
using namespace std;

class Nova_Lista_leitura{
public:
  Nova_Lista_leitura(int tamanho);
  ~Nova_Lista_leitura(); //Destrutor, definida no arquivo .cpp

  int get_tamanho();
  string get_autor(int i);

  Nova_Lista_leitura(const Nova_Lista_leitura& a); //Copy Constructor
  Nova_Lista_leitura& operator=(const Nova_Lista_leitura& lista); //Copy Assignment

  Nova_Lista_leitura(Nova_Lista_leitura&& lista); //Move Constructor
  Nova_Lista_leitura& operator=(Nova_Lista_leitura&& lista); //Move Assignment
  //OBS: explicação aos "&&" está na função "mover" do arquivo principal
  //OBS': os moves não usam argumentos const, já que a função deles é esvaziar a instância que recebem e passar seus valores
  //para a próxima variável.

  void imprimir_lista();
  void adicionar_autor(string autor);
private:
  string *autores;
  int proxIndice;
  int tamanho;
};

//Operador de Soma
Nova_Lista_leitura operator+(Nova_Lista_leitura& lst1, Nova_Lista_leitura& lst2);
#endif
