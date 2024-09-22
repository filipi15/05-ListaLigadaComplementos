#include <iostream>
using namespace std;

// definicao de tipo
struct NO {
	int valor;
	NO* prox;
};

NO* primeiro = NULL;
NO* ultimo = NULL;

// headers
void menu();
void inicializar();
void exibirQuantidadeElementos();
void exibirElementos();
void inserirElemento();
void excluirElemento();
void buscarElemento();
NO* posicaoElemento(int numero);
//--------------------------


int main()
{
	menu();
}

void menu()
{
	int op = 0;
	while (op != 7) {
		system("cls"); // somente no windows
		cout << "Menu Lista Ligada";
		cout << endl << endl;
		cout << "1 - Inicializar Lista \n";
		cout << "2 - Exibir quantidade de elementos \n";
		cout << "3 - Exibir elementos \n";
		cout << "4 - Buscar elemento \n";
		cout << "5 - Inserir elemento \n";
		cout << "6 - Excluir elemento \n";
		cout << "7 - Sair \n\n";

		cout << "Opcao: ";
		cin >> op;

		switch (op)
		{
		case 1: inicializar();
			break;
		case 2: exibirQuantidadeElementos();
			break;
		case 3: exibirElementos();
			break;
		case 4: buscarElemento();
			break;
		case 5: inserirElemento();
			break;
		case 6: excluirElemento();
			break;
		case 7:
			return;
		default:
			break;
		}

		system("pause"); // somente no windows
	}
}

void inicializar()
{
	// se a lista já possuir elementos
// libera a memoria ocupada
	NO* aux = primeiro;
	while (aux != NULL) {
		NO* paraExcluir = aux;
		aux = aux->prox;
		free(paraExcluir);
	}

	primeiro = NULL;
	cout << "Lista inicializada \n";

}

void exibirQuantidadeElementos() {

	int nElementos = 0;
	NO* aux = primeiro;
	while (aux != NULL) {
		nElementos++;
		aux = aux->prox;
	}
	cout << "Quantidade de elementos: " << nElementos << endl;

}

void exibirElementos()
{
	if (primeiro == NULL) {
		cout << "Lista vazia \n";
		return;
	}
	else {
		cout << "Elementos: \n";
		NO* aux = primeiro;
		while (aux != NULL) {
			cout << aux->valor << endl;
			aux = aux->prox;
		}
	}
}

void inserirElemento()
{
	// aloca memoria dinamicamente para o novo elemento
	NO* novo = (NO*)malloc(sizeof(NO));
	if (novo == NULL)
	{
		return;
	}

	cout << "Digite o elemento: ";
	cin >> novo->valor;
	novo->prox = NULL;

	if (primeiro == NULL)
	{
		primeiro = novo;
		ultimo = novo;
	}
	else
	{
		NO* aux = primeiro;
		while (aux != NULL) {
			if (novo->valor > aux->valor) {
				if(primeiro->prox != NULL){
					ultimo->prox = novo;
					ultimo = novo;
				}
				else
				{
					primeiro->prox = novo;
					ultimo->prox = novo;
					ultimo = novo;
					break;
				}
			}
			else if (novo->valor == aux->valor) {
				cout << "Este elemento já existe.";
				break;
			}
			else {
				NO* sucessor = primeiro;
				if (primeiro->prox == NULL) {
					primeiro = novo;
					primeiro->prox = sucessor;
				}
				else{
					if(primeiro->valor < novo->valor){
						while (primeiro->valor < novo->valor) {
							primeiro = primeiro->prox;
						}
						sucessor->prox = novo;
						novo->prox = primeiro;
						primeiro->prox = NULL;
						primeiro = sucessor;
						break;
					}
					else
					{
						primeiro = novo;
						novo->prox = sucessor;
						break;
					}
				}
			}
			aux = aux->prox;
		}
	}
}

void excluirElemento()
{
	if (primeiro == NULL) {
		cout << "Lista vazia \n";
		return;
	}
	else {
		int excluirElemento = NULL;
		cout << "Digite o valor do elemento que deseja excluir: " << endl;
		cin >> excluirElemento;

		if (posicaoElemento(excluirElemento) == NULL)
		{
			cout << "ELEMENTO NAO ENCONTRADO" << endl;
			return;
		}

		NO* ponteiroElemento = posicaoElemento(excluirElemento);
		NO* aux = primeiro;
		NO* elementoAnterior = NULL;
		NO* elementoPosterior = NULL;

		while (aux != NULL)
		{
			if (aux->prox == ponteiroElemento) {
				elementoAnterior = aux;
			}
			if (aux == ponteiroElemento) {
				if (aux->prox == NULL) {
					break;
				}
				else {
					elementoPosterior = aux->prox;
				}
			}
			aux = aux->prox;
		}

		if (elementoAnterior != NULL) {
			elementoAnterior->prox = elementoPosterior;
		}
		else {
			primeiro = elementoPosterior;
		}
		free(ponteiroElemento);
	}
}

void buscarElemento()
{
	int buscarElemento = NULL;
	cout << "Digite o valor do elemento que deseja buscar: " << endl;
	cin >> buscarElemento;

	if (posicaoElemento(buscarElemento) != NULL)
	{
		cout << "ENCONTRADO" << endl;
	}
	else
	{
		cout << "ELEMENTO NAO ENCONTRADO" << endl;
	}
}


