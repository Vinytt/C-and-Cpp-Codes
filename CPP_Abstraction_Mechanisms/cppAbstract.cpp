#include <string>
#include <iostream>
#include <vector>
#include "Num_Complex.h"
#include "Lista_leitura.h"
#include "Nova_Lista_leitura.h"
#include "Ferramenta.h"
#include "Martelo.h"
#include "Plantas.h"
#include "Arvore.h"
#include "Flor.h"
#include "Rosa.h"
#include "Orquidea.h"
#include "Vetorzin.h"
#include "Vetorzin.cpp"

void Comprar_Ferramenta(Ferramenta& f){
  std::cout << f.get_nome() << " comprada(o)!\n";
}

template<typename T>
T primeiro_elemento(Vetorzin<T> v){
  cout << "Primeiro elemento:\n";
  return v[0];
}

template<typename T>
class MenorQue{
public:
  MenorQue(const T& v):valor{v}{}
  bool operator()(const T& x) const{
    return x < valor;
  }
private:
  const T valor;
};

template<typename P>
int Contador_Predicados(std::vector<int> v , P predicado){
  int contador {0};
  for(auto valor : v){
    if(predicado(valor)){
      ++contador;
    }
  }
  std::cout << "\n\n";
  return contador;
}

template<typename Primeiro, typename... Resto>
void imprimir_var(Primeiro param1, Resto... param2){ //param2 representa todos os outros parâmetros que não o primeiro
  std::cout << param1 << "\n";
  imprimir_var(param2...);
}

void imprimir_var(){ //Inevitavelmetne uma hora a função chamará a si mesma sem argumentos:
  std::cout << "FIM\n";
}

template<typename T>
using Element_type = typename T::value_type; //Define Element_type para pegar o tipo de value_type de uma classe T qualquer

template<typename Conteiner>
void criar_vec_mesmo_tipo(Conteiner& c){
  Vetorzin<Element_type<Conteiner>> novo_vec; //Cria um vetor do tipo Element_type, que pega seu valor de Conteiner
}

void classes_concretas(){
  //Classes concretas são aquelas que se comportam semelhantemente a tipos internos (built-in types):
  //Podem iniciadas/instanciadas imediatamente e completamente
  //Podem ser referenciadas diretamente (sem necessidade absoluta de pointeiros* ou referências&)
  //Podem ser colocadas em conjuntos, memória estática ou em outros Objetos
  //Podem ser copiados
  //OBS: para aumentar flexibilidade, geralmente os membros/parâmetros das classes cocnretas são alocados
  //na memória dinâmica (heap).

  //Tipo Aritmético (tipo "mais comum")
  //Verificar Classe Num_Complex
  Num_Complex meu_z{4.5, 9.4};
  meu_z.imprimir();
  Num_Complex outro_z{2.5, 11.6};
  meu_z += outro_z; //Operador definido pelo usuário (overloaded operator)
  meu_z.imprimir();
  outro_z = - outro_z;
  outro_z.imprimir();
  //OBS: Lembrando que não é possível redefinir os operadores de tipos internos!
  //OBS': Instanciando:
  Num_Complex z{3.5, 7.8}; //Alocado na stack memory (para variáveis locais).
                           //Assim que a função em que foi declarada acaba, o objeto é desalocado.

  Num_Complex* w = new Num_Complex{6.7, 8.9}; //Alocado na memória dinâmica (heap, lugar reservado)
                                              //Só pode ser desalocada com um destrutor!
  //OBS'': É uma boa prática sempre destruir tudo que for criado com "new" para preservar memória

  //Destrutores
  //Servem para destruir objetos de uma classe e seus parâmetros sempre que saem do escopo em que
  //foram criados (função em que foram declarados).
  //Esse processo é feito automaticamente e não é necessário chamar os destrutores
  //EX: Checar classe Lista_leitura em Lista_leitura.h
  Lista_leitura minhaLista{3}; //Cria uma lista de leitura
  //Assim que essa função acabar, ela e sua lista de autores serão desalocados da memória dinâmica

  //Contêiner (Container)
  //São objetos que contêm uma coleção de elementos (string, array, vector são todos contêiners)
  //Podemos sempre instanciar vetores do tipo e tamanho desejados (se conhecido), mas existem
  //soluções mais elegantes:

  //Initializer-list Constructor: Inicia uma lista de elementos (std::)
  initializer_list<double> listaD = {2.4, 6.7};
  //List X Vector: Vector aloca os elementos em memória contínua (lado a lado), oque permite random access (acesso mais rápido)
  std::cout << listaD.begin() << "\n"; //Acessa primeira localização da lista (existe para vector também)
  std::cout << listaD.end() << "\n"; //Acessa última localização da lista (existe para vector também)
  //Ao invés de passar um tamanho para o construtor de Lista_leitura, podemos passar uma lista de strings
  //e copiarmos (std::copy) ele para o ponteiro de strings

  //Criar vetor vazio e usar push_back:
  int arrayInts[] {1, 2, 3, 4};
  vector<int> v;
  for(int i = 0; i < 4; i++){
      v.push_back(arrayInts[i]);
  }
  for(int i = 0; i< v.size(); i++){
    std::cout << v[i] << "\n";
  }
}

