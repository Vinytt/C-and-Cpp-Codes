#include <algorithm> //copy(), find(), sort()
#include <array> //array
#include <chrono> //duration, time_point
#include <cmath> //sqrt(), pow()
#include <complex> //complex, sqrt(), pow()
#include <fstream> //fstream, ifstream, ofstream
#include <future> //future, promise
#include <iostream> //istream, ostream, cin, cout
#include <list> //
#include <map> //map, multimap
#include <memory> //unique_ptr, shared_ptr, allocator
#include <random> //deafault_random_engine, normal_distribution
#include <regex> //regex, smatch
#include <string> //string, basic_string
#include <set> //set, multiset
#include <sstream> //istrstream, ostrstream
#include <thread> //thread
#include <unordered_map> //unordered_map, unordered_multimap
#include <utility> //move(), swap(), pair
#include <vector> //vector
#include "Aluno.h"
#include <ios>

void Strings(){
  //Concatenação
  std::string s1 = "oi ";
  std::string s2 = "td bom?\n";
  std::string s = s1 + s2; //OBS: NÃO é possível fazer direto s = "oi " + "td bom?\n" !!!
  std::cout << s;

  //OBS: também é possível concatenar um caractére a uma string

  //OBS': Também é válido fazer:
  s += "\n";

  //Substring
  std::string ps = s.substr(3, 7); //Substring que começa em 3 e têm tamanho 7
  std::cout << ps << "\n";

  //Subistituir (Replace)
  std::string rs = s.replace(3,7, "vsf"); //Subistitui substring por outra string
  std::cout << rs << "\n";

  //toupper e tolower
  s[0] = toupper(s[0]); //Passa para maiúscula (upper case)
  std::cout << s;

  //A função complementar é tolower()

  //Deve ser notado que a função "replace()" não apenas retorna a string alterada, como altera a string sobre a qual é chamada
  //Isso é perceptível já que "s" (string original), sofreu a alteração de "replace()", que não ficou restrita a "rs"
}

void StreamIO(){
  //Output

  std::cout << 10 << "\n";
  //cout converte o int "10" na sequência de caracteres '1' e '0' para imprimí-los na tela
  //OBS: também válidos para variáveis
  //OBS': Usamos mais de um operador "<<" quando temos mais de um tipo de dado diferente!

  int b = 'b'; //o integer b recebe o valor do caractere 'b' na tabela ASCII
  char c = 'c';
  std::cout << 'a' << b << c << "\n";

  //Input

  int i;
  //std::cin >> i; //Lê input como um integer e o armazena em i

  //Para fazer a operação de input acima, é necessário ler uma sequência de caracteres como dados de outros tipos.
  //OBS: um "white space character" (como o próprio "espaço") termina a leitura. Ou seja, caso o input para a operação abaixo seja
  //"Vinicius Ariel", o output ainda será "Vinicius"
  std::string nome;
  //std::cin >> nome;
  //std::cout << nome << "\n\n";

  //Para ler uma linha completa, podemos usar a função "getline()":
  std::string nome_completo;
  std::cout << "Agora, coloque seu nome completo:\n";
  //std::getline(std::cin, nome_completo);
  //std::cout << nome_completo << "\n\n";

  //OBS: Devemos passar todos os cin de uma vez!!!

  //Input e Outbut de tipos definidos por usuários
  //Deve ser feito através de uma definição na class/struct para os operadores "<<" e ">>"
  //Checar classe "Aluno"!

  Aluno* a = new Aluno(7, "Kevin");
  std::cout << *a << "\n"; //Precisamos chamar o objeto com o * para ser uma referência direta ao objeto e não ao espaço de momória no qual está

  std::cout << "\nColocar input em a:\n";
  std::cin >> *a;
  std::cout << *a << "\n";
}

