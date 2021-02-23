//Classe Abstrata: Ferramenta
//Classes abstratas não possuem construtores ou parâmetros
//OBS: uma classe que serve de interface para mais de uma outra classe é chamada de classe polimórfica
#ifndef FERRAMENTA_H //Definition Guard
#define FERRAMENTA_H
#include <string>

class Ferramenta{
public:
  virtual std::string get_nome() = 0;
  virtual void usar() = 0;
  virtual ~Ferramenta(){} //Mesmo não tendo um construtor, uma classe abstrata pode ter um destrutor.
                         //Elas podem ser destruídas por ponteiro, sem se precupar com a implementação.
                         //Assim, é possível chamar delete Ferramenta para chamar o destrutor de qualquer
                         //classe que a implementa.
  //IMPORTANTE: o destrutor deve ser "implementado" (olha lá, tá com chaves).
  //Caso contrário será uma função sem implementação nenhuma, o que gerará um erro no linker.

  //"virtual" anuncia que a função em questão pode ser redefinida numa subclasse desta classe posteriormente.
  //Esse uso não está restrito à classes abstratas, mas quaisquer classes com subclasses.
  //A notação "=0" indica que a função é puramente virtual, e portanto não será definida nesta classe. Qualquer
  //subclasse de "Ferramenta" deve, necessariamente, implementar essa função.
};

#endif