void std_copy(){
  //std::copy é uma função que copia os elementos de um range[] (de listas, vetores ou arrays) e os aloca
  //numa posição começando em result
  //EX:
  initializer_list<int> listaInts = {1, 2, 3, 4, 5, 6, 7};
  vector<int> v(7); //Note que o vetor já deve ter um tamanho antes de ter os dados copiados para ele

  //Notemos que tanto o range quanto o result=v.begin() são ponteiros (iteradores, na verdade)
  copy(listaInts.begin(), listaInts.end(), v.begin());

  //For com iterador!
  for(vector<int>::iterator it = v.begin(); it != v.end(); it++){
    std::cout << *it << "\n";
  }
}

void classes_abstratas(){
  //Classes que podem ser declaradas mas não instanciadas por não apresentarem uma implementação.
  //Como não sabemos qual será o tamanho de um objeto desse tipo, deveremos sempre alocar os objetos
  //na free store (memória dinâmica) e acessá-los com referências e ponteiros
  //Checar Classe Ferramenta (naturalmente, ela não possui um construtor)

  //Funções que usam classes abstratas:
  //Checar função "Comprar_Ferramenta" no início do código.
  //Ela chama por um objeto da classe abstrata "Ferramenta", mesmo que essa classe não possa ser instanciada.
  //Isso quer dizer que quaisquer instâncias de subclasses de "Ferramenta" podem ser passadas como parâmetro e
  //que a função não faz ideia da implementação das funções que usa.
  //Esse comportamento estende-se naturalmente para qualquer classe com subclasses.
  Ferramenta* meu_martelo = new Martelo();
  Comprar_Ferramenta(*meu_martelo);
  delete meu_martelo; //Chamando destrutor pelo ponteiro!
  //OU
  std::cout << "Outro jeito:\n";
  Martelo meu_martelinho;
  Comprar_Ferramenta(meu_martelinho);
  //Como não foi instanciado com o new, ele é destruído assim que função acaba!

  //OBS: como a função "Comprar_Ferramenta" usa qualquer subclasse de "Ferramenta", ela não precisa ser
  //compilada mais que uma vez para servir para todas as subclasses existentes!

  //Virtual Function Table (vtbl)
  //Quando uma classe abstrata define funções virtuais, a ela e às suas subclasses são adicionados
  //ocultos que apontam para uma tabela de funções, chamada Virtual Function Table (ou Vitrual Method
  //Table). Essa tabela contém também ponteiros, que, em cada classe concreta, aponta para a
  //implementação de cada função.
  //
  //EX: Martelo -> ponteiro para uma vtbl -> vtbl: ponteiro para funções construtor, usar e get_nome ->
  //implementação dessas funções
  //
  //Isso é feito pois em tempo de compilação não é possível definir qual implementação da função deve
  //ser chamada, já muitas vezes a referência é feita para a superclasse. Assim, pode-se definir
  //qual implementação usar em tempo de execução!
  //Objetos de uma mesma classe têm a mesma vtbl. Objetos de classe irmãs têm vtbl semelhantes
  //(ponteiros para as funções aparecem na mesma ordem).
}

