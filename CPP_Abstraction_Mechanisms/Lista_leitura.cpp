#include <string>
#include <iostream>
#include "Lista_leitura.h"
//using namespace std;

Lista_leitura::Lista_leitura(int tamanho)
  :autores{new string[tamanho]}, proxIndice{0}, tamanho{tamanho}
{
  if(tamanho < 0){
    throw std::length_error("Erro de tamanho!\n");
  }
}

//Deleta o parâmetro alocado na memória dinâmica (heap)
Lista_leitura::~Lista_leitura(){
  delete[] autores;
}

void Lista_leitura::imprimir_lista(){
  for (int i = 0; i < tamanho; i++ ){
    std::cout << autores[i] << "\n";
  }
}

void Lista_leitura::adicionar_autor(string autor){
  autores[proxIndice] = autor;
  proxIndice ++;
}
