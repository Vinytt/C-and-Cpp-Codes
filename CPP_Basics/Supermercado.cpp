//Implementação do namespace supermercado
#include "Supermercado.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

//Implementação da classe Carrinho
supermercado::Carrinho::Carrinho(string dono) //OBS: NÃO é necessário inicializar o vector
  :dono{dono} {}

vector<string> supermercado::Carrinho::get_produtos(){
  return produtos;
}

void supermercado::Carrinho::adicionar_produto(string produto){
  produtos.push_back(produto);
}

string supermercado::Carrinho::get_dono(){
  return dono;
}

//Implementação da função comprar_produtos
void supermercado::comprar_produtos(Carrinho carrin){
  if(carrin.get_produtos().size() == 0){
    throw out_of_range{"supermercado::comprar_produtos\n Vetor de produtos está vazio!\n"};
  }

  for(string produto : carrin.get_produtos()){
    std::cout << "Produto comprado: " << produto << "\n";
  }
}