void hierarquias(){
  //Observemos a hierarquia de classe:
  //Plantas é uma classe abstrata, que tem como subclasses "Arvore" e "Flor"
  //Tanto Arvore e Flor podem ser instanciadas, cada uma implementando as funções de Plantas além de
  //suas próprias.
  //Flor também tem duas subclasses: Rosa e Orquidea, que implementam novas funções e dão override na
  //função "desabrochar" de flor:

  Arvore minha_arvore{3, 5};
  std::cout << minha_arvore.get_nome() << std::endl;
  minha_arvore.regar();
  std::cout << "Tamanho: " << minha_arvore.get_tamanho() << " Idade: " << minha_arvore.get_idade() << std::endl;
  minha_arvore.morrer();
  std::cout << std::endl;

  Flor minha_flor;
  std::cout << minha_flor.get_nome() << std::endl;
  minha_flor.regar();
  minha_flor.desabrochar();
  minha_flor.morrer();
  std::cout << std::endl;

  Rosa minha_rosa;
  std::cout << minha_rosa.get_nome() << std::endl;
  minha_rosa.regar();
  minha_rosa.desabrochar();
  minha_rosa.morrer();
  std::cout << std::endl;

  Orquidea minha_orquidea;
  std::cout << minha_orquidea.get_nome() << std::endl;
  minha_orquidea.regar();
  minha_orquidea.desabrochar();
  minha_orquidea.morrer();
  std::cout << std::endl;

  //OBS: É possível perceber que quando uma subclasse chama seu destrutor, logo em seguida o destrutor da superclasse
  //é chamado automáticamente (olhar outputs das classes Rosa e Orquidea
  //OBS': Sobre destrutores
}

void ponteiro_inteligente(){
  //A biblioteca unique_ptr<[tipo_de_dado]> serve para implementar ponteiros para objetos específicos e garantir que serão
  //deletados quando unique_ptr sair de escopo

  //unique_ptr é un tipo de ponteiro inteligente, que permite automatizar a deleção de memória dinâmica (heap memory) sem
  //que seja necessário chamar "delete" no código. Isso impede vazamento de memória (memory leak), ou seja, espaço na memória
  //que não está mais sendo usado mas não foi desalocado.
  //OBS: unique_ptr NÃO podem ser copiados

  std::unique_ptr<Flor> flor_ptr{new Flor}; //OBS': Fazer = new Flor NÃO é permitido
  //Assm que essa função acabar, o destructor de Flor será chamado, mesmo não havendo delete
}