void Conteiners(){

  //Vector

  //Iniciando vetores com tamanhos pré-definidos

  //Ao iniciar um vetor com um tamanho pré-definido, ele tem como padrão elementos nulos: nullptrs para ponteiros, 0 para números.
  //Porém, podemos fazer com que os valores com os quais o vetor é iniciado sejam diferentes:
  //Iniciando vetores com valores customisados

  std::vector<int> v1; //Iniciando um vetor de tamanho 0
  std::vector<int> v2(4); //Iniciando um vetor de tamanho 4
  std::vector<int> v3(3, 9); //Iniciando um vetor de tamanho 4 cujos elementos são iniciados com o valor 9

  std::cout << "v2:\n";
  for(auto x : v2){
    std::cout << x << "\n";
  }

  std::cout << "\n";

  std::cout << "v3:\n";
  for(auto x : v3){
    std::cout << x << "\n";
  }

  std::cout << "\n";

  //push_back() -> função que adiciona um elemento num vetor de tipo correspondente, aumentando automaticamente seu tamanaho

  v3.push_back(7);

  std::cout << "novo v3:\n";
  for(auto x : v3){
    std::cout << x << "\n";
  }

  std::cout << "\n";

  //at(int i) -> retorna um elemento na posição i do vetor, depois de checar se a posição é válida para o tamanho do vetor
  //O operador "[]" NÃO checa os limites do vetor e NÃO gera erro caso a posição seja inválida, apenas retorna um número aleatório na memória

  //List

  //Iteradores: begin() é um iterador que aponta para o primeiro elemento do conteiner
  //end() é um iterador que aponta para o elemento após o último elemento do conteiner

  std::list<int> l1{1, 2, 3};

  l1.insert(l1.end(), 4); //Insert: adciona um elemento na posição anterior à referida pelo iterador
  l1.insert(l1.end(), 5);
  l1.insert(l1.end(), 6);

  l1.erase(l1.begin()); //Erase: deleta um elemento na posição referida pelo iterador

  std::cout << "l1:\n";

  for(auto& x : l1){
    std::cout << x << "\n";
  }

  std::cout << "\n";

  //Map

  //Um array associativo, otimizado para procurar elementos de maneira mais eficiente e não linear.

  //Iniciando um map:
  //Para iniciar um map precisamos de dois valores (que podem ser dados de quaisquer tipos). O primeiro será a "key" e o segundo o "value"
  //Quando indexado pelo valor de uma key, ele retorna o value correspondente

  std::map<std::string, double> m1{ {"Queijo Minas", 3.99}, {"Laranja", 1.99}};
  //No exemplo acima o mapa possui 2 elementos:
  //O primeiro possui key "Queijo Minas" e value 3.99
  //O segundo possui key "Laranja" e value 1.99

  //Chamando elementos por indexação de key:

  std::cout << "Valores do mapa:\n\n";

  std::cout << m1["Queijo Minas"] << "\n";
  std::cout << m1["Laranja"] << "\n";

  //Caso indexamos usando uma chave a qual não foi atribuída um value, NÃO é gerado um erro.
  //Ao invés disto, a key é adicionada ao map com um value padrão (0 para ints, 0.0 para doubles, nullptr para ponteiros, etc)

  std::cout << m1["Chocolate"] << "\n";

  std::cout << "\n";

  //OBS: o custo para do algortimo de procura num map é O(log(n)), sendo n o númeor de elementos no map

  //Unordered_map

  //Diferentemente dos maps tradicionais, o unordered_map tem seus elementos (key e value) guardados sem se preocupar com uma ordenação
  //Isso torna as buscas em seus elementos mais eficientes em alguns casos

  std::unordered_map<std::string, int> um1{ {"cubo", 3}, {"esfera", 7} };

  //Tal como em maps, podemos indexar pela key:

  std::cout << "Valores do mapa inordenado:\n\n";

  std::cout << um1["cubo"] << "\n";
  std::cout << um1["esfera"] << "\n";

  std::cout << "\n";

  //OBS: o custo para o algoritmo de procura num unordered_map é de O(1) para um caso médio, porém O(n) para o pior caso possível
  //sendo n o número de elementos no unordered_map


}

