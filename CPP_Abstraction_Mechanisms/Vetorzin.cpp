#include "Vetorzin.h"
#include <stdexcept>
#include <iostream>
#include <initializer_list>

//Construtores
template<typename Tipo>
Vetorzin<Tipo>::Vetorzin(int t){
  //Exceção: t < 0
  if(t < 0){
    throw std::domain_error{"Vetorzin::Vertorzin(int t)\n O tamanho do contêiner não pode ser menor que 0\n"};
  }
  tamanho = t;

  //Exceção: Sem espaço na memória para a alocação
  try{
    elementos = new Tipo[t];
  }
  catch(const std::bad_alloc& excpt){
    std::cout << "Vertorzin::Vetorzin(int t)\n Não possível alocar memória para o contêiner\n";
  }
}

template<typename Tipo>
Vetorzin<Tipo>::Vetorzin(std::initializer_list<Tipo> init_list){
  tamanho = init_list.size();

  //Exceção: Sem espaço na memória para a alocação
  try{
    elementos = new Tipo[init_list.size()];
  }
  catch(const std::bad_alloc& excpt){
    std::cout << "Vetorzin::Vetorzin(initializer_list<double>& init_list)\n Não foi possível alocar memória para o contêiner\n";
  }

  //Copiar elementos da lista de inicação:
  std::copy(init_list.begin(), init_list.end(), elementos);
}

template<typename Tipo>
Vetorzin<Tipo>::Vetorzin(const Vetorzin& v){
  tamanho = v.tamanho;

  try{
    elementos = new Tipo[v.tamanho];
  }
  catch(const std::bad_alloc& excpt){
    std::cout << "Vetorzin::Vetorzin(const Vetorzin& v)\n Não foi possível alocar memória para o contêiner\n";
  }

  for(int i = 0; i < v.tamanho; ++i){
    elementos[i] = v.elementos[i];
  }
}

template<typename Tipo>
Vetorzin<Tipo>::Vetorzin(Vetorzin && v){
  tamanho = v.tamanho;
  elementos = v.elementos;

  v.elementos = nullptr; //OBS: NÃO DESALOCAR!
  v.tamanho = 0;
}

//Destrutor
template<typename Tipo>
Vetorzin<Tipo>::~Vetorzin(){
  delete[] elementos;
}

//Operadores
template<typename Tipo>
Tipo& Vetorzin<Tipo>::operator[](int i){
  if(i < 0 || i >= tamanho){
    throw std::out_of_range{"Vetorzin::operator[](int i)\n O indice passado ultrapassa os limites do vetor\n"};
  }

  return elementos[i];
}

template<typename Tipo>
Vetorzin<Tipo>& Vetorzin<Tipo>::operator=(const Vetorzin& v){
  tamanho = v.tamanho;

  delete[] elementos;

  try{
    elementos = new Tipo[v.tamanho];
  }
  catch(const std::bad_alloc& excpt){
    std::cout << "Vetorzin::operator=(const Vetorzin& v)\n Não foi possível alocar memória para o contêiner\n";
  }

  for(int i = 0; i < v.tamanho; ++i){
    elementos[i] = v.elementos[i];
  }

  return *this;
}

template<typename Tipo>
Vetorzin<Tipo>& Vetorzin<Tipo>::operator=(Vetorzin&& v){
  tamanho = v.tamanho;
  elementos = v.elementos;

  v.tamanho = 0;
  v.elementos = nullptr;

  return *this;
}

template<typename Tipo>
Vetorzin<Tipo> Vetorzin<Tipo>::operator+(const Vetorzin& v){
  if(v.tamanho != tamanho){
    throw std::length_error{"Vetorzin::operator+(const Vetorzin& v)\n Os vetores não possuem o mesmo tamanho\n"};
  }

  Vetorzin a(tamanho);
  for(int i = 0; i < tamanho; ++i){
    a.elementos[i] = elementos[i] + v.elementos[i];
  }

  return a;
}

//Getters
template<typename Tipo>
int Vetorzin<Tipo>::get_tamanho() const{
  return tamanho;
}

//Funcionalidades
template<typename Tipo>
void Vetorzin<Tipo>::add_elem(Tipo x){

}

template<typename Tipo>
Tipo* Vetorzin<Tipo>::begin(){
  return &elementos[0];
}

template<typename Tipo>
Tipo* Vetorzin<Tipo>::end(){
  return &elementos[tamanho]; //Não é preciso preocupação, esse elemento não é acessado, ele só diz quando parar!
}
