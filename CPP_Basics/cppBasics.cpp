//Arquivo de prática das função básicas da linguagem C ++
#include <iostream> //Inclui declarações da iostream
#include <vector> //Posibilita o uso de vetores
#include <string>
#include "Gatin.h"
#include "Supermercado.h"
using namespace std; //Faz com que não seja necessário usar std:: ao usar uma declaração da std
#include <curlpp/cURLpp.hpp>
#include <curlpp/Easy.hpp>
#include <curlpp/Options.hpp>

//Struct
struct VetorDoublesS{
	int tamanho; //Será o tamanho de nosso vetor
	double *elementos; //Ponteiro para o array de elementos (já que não sabemos o tamanho do array pra definirmos agora)
};

//Class
class VetorDoublesC{
public: //Funções e dados públicos. Formas de acesso permitidos de qualquer parte
	//Construtor:
	VetorDoublesC(int t); //Construtor
	int get_tamanho(){return tamanho;} //Retorna tamanho do vetor
	double& get_elemento(int indice){return elementos[indice];} //Retorna referência ao elemento na posição indice do vetor
	int set_elemento(double elemento, int indice); //Função ainda não definida (ver abaixo)
	static string nome_classe; //Variável estática
	static void imprimir_nome_classe(){cout << nome_classe << "\n";} //Função estática

private: //Funções e dados privados. Só podem ser acessados e alterados pela própria classe
	int tamanho; //Tamamho do vetor
	double *elementos; //Ponteiro para o array de elementos
};
//Definição do construtor
VetorDoublesC::VetorDoublesC(int t)
	:tamanho{t}, elementos{new double[t]}
{
	if(t < 0 ){
		throw length_error("Erro de Tamanho");
	}
}
//Definição da função usando o operador de escopo de resolução "::"
int VetorDoublesC::set_elemento(double elemento, int indice){
	elementos[indice] = elemento;
	return 1;
}
//Iniciação da Variável estática
string VetorDoublesC::nome_classe = "Vetor de Doubles";

//Enumerador
enum class Cores{vermelho, azul, amarelo};
//Definindo novos operadores (Serve para classes também!)
Cores& operator++(Cores& c){ //Recebe uma referência ao um objeto Cores
	switch (c) {
		case Cores::vermelho:
			return c = Cores::azul;
		case Cores::azul:
			return c = Cores::amarelo;
		case Cores::amarelo:
			return c = Cores::vermelho;
		default:
			return c = Cores::vermelho;
	}
}

int x = 10;

//Declarar funções
void print_Nome(string nome) {
	cout << "Meu nome e " << nome << "!\n"; //printar strings e variáveis
}

constexpr int AoQuadrado(int num) {
	return num * num;
}

void IniciarVariaveis() {
	//Iniciar vairáveis
	int i = 4; //= faz conversão de tipos
	int t{ 4 }; //{} não faz (salva tempo)
	cout << t << "\n";

	int b = 7.5; //b = 7 (convertido)
	//int b{7.5}; -> erro pois 7.5 não é int
	cout << b << "\n";

	//Iniciando variáveis com "auto" -> automaticamente identifica o tipo da variável pelo inicialização
	auto ai = 5; //5 é um int, portanto b é do tipo int
	auto ac = 'x'; //"x" é um char, então ac será do tipo char
	//Aqui usamos o "=" em todos os casos porque sempre há uma conversão de tipos

}

void Vetores() {
	//Vetores -> precisa declarar tipo dentro dos <>
	vector<int> v{ 1, 3, 6, 8 };
	vector<double> vd{ 2.0, 5.6 };

	//Acessando valores:
	cout << v[2] << "\n";

	//Primeira posição
	vector<int>::iterator b = v.begin(); //Retorna um iterador que aponta para o elemento inicial
	vector<int>::iterator e = v.end();   //Retorna um iterador que aponta para o elemento final
	//OBS: iteradores são uma generalização de ponteiros!
	//ERRO: iteradores NÃO possum valor próprio!
	//cout << b << "\n";
	//cout << e << "\n";

	//Tamanho: (retorna o número de elementos!)
	cout << v.size() << "\n";

	//Colocar novos elementos:
	vd.push_back(0.78); //Adiciona o elemento no final do vetor
	cout << vd[2] << "\n";
	cout << vd.size() << "\n";

	//Vetor X Array: vetores usam mais memória e têm tamanho dinâmico. Além disso o tempo de acesso a um lemento num vetor
	//varia em relação a sua posição no vetor
}

