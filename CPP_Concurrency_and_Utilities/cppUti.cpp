#include <string>
#include <vector>
#include <iostream>
#include <thread>

void Funcao_Simulada1(){
  std::cout << "olar\n\n";
}

int Funcao_Simulada2(){
  int num{74};
  int sub{49};

  return (num - sub);
}

void Concurrency(){

  //Para executarmos tarefas simultâneamente, temos o header <thread>.

  std::thread t1{Funcao_Simulada1}; //Cria objeto thread para executar a função
  int b;
  std::thread t2{Funcao_Simulada2};

  t1.join(); //A função "join" garante que não sairemos da função Concurrency() até que a execução da thread termine
  t2.join();

}

int main(){

  //Última Página: 130

  Concurrency();

}
