#include <iostream>
using namespace std;

// definicao de tipo
struct NO {
	int valor;
	NO* prox;
};

NO* topo = NULL;

// headers
void menu();
void inicializar();
void pop();
void push();
//--------------------------


int main()
{
	menu();
}

void menu()
{
	int op = 0;
	while (op != 4) {
		system("cls"); // somente no windows
		cout << "Menu Pilha";
		cout << endl << endl;
		cout << "1 - Inicializar Pilha \n";
		cout << "2 - Inserir elemento (Push) \n";
		cout << "3 - Remover elementos (Pop) \n";
		cout << "4 - Sair \n";


		cout << "Opcao: ";
		cin >> op;

		switch (op)
		{
		case 1: inicializar();
			break;
		case 2:push();
			break;
		case 3: pop();
			break;
		case 4:
			return;
		default:
			break;
		}

		system("pause"); // somente no windows
	}
}

void inicializar()
{

	// se a lista j� possuir elementos
	// libera a memoria ocupada
	NO* aux = topo;
	while (aux != NULL) {
		NO* paraExcluir = aux;
		aux = aux->prox;
		free(paraExcluir);
	}

	topo = NULL;
	cout << "Pilha inicializada \n";

}


void push()
{
	// aloca memoria dinamicamente para o novo elemento
	NO* novo = (NO*)malloc(sizeof(NO)); //Cria��o do n�
	if (novo == NULL) // Se nao tem memoria disponivel
	{
		cout << "Erro: Mem�ria insuficiente para criar um novo elemento." << endl;
		return; // Retorna sem fazer nada
	}

	cout << "Digite o elemento: "; //Usuario insere o valor
	cin >> novo->valor; // pega o que o usuario colocou e guarda na variavel valor
	novo->prox = NULL; //ultimo da pilha
	novo->prox = topo; //define o proximo elemento como o topo atual
	topo = novo; // colocar o novo como o topo
	cout << "Elemento adicionado com sucesso!" << endl;

}

void pop()
{
	// Primeiro passo: Verficar se a lista est� vazia
	if (topo == NULL)
	{
		cout << "Pilha vazia. Nada para remover." << endl;
		return; //Se estiver vazia retorna sem fazer nada.
	}
	// Segundo passo: Acessar o n� que ser� removido
	NO* paraRemover = topo;
	// Terceiro passo: Mover o topo para o prox, 
	topo = topo->prox;
	// Quarto passo: Mostra ao usu�rio qual elemento vai ser removido
	cout << "Elemento removido: " << paraRemover->valor << endl;
	// Quinto passo: Liberar a memoria do n� que foi removido
	free(paraRemover);

}

