//Declaração do namespace supermercado
#include <string>
#include <iostream>
#include <vector>
using namespace std;

namespace supermercado{
  class Carrinho{
  public:
    Carrinho(string dono);
    vector<string> get_produtos();
    void adicionar_produto(string produto);
    string get_dono();
  private:
    vector<string> produtos;
    string dono;
  };

  void comprar_produtos(Carrinho carrin);
}