void Constantes() {
	//Constantes
	const int constante = 4; //Valor que não pode ser mudado
	constexpr int constanteQ = AoQuadrado(constante); //Avalia o valor (que é imutável) apenas em tempo de compilação
	//constexpr facilita performance e reserva um lugar da memória para o valor da expressão
	//OBS: para constexp funcionar a função que ela chama também deve ser uma constexpr!

}

void Inputs() {
	//Inputs
	cout << "Proceder?\n";
	char resposta{ ' ' };
	cin >> resposta; //Guarda input do usuário na variável resposta
	cout << resposta << "\n";

}

void TestesANDSwitches() {
	cout << "Proceder?\n";
	char resposta{ ' ' };
	cin >> resposta;

	//Testes
	if (resposta == 's') {
		cout << ":)\n";
	}
	else {
		cout << ":(\n";
	}

	//Switches -> ação baseada no valor de um parâmetro que é comparado com CONSTANTES em cada caso
	switch (resposta) {
	case 's':
		cout << "s2\n";
		break; //Se não colocar o break ou return o código entra em TODOS os casos, cuidado
	case 'n':
		cout << "s/2\n";
		break;
	default:
		cout << "confuso estou\n";
		break;
	}

}

void Incrementos() {
	//Incrementos
	int k{ 1 };
	int j{ k++ };
	//Nesse caso k = 2 e j = 1, pois k++ retorna o valor antigo de k
	cout << k << "\n";
	cout << j << "\n";

	j = ++k;
	//Agora k = 3 e j =3, pors ++k retorna o novo valor de k
	cout << k << "\n";
	cout << j << "\n";

	//Nenhum deles é muito melhor que o outro em termos de perfomance pois o compilador otimiza esses processos
	//da mesma maneira

}

void Arrays() {
	//Arrays
	char arrayChar[5]{'s', 'h', 'i', 't', '!'}; //Array de que contém 5 chars, indexados de 0 a 4
	cout << arrayChar[3] << "\n"; //Acessando elementos do Array

	int arrayInt[]{ 1, 2, 3, 4, 5 }; //array de tamanho indefinido (precisa ser declarado)

	//Array x Vector: Arrays têm tamanho constante (por isso é preciso declará-los quando não se especifica um tamanho).
	//Assim, gastam menos memória e o acesso a um elemento em qualquer posição leva o mesmo tempo.
}

void CharsANDStrings() {
	//Aspas simples representam objetos da classe char
	char x = 'x';

	//Apas duplas representam objetos da classe string literal, um array de chars
	string str = "ola!";
	//OBS: strings literal são compostas de seu conteúdo e um null terminator no final (elemento nulo)
	//Assim, a string str acima é um array de 5 elementos e não 4!
}

void PonteirosANDReferencias() {
	char x = 'x';

	//Ponteiros
	char* ponteiroChar; //ponteiro que aponta para um objeto da classe char

	ponteiroChar = &x; //o "&" faz com que ponteiroChar aponte para x. Ou seja, ponteiroChar contém a posição de
					   //memória de x

	cout << ponteiroChar << "\n";

	//Encontrar o objeto para o qual o ponteiro está apontando:
	cout << *ponteiroChar << "\n";

	//Podemos interpretar então: & -> "endereço de" ; * -> "conteúdo em"

	//Ponteiros podem ser incrementados para apontar para o próximo valor de uma array:
	char arrayChar[3]{ 'n', 'r', 'o' };

	char *pontArrChar; //OBS: char* pontArrChar ou char * pontArrChar são EXATAMENTE a mesma coisa

	pontArrChar = arrayChar;

	cout << "Ponteiro Char1: " << *pontArrChar << "\n";
	pontArrChar++;
	cout << "Ponteiro Char 2: " << *pontArrChar << "\n";


	//Referências
	char& refChar = x; //referência a um objeto da classe char
					   //refChar não guarda o valor do objeto, apenas referencia seu valor sempre que chamado.
					   //Portanto, mudanças em refChar também mudam o valor de ac!

	refChar = 'g';
	cout << x << "\n";

	//Ponteiros Nulos (nullptr)
	//Equivalente de NULL, mas apenas para ponteiros.
	int* pointInt = nullptr;

	//OBS: todos ponteiros com nullptr apontam para o mesmo lugar
	//OBS': nullptr pode ser convertido para um booleano, que é falso
}