void Algorithms(){

  //Algoritmos padrão implementados pelos conteiners no namespace std

  //sort()
  //Recebe como argumentos dois iteradores. O primeiro aponta onde o sorting deve iniciar e o segundo a posição imediatamente após àquele
  //que o sort termina

  std::cout << "sort():\n\n";

  std::vector<int> v1{3, 6, 19, 39, 10, 40, 999, 0, -5, 47, 2, 2, 2, 2, 2};

  std::sort(v1.begin(), v1.end());

  for(auto x : v1){
    std::cout << x << "\n";
  }

  std::cout << "\n";

  //Caso passemos um interador/ponteiro em posições diferentes do começo e do final:
  std::vector<int> v2{3, 6, 19, 0, 6, 4, 3, 2, 39, 10, 40, 999, 0, -5, 47, 2};

  std::vector<int>::iterator i1 = v2.begin();
  ++i1;
  ++i1;
  ++i1; //Aponta para 0 (posição 3)
  std::vector<int>::iterator i2 = v2.begin();
  ++i2;
  ++i2;
  ++i2;
  ++i2;
  ++i2;
  ++i2;
  ++i2;
  ++i2; //Aponta para 39 (posição 8)

  std::sort(i1, i2);

  //Ordenará o intervalo [3, 8[ de v2
  for(auto x : v2){
    std::cout << x << "\n";
  }

  std::cout << "\n";

  //unique_copy
  //Copia elementos de um conteiner para outro (não precisam ser o mesmo tipo de conteiner) SEM REPETIR valores dos elementos
  //Recebe como argumento 3 iteradores: os dois primeiros são referentes ao conteiner do qual os elementos serão copiados,
  //são a posição na qual a cópia começa e a posição imediatamente após a qual a cópia termina
  //O terceiro iterador é referente ao conteiner para o qual os elementso serão copiados: é a posição na qual o alocamento deve começar

  std::cout << "unique_copy():\n\n";

  std::list<int> l1;

  std::unique_copy(v1.begin(), v1.end(), std::back_inserter(l1));

  //OBS: podemos passar o terceiro iterador como sendo l1.begin() DESDE que a lista tenhha o mesmo tamanho que o número de elementos a serem copiados!
  //Caso apenas queiramos inserir os elementos copiados como novos elementos num conteiner de tamanho qualquer, usamos std::back_inserter(<conteiner>)

  for (auto x : l1){
    std::cout << x << "\n";
  }

  std::cout << "\n";

  //find()
  //Procura por um elemento de determinado valor num certo intervalo de um conteiner, retorna um iterador que aponta para este elemento
  //Caso o valor não esteja presente no conteiner, retorna um iterador que aponta para <conteiner>.end()
  //Como argumentos recebe os iteradores que definem o intervalo no conteiner e o valor a ser procurado

  std::cout << "find():\n\n";

  std::vector<int>::iterator it1 {std::find(v1.begin(), v1.end(), 6)};
  std::vector<int>::iterator it2 {std::find(v1.begin(), v1.end(), 42)};

  if(it1 != v1.end()){
    std::cout << "Elemento com o valor 6 existe em v1!\n";
  }
  else{
    std::cout << "Elemento com o valor 6 não existe em v1!\n";
  }

  std::cout << "\n";

  if(it2 != v1.end()){
    std::cout << "Elemento com o valor 42 existe em v1!\n";
  }
  else{
    std::cout << "Elemento com o valor 42 nao existe em v1!\n";
  }

  std::cout << "\n";

  //Iteradores para iostream

  std::ostream_iterator<std::string> oi {std::cout}; //Faz com que o iterador passe os valores atribuidos ao elemento que aponta para cout

  *oi = "Olar\n";
  ++oi;
  *oi = "Turu bao\n";

  std::istream_iterator<std::string> ii {std::cin}; //Primeiro iterador de input
  std::istream_iterator<std::string> eos{}; //Segundo iterador de input
  //OBS: para inputs, na verdade 2 iteradores são necessários: um para o começo do input e outro para o final

}


int main(){
  //última página: 126

  Algorithms();
}