void copiar(){
  //Por definição, a maioria dos objetos em C++ podem ser copiados. Isso inclui tipos internos (built-in types) e tipos
  //definidos pelo usuário (uma das exceções é o unique_ptr ali em cima).

  //Cópias simples
  Num_Complex c1{3.4, 7.0};
  Num_Complex c2{c1}; //Cópia por iniciação (Copy Initialization)

  Num_Complex c3;
  c3 = c1; //Cópia por atribuição (Copy Assignment)

  //OBS: Quando "return" é usado para retornar um valor de um tipo definido por usuário e esse valor não é copiado para
  //um novo objeto antes de passar pelo return, o return copia o valor num objeto temporário (que depois é deletado) para
  //poder fazer o retorno.
  //OBS': Uma função que não usa referências ou ponteiros copia seus parâmetros em objetos temporários

  //Copiando Contêiners
  //Cópia de contêiners que usam ponteiros para acessar seus membros com atribuição ou iniciação geralmente é um desastre:
  //Lista_leitura uma um string* autores para acessar os membros de sua lista:
  Lista_leitura lst1{4};
  lst1.adicionar_autor("Moreschi");
  lst1.adicionar_autor("Pereira");
  lst1.imprimir_lista();

  Lista_leitura lst2 = lst1; //Copia lst1 em lst2 (atribuição)
  Lista_leitura lst3{lst1}; //Copia lst1 em lst3 (iniciação)

  lst2.imprimir_lista();
  lst2.adicionar_autor("Bjourne"); //Adicionamos um elemento à lst2...
  lst1.imprimir_lista(); //Mas lst1 TAMBÉM MUDA! (E vice-versa)

  lst3.imprimir_lista(); //naturalmente, o mesmo ocorre com lst3

  //Isso ocorre porque a cópia também copia o ponteiro para a parte de memória alocada no construtor de lst1.
  //Sendo o ponteiro o mesmo, então todas modificações terão efeito na mesma parte da memória e serão propagadas
  //a todos objetos que acessam essa parte da memória.

  //Para resolver isso, definiremos um "copy constructor" e um "copy operator" (=) dentro da classe nova_Lista_Leitura:

  //Copy Constructor
  //Um bom Copy Constructor deve alocar novo espaço para a cópia do contêiner e copiar os valores do original nele
  //nome_class(const nome_class& a); //Forma como deve ser declarado dentro de uma classe
  //Checar classe "Nova_Lista_leitura"!
  std::cout << "NOVA LISTA DE LEITURA: Copy Constructor\n";
  Nova_Lista_leitura lista1{3};
  lista1.adicionar_autor("Moreschi");
  lista1.adicionar_autor("Pereira");

  Nova_Lista_leitura lista2{lista1}; //Inicia 2 com 1
  lista2.imprimir_lista();
  lista2.adicionar_autor("Bjourne");
  std::cout << "Lista1: \n";
  lista1.imprimir_lista();   //Os elementos de "lista1" permanecem agora inalterados!
  std::cout << "Lista2: \n";
  lista2.imprimir_lista();

  //Copy Operator (=)
  //Seu funcionamento é basicamente o mesmo de um copy constructor. Ainda sim, é importante tê-lo definido para possibilitar
  //operações do tipo obj1 = obj2, representando a atribuição dos valores de um objeto de tipo definido pelo usuário para
  //outro de mesmo tipo, ambos já criados e possivelmente iniciados.
  //Ter apenas o Copy constructor limita a cópia à iniciação dos objetos.
  //nome_class& operator=(const nome_class& a); //Declaração dentro de uma classe
  //Checar classe "Nova_Lista_leitura"!
  std::cout << "NOVA LISTA DE LEITURA: Copy Operator\n";
  Nova_Lista_leitura lista3{4};
  lista3.adicionar_autor("Monteiro");
  lista3 = lista1; //Copia 1 em 3
  lista3.adicionar_autor("Moises");
  std::cout << "Lista3: \n";
  std::cout << lista3.get_tamanho() << "\n";
  lista3.imprimir_lista();
  std::cout << "Lista1: \n";
  lista1.imprimir_lista(); //Lista 1 segue inalterada!

  //OBS: ambas funções definidas tipicamente usam "const" em seus argumentos (para receber o objeto que vão copiar)
}