void Lacos() {
	//Laços ou Loops
	int contador = 0;
	while (contador < 4) {
		cout << contador << "\n";
		contador++; //C++ >>>>>> python
	}

	for (int cont = 0; cont < 3; cont++) {
		cout << cont << "\n";
	}

	//For-Range!
	int array[]{ 1, 2, 3 };
	for (int x : array) { //Temos cada um dos elementos da lista copiados em x:
		cout << x << "\n";
		//OBS: nesse caso cada um dos elementos da lista é copiado na variável x
		//Mas podemos usar uma referência auto& x : lista para que x se torne uma referência a esses elementos
	}

	for (double x : {2.2, 4.5}) { //Podemos colocar a lista direto no for também
		cout << x << "\n";
	}

	//For com Iterador! Válido para todos os tipos básicos de contêiners (vector, list)
	initializer_list<int> lista = {4, 5, 6};
	for(initializer_list<int>::iterator it = lista.begin(); it != lista.end(); it ++){
		cout << *it <<"\n";
	}
}

void OperadorNew(){
	//Num código, as memória necessária é definida antes da execução com a delcaração de variáveis. Porém,
	//podemos alocar memórias dinamicamente (em tempo de execução) usando os operadores "new" e "new[]".
	//Esses operadores iniciam um objeto de determinada classe se houver memória suficiente.
	int *ponteiro;
	ponteiro = new int; //OBS: os operadores new retornam PONTEIROS!
	cout << ponteiro << "\n"; //printa posição na memória
	*ponteiro = 7;
	cout << *ponteiro << "\n"; //printa valor do inteiro

	ponteiro = new int[4]; //Aloca memória para 4 ints, e o ponteiro aponta para o 1º elemento
	cout << ponteiro << "\n"; //printa posição na memória do primeiro elemento
	ponteiro[0] = 4; //ACESSO AOS ELEMENTOS É DIRETO!!!!! EU AMO CPP
	ponteiro[1] = 87;
	cout << ponteiro[0] << "\n"; //printa valor do elemento na posição 0
	cout << *ponteiro << "\n"; //printa valor do primeiro elemento
	ponteiro++;
	cout << *ponteiro << "\n"; //agora printa o segundo elemento

}

void vetor_doubles_constr(VetorDoublesS& v, int t){
	//Construtor do nosse struct VetorDoubles
	v.tamanho = t;
	v.elementos = new double[t]; //Alocando memória para o array de elementos
	cout << "Vetor de tamanho " << t << " construido!\n";
	//OBS: precisamos de uma referência (&) pois do contrário a função construtora apenas copiaria o vetor passado
	//em outro objeto, não alterando o valor do original! As alterções na referência alteram o original!

	//OBS': caso tivéssemos um ponteiro ao invés de uma referência (VetorDoubles *v), teríamos que acessar os valores
	//da seguinte maneira: v->tamanho;
	//Além disso precisaríamos chamar o construtor com vetor_doubles_constr(&v, t);
}

void TipoStruct(){
	//Assim como uma classe, Struct é um tipo de dado definido pelo usuário. A principal diferença entre
	//ambas é que, por definição, os parâmetros das classes são privados e os dos Structs são públicos.

	//Declarando Struct:
	//Checar a delcaração "Struct" no começo do código. A delcaração não deve ser feita dentro de uma
	//função específica, para que todas a outras possam identificá-la também.

	//Construtor:
	//Checar função Construtor logo aacima. Em C++, não podemos ter uma declaração de função dentro de
	//outra, salvo usando algumas ferramentas expeciais (lambdas). Toda função deve ser declarada ANTES
	//de ser chamada pela primeira vez, pois a leitura do código é direta.

	//Usando o tipo definido:
	VetorDoublesS vtzin; //Declarando
	int t;
	cout << "Digite o tamanho do vetor:\n";
	cin >> t;

	vetor_doubles_constr(vtzin, t); //Iniciando

	cout << "Digite os valores do vetor\n";
	for(int i = 0; i < t; i++){
		cin >> vtzin.elementos[i]; //Definindo elementos
	}

	double soma = 0.0;
	for(int j = 0; j < t; j++){
		soma += vtzin.elementos[j]; //Acessando elementos
	}
	cout << soma;

}

void TipoClass(){
	//Seus membros (parâmetros) são apenas acessíveis através de sua própria interface. Eles são privador ao menos
	//que se especifique o contrário.

	//Declarando classe:
	//Checar a declaração no início do código. Ela deve ser feita fora de uma função específica para que todas as
	//funções do código possam identificá-las
	//OBS: o construtor e todas funções já podem ser definidas na declaração da classe (mas eu acho isso um pouco
	//bagunça)
	//OBS': as variáveis de uma classe também podem ser chamadas de "parâmetros" ou "membros"!

	//Usando o tipo definido:
	int t = 2;
	VetorDoublesC vtzin(t); //Iniciando um vetor de tamanho 4 de nome vtzin
	vtzin.set_elemento(4.5, 0);
	vtzin.set_elemento(3.5, 1);

	cout << vtzin.get_tamanho() << "\n";
	cout << vtzin.get_elemento(1) << "\n";

	double soma = 0.0;
	for (int i = 0; i < vtzin.get_tamanho(); i ++){
		soma += vtzin.get_elemento(i);
	}

	cout << soma << "\n";

	//OBS: lembrar de usar definition guards para todos os headers!

}

