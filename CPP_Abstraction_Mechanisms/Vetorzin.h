//Classe definida APENAS com o porósito de estudo.
//É importante ressaltar que NÃO se deve tentar redifinir classes já apresentadas pela biblioteca padrão (std), e sim usá-las!
//Última Página: 95

#ifndef VETORZIN_H
#define VETORZIN_H
#include <initializer_list>
#include "Conteiner.h"

template<typename Tipo>

class Vetorzin : public Conteiner{
public:
  //Alias/Sinônimo
  using value_type = Tipo; //A partir de agora, "value_type" será um sinônimo para o Tipo de dado de "Vetorzin"

  //Construtores
  Vetorzin(int t); //Iniciar um vetor de tamanho t
  Vetorzin(std::initializer_list<Tipo> init_list); //Iniciar com uma lista de doubles
  Vetorzin(const Vetorzin<Tipo>& v); //Construtor por cópia (Copy Constructor)
  Vetorzin(Vetorzin<Tipo>&& v); //Construtor por mover (Move Constructor)

  //Destrutor
  ~Vetorzin();

  //Operadores
  Tipo& operator[](int i); //Acessa um elemento
  Vetorzin& operator=(const Vetorzin<Tipo>& v); //Atribuição por cópia (Copy Assignment)
  Vetorzin& operator=(Vetorzin<Tipo>&& v); //Atribuição por mover (Move Assignment)
  Vetorzin operator+(const Vetorzin<Tipo>& v);

  //Getters
  int get_tamanho() const; //Retorna tamanho

  //Funcionalidades
  void add_elem(Tipo x);
  Tipo* begin(); //Funções necessárias para fazer um for in range!
  Tipo* end();

private:
  Tipo* elementos;
  int tamanho;
};

#endif
