#include <string>
#include <iostream>
#include "Nova_Lista_Leitura.h"

Nova_Lista_leitura::Nova_Lista_leitura(int tamanho)
  :autores{new string[tamanho]}, proxIndice{0}, tamanho{tamanho}
{
  if(tamanho < 0){
    throw std::length_error("Erro de tamanho!\n");
  }
}

//Deleta o parâmetro alocado na memória dinâmica (heap)
Nova_Lista_leitura::~Nova_Lista_leitura(){
  delete[] autores;
}

int Nova_Lista_leitura::get_tamanho(){
  return tamanho;
}

string Nova_Lista_leitura::get_autor(int i){
  return autores[i];
}

//Copy Constructor
Nova_Lista_leitura::Nova_Lista_leitura(const Nova_Lista_leitura& lista)
  :autores{new string[lista.tamanho]}, proxIndice{0}, tamanho{lista.tamanho}
  {
    for(int i = 0; i < lista.tamanho; ++i){
      autores[i]  = lista.autores[i];
    }
    std::cout<<"Copy Constructor\n";
  }

//Copy Operator (=)
Nova_Lista_leitura& Nova_Lista_leitura::operator=(const Nova_Lista_leitura& lista){
  delete[] autores; //Desaloca memória antiga
  autores = new string[lista.tamanho]; //Aloca um novo espaço na memória para este objeto

  //Copia valores
  for(int i = 0; i < lista.tamanho; ++i){
    autores[i] = lista.autores[i];
  }
  tamanho = lista.tamanho;
  proxIndice = lista.proxIndice;
  std::cout<<"Copy Assignment\n";

  return *this; //Retorna o conteúdo do ponteiro para este objeto. Ou seja, uma referência para o mesmo.
}

//Move Constructor
Nova_Lista_leitura::Nova_Lista_leitura(Nova_Lista_leitura&& lista)
  :autores{lista.autores}, proxIndice{lista.proxIndice}, tamanho{lista.tamanho} //"Pega" os elementos de lista e coloca em outra
  //Notemos como um novo espaço na memória não é alocado. O ponteiro para os mesmos dados é transferido para outro objeto apenas
{
  lista.autores = nullptr; //Agora lista não tem mais elementos e pode ser facilmente destruído
  lista.proxIndice = 0;
  lista.tamanho = 0;
  std::cout<<"Move Constructor\n";
}

//Move Assignment
Nova_Lista_leitura& Nova_Lista_leitura::operator=(Nova_Lista_leitura&& lista)
{
  //"Pega" os elementos de lista e coloca em outra
  autores = lista.autores; //Agora aponta para o espaço onde estava alocada os autores de lista, que pode ser de um tamanho
                           //diferente do tamanho original desta lista, mas não causará problemas
  proxIndice = lista.proxIndice;
  tamanho = lista.tamanho;
  std::cout << "Move Assignment\n";

  lista.autores = nullptr; //Agora lista não tem mais elementos
  lista.proxIndice = 0;
  lista.tamanho = 0;

  return *this;
}

//Operador de Soma
Nova_Lista_leitura operator+(Nova_Lista_leitura& lst1, Nova_Lista_leitura& lst2){
  int tamanho_temp{lst1.get_tamanho() + lst2.get_tamanho()};

  Nova_Lista_leitura lst_temp{tamanho_temp}; //Lista temporária para ser retornada

  for (int i = 0; i < tamanho_temp; i++){
    if(i < lst1.get_tamanho()){
      lst_temp.adicionar_autor(lst1.get_autor(i));
    }
    else{
      lst_temp.adicionar_autor( lst2.get_autor(i - lst1.get_tamanho()) );
    }
  }

  return lst_temp;
}

void Nova_Lista_leitura::imprimir_lista(){
  for (int i = 0; i < tamanho; i++ ){
    std::cout << autores[i] << "\n";
  }
}

void Nova_Lista_leitura::adicionar_autor(string autor){
  autores[proxIndice] = autor;
  proxIndice ++;
}