void mover(){
  //Consideremos o operador "+" na função Nova_Lista_leitura. Ele permite somar elementos da classe Nova_Lista_leitura.
  //Sua implementação consiste em criar uma nova instância da classe e retorná-la. Ou seja, uma cópia é feita.
  //No entanto, copiar contêiners grandes pode ter um alto custo computacional. Além disso, a instância criada, uma vez
  //copiada para a varável que recebe o return, nunca mais é usada novamente.
  //Para resolver esse problema, podemos implementar um "Move Constructor" e um "Move Assignment", tal como fizemos com as
  //cópias. Eles serão selecionados automaticamente pelo compilador ao utilizar uma função que use um "rvalue".
  //Checar classe Nova_Lista_leitura!!

  Nova_Lista_leitura listinha1{3};
  listinha1.adicionar_autor("Constantino");
  listinha1.adicionar_autor("Monteiro");
  listinha1.adicionar_autor("Finger");

  Nova_Lista_leitura listinha2{2};
  listinha2.adicionar_autor("Abreu");
  listinha2.adicionar_autor("Bueno");

  Nova_Lista_leitura lista_cons{listinha1 + listinha2};
  lista_cons.imprimir_lista();
  std::cout << "\n";

  Nova_Lista_leitura lista_atr{2};
  lista_atr.adicionar_autor("Arihiko");
  lista_atr.adicionar_autor("Kishimoto");
  lista_atr = listinha1 + listinha2;
  std::cout << "Lista atribuida: \n";
  lista_atr.imprimir_lista();

  //Explicação do "&&": rvalue
  //Em C++, existem os lvalues, ou valores à esquerda. Eles basicamente são um nome para qualquer valor que pode estar
  //na parte da esquerda numa operação de atribuição ("assignment"). Ou seja, são valores que podem receber atribuições.
  //rvalues são os complementos dos lvalues. Ou seja, são valores que não podem receber atribuições. Os "return" e as
  //instanciações temporárias são rvalues.
  //OBS: rvalues são destruídos uma vez que a função que os criou acaba. Por isso, ao usarmos &&, o próprio compilador
  //se prontifica a usar move ao invés de copy nos "return"

}

void restringir_funcoes(){
  //Para quaisquer classes que um destrutor não tenha sido definido pelo usuário, funções "default" são criadas para o
  //destrutor, e operações de "copy" e "move". Para classes dentro de hierarquias, isso pode ser desastroso: Uma função
  //de cópia chamada a partir de um ponteiro de uma superclasse ou interface não sabe quais funções e atributos a
  //subclasse pode ter.
  //Para impedir que existam quaisquer funções que funcionem como copy/move constructor/assignment, incluindo as "default"
  //podemos deletar as funções. Isso gerará um erro caso uma função desse tipo tente ser chamada (return, passar argumentos
  //a funções sem usar referência, etc).
  //OBS: Nada disso é necessário caso o usuário defina um destrutor, já que as funções "default" não serão geradas!
  //Checar interface "Plantas.h" e "Flor.h"

  //Gera um erro na compilação: Plantas.h deletou as funções de copy e move assignment
  //Flor* flor1 = new Flor();
  //Flor* flor2 = new Flor();
  //*flor2 = *flor1;
  //OBS: em Flor.h, deletamos os copy/move construtor, o que não poderia ser feito numa interface (que não pode declarar
  //construtores

  //Podemos voltar a ter copy/move construtor/assignment dando override neles numa subclasse:
  //Checar classe Orquidea!
  Orquidea* orqui1 = new Orquidea();
  Orquidea* orqui2 = new Orquidea();
  *orqui2 = *orqui2;
}