void StaticKeyword(){
	//Usos da palavra reservada "static"

	//Varáveis estáticas em uma função
	//Quando uma variável de função é declarada como estática, espaço na memória é alocado/reservado para ela
	//até que o programa ACABE
	//Mesmo que a função seja chamda múltiplas vezes, o espaço é alocado apenas uma vez, de forma que o valor
	//da variável ao final de uma chamda será o valor inicial dessa mesma variável no início da próxima.
	static int contador = 0; //OBS: isso não reseta o valor da variável para 0, só inicializa com 0
	cout << contador << "\n";
	contador++;
	//Experimentemos chamar essa função múltiplas vezes na main() ver o resultado

	//Variáveis estáticas em uma classe
	//Ao defirmos uma classe que tenha uma de suas variáveis delcarada como estática, essa variável será a mesma para
	//TODOS objetos instanciados desta classe. Terá o mesmo endereço único (alocado apenas uma vez) e, naturalmente,
	//o mesmo valor.
	//OBS: variáveis estáticas NÃO podem ser inicializadas nos construtores
	VetorDoublesC v1(3);
	VetorDoublesC v2(4);

	cout << v1.nome_classe << "\n"; //Variável estática foi declarada na classe e inicializada fora dela
	cout << v2.nome_classe << "\n";
	cout << VetorDoublesC::nome_classe << "\n"; //Pode ser chamado diretamente da classe, sem instanciação

	//Funções estáticas em uma classe
	//Tal como as variáveis, as funções estáticas não dependem dos objetos e são as mesmas para todos. No entanto,
	//ela pode ser definida dentro da própria classe, caso se deseje.
	VetorDoublesC::imprimir_nome_classe(); //Também pode ser chamada diretamente da classe, sem instanciação

	//Objetos estáticos (instanciação estática)
}

void ScopeResolutionOperator(){
	//O operador "::" tem vários usos ineressantes

	//Diferenciação de variáveis globais e variáveis locais
	int x = 7;
	cout << "x local: " << x << "\n";  //printa o x definido nesta função
	cout << "x global: " << ::x << "\n"; //printa o x definido no início do código

	//Definir uma função fora da declaração da classes
	//Checar a definição da função "set_elemento "da Classe "VetorDoublesC" logo abaixo da declaração da classe,
	//no início do código

	//Acessar vairáveis estáticas de uma classe (como demonstrado anteriormente)
	//Também pode ser usado para diferencair caso haja outra variável com o mesmo nome:
	string nome_classe = "tem classe aqui nao";
	cout << nome_classe << "\n";
	cout << VetorDoublesC::nome_classe << "\n";

	//Diferenciação de classes/funções de mesmo nome quando se utiliza múltiplos namespaces
	//Imagine que esteja-se utilizando além do "std" um outro namespace que também define uma classe "cout":
	std::cout << "olar!" << std::endl;

	//Importar apenas uma função/classe específica de um namespace
	//Se quisermos apenas importar o "cout" do namespace "std", devemos colocar no início do código:
	//using std::cout;

	//Diferenciação de variáveis de mesmo nome em heranças múltiplas
}

void TipoEnumeracaoes(){
	//Um tipo de dado definido por usuário que é mais simples que class e struct na qual podemos enumerar valores.
	//É para representar conjuntos pequenos de forma simples, minemônica.

	//Declaração e inicialização
	//enum class Cores{vermelho, azul, amarelo}; -> Agora definida no início do código!
	enum class Semaforo{vermelho, amarelo, verde};
	//OBS: Os enumeradores podem ser usados com o mesmo nome em diferentes enumerações sem confusão

	//Instanciação
	Cores cor1 = Cores::vermelho;
	Semaforo cor_semaforo = Semaforo::vermelho;

	//Operadores
	//Por definição, as enumerações só têm as inicializações, acessos (::), atribuições (=) e
	//comparações (==, >, <, >=, <=):
	Cores cor2 = Cores::azul;
	cout << (cor1 == cor2) << "\n";
	cout << (cor1 < cor2) << "\n";
	cout << (cor1 > cor2) << "\n";
	//OBS: "azul" é declarado posteriormente a vermelho, portanto cor2 > cor1

	//Definindo novos operadores: definindo prefixo ++
	//Checar início do código! Não dá pra declarar o função da enum class localmente!
	Cores cor3 = ++cor2;
	if(cor3 == Cores::amarelo){
		cout << "Deu certo!\n";
	}

}

void Modularizacao(){
	//Podemos fazer a declaração de Classes, Enumerations e Structs em um arquivo separado (header, .h), que será
	//compilado separadamente também. Isso reduz o tempo de compilação e minimiza as chances de erros por separar
	//partes logicamente distintas do programa.

	//Definiremos uma nova classe "Gatin" num arquivo "Gatin.h" e a incluiremos neste código fonte usando "#include".
	//A implementação da classe "Gatin" também estará a num arquivo separado ("Gatin.cpp")
	//Abaixo, acessaremos a classe normalmente, como qualquer outra.

	Gatin ramona("marrom", 8);
	Gatin teco("cinza", 11);

	cout << "Dono: \n";
	cout << ramona.dono << "\n";
	cout << teco.dono << "\n";

	cout << "Miar:\n";
	ramona.miar();
	teco.miar();

	cout << "Peso:\n";
	cout << ramona.get_peso() << "\n";
	cout << teco.get_peso() << "\n";

	cout << "Cor:\n";
	cout << ramona.get_cor() << "\n";
	cout << teco.get_cor() << "\n";

	//OBS: Compilação com múltiplos arquivos .cpp (como é o caso agora):
	//Deve-se passar TODOS os arquivos .cpp para o compilador (MAS NÃO O HEADER .h)
	//EX: cl cppBasics.cpp Gatin.cpp

}

void Namespaces(){
	//Separar declarações deferentes que tenham o mesmo nome
	//Namespaces podem conter classes, funções, e constantes, que podem ser chamadar seguindo o exemplo:
	//namespace::funcao();
	//OBS: com a palavra reservarda "using" não é necessário usar o Scope Resolution Operator (::), checar acima

	//Declaração e Implementaçãonce
	//Tal como ocorre em classes, namespaces devem ser declarados em headers (.h) e implementados em arquivos fontes (.cpp)
	//Uma função que usa um namespace deve também incluir seu .h, a menos que seja std (standart library)

	supermercado::Carrinho meu_carrinho("Vinicius");

	meu_carrinho.adicionar_produto("Pera");
	meu_carrinho.adicionar_produto("Brocolis");
	cout << "Dono: " << meu_carrinho.get_dono() << "\n";

	supermercado::comprar_produtos(meu_carrinho);

}

void ManejamentoDeErros(){
	//Jogar exceção: Agora, a classe carrinho gera um erro se tentar comprar produtos com o carrinho vazio
	//Deve-se declarar o tipo de exceção e a mensagem que ela mostrará. É de extrema importância sempre definir
	//quais são as condições mínimas para que uma função funcione e definir erros adequadamente

	supermercado::Carrinho carrin("Vinicius");

	//Try-Catch
	try{ //Tenta executar os seguintes comandos:
		supermercado::comprar_produtos(carrin);
	}
	catch (out_of_range){ //Captura exceções do tipo "out_of_range"
		cout << "Erro!\n";
	}

	//Invariantes
	//São as condições mínimas para que uma classe funcione corretamente. As outras funções da classe devem pressupor
	//que essas condições são satisfeitas sempre que são chamadas. Portanto, os invariantes devem ser definidos no
	//próprio construtor da classe
	//EX: checar construtor da classe VetorDoublesC no início deste código

	//Declaração Estática (Static Assertion)
	//Exceções reportam erros em tempo de execução, mas, se possível, é melhor encontrar erros em tempo de compilação
	//Coisas que podemos verificar em tempo de compilação: tamanho de variável, tipos
	//Ex: checar construtor da classe Gatin, no arquivo Gatin.cpp
	//a static_assert(a, s) checa se a expressão "a" é veradeira, e, se não for, printa a expressão "s"

}

void sizeof_Operator(){
	//sizeof é um oprerador muito útil que retorna o tamanho, em bytes, de um tipo ou de um objeto
	cout << "Tamanho do tipo 'int': " << sizeof(int) << "\n";

	int i{1};

	cout << "Tamanho de i: " << sizeof(i) << "\n";

	//Também pode ser usada para tipos definidos pelo usuário!
	cout << "Tamanho da classe 'Gatin': "  << sizeof(Gatin) << "\n";
}

//OBS: Não é necessário pedir para executar a main, isso é feito automaticamente
int main() {

	//Vetores();

	//Última Página: 75
	return 0;
}