void templates(){
  //Muitas vezes podemos querer que nossa classe tenha atributos que não sejam de um tipo específico, mas possam ser de qualqquer tipo.
  //A classe "std::Vector", por exemplo, é um vetor de elementos que pode ser de qualquer tipo, e não precisa de uma nova implementação
  //para cada um dos tipos que recebe.

  //Para fazer isso, precisamos de um "template", que representa uma classe/tipo ou função indefinida no "header" da classe.
  //Checar classe vetorzin!
  //Uma vez definido o template, devemos ajustar os valores das variáveis, além de declará-lo antes da implementação de qualquer função,
  //mesmo que não use o tipo parametrizável!

  Vetorzin<std::string> vs{"oie", "td", "bao"};
  Vetorzin<int>* vi = new Vetorzin<int>(4);
  Vetorzin<double> vd(7);

  //IMPORTANTE: A implementação das templates PRECISA estar acessível ao compilarmos qualquer arquivo que usa suas funções.
  //Por isso é necessário colocar o #include "Vetorzin.cpp" ali em cima!!

  //OBS: por termos defindo funções "end()" e "begin()", podemos fazer um for in range!
  for(std::string& s : vs){
    std::cout << s << "\n";
  }

  //Templates para funções:
  //Olhar a função "primeiro_elemento", lá em cima. Ela retorna o primeiro elementos de um Vetorzin de tamanho qualquer.
  std::cout << primeiro_elemento(vs) << "\n\n";

  //Functor (ou "Function Objects")
  //São um uso específico para templates: criar um objeto que serve para realizar uma função. Functors são muito usados como
  //argumentos em algorítimos. Eles são úteis pois podem carregar dados sem precisarmos de variáveis globais no código. São
  //funções com estados.
  //Checar o functor "MenorQue" no começo do código!

  //Podemos instanciar MenorQue :
  MenorQue<int> iMQ{3}; //Carrega com ele o valor de comparação "3"
  MenorQue<std::string> sMQ{"a"}; //Carrega com ele o valor de comparação "a"

  std::cout << iMQ(2) << "\n"; //O operador "()" no functor iMQ verifica se 2 < 3
  std::cout << sMQ("b") << "\n"; //verifica se "b" < "a"

  //Funções Lambda (são funções anônimas, não têm nome!)
  //Geram objetos funções IMPLICITAMENTE, e devem ser usadas como parâmetros de funções (predicados!)
  //[&] Gera uma função para todos as variáveis locais do tipo definido, passando-as por referência
  //[=] Gera uma função para todas as variáveis locais do tipo definido, passando-as por valor (assingment)
  //[]
  //[&v] Gera uma função para a variável local "v", passando-a por referência
  //[=v] Gera uma função para a variável local "v", passando-a por valor
  std::vector<int> v_lambda{31, 20, 40, 0, 13, 62, 62};

  //Usando como uma função comum:
  std::cout << "valores iguais a 2x:\n";

  auto menor40 = [](int y){
    bool b {y < 40};
    std::cout << b;
    std::cout << "\n";
    return b;
  };

  for (auto valor : v_lambda){
    menor40(valor);
  }

  //Usando dentro de outra função:
  //Vide declaração da função: Contador_Predicados lá em cima!
  std::cout << "\n\nContador de Predicados!\n";
  std::cout << Contador_Predicados(v_lambda, menor40) << "\n";

  //É importante notar duas coisas:
  //1. A função Contador_Predicados poderia receber qualquer outro predicado (função booleana que verifica algum caso), e funcionaria
  //corretamente.
  //2. É NECESSÁRIO o uso do template<typename P> antes da função que usará a função lambda. Isso se deve ao tipo específico que as
  //funções lambda possuem: elas não possuem um tipo definido pois são uma classe gerada implicitamente pelo compilador!

  //Variadic Templates
  //Usadas para funções que utilizam um número de argumentos variável, SEMPRE recursivas!
  //Checar funções imprimir_var lá em cima!
  //Notemos a necessidade de implementar a função vazia de argumentos (para a última chamada). A cada chamada realizamos uma ação com
  //o primeiro argumento e chamamos a função de novo (recursivamente) para operar com as variáveis restantes

  std::cout << "\n\nFunções com Variadic Templates:\n";

  imprimir_var("nao", "importa", "quantos ou o tipo de argumentos", "sempre funciona", 1, 3.5, 'd');

  //Aliases
  //Muitas vezes é útil usar sinônimos para se referir a tipos, pois permite generalizar funções e solidificar partes do código que
  //são chamadas com frequência.
  //Checar Vetorzin.h e a função criar_vec_mesmo_tipo no início do código!

  //Também podemos usar aliases para nos referirmos a certas implementações de classes:
  using vec_int = Vetorzin<int>;

  vec_int v_int{1, 2, 3}; //Assim, não precisamos ficar chamando Vetorzin<int> todas as vezes. Muito útil para classes com muitos
                          //tipos variáveis

}


int main (){
  templates();

  //Última Página: 98
  return 0;
}
