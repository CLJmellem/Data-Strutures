//Domingos Soares do Carmo Neto - TIA: 32032889
//Cássio Luis Junqueira Mellem Filho - TIA: 32089694
#include <iostream>
#include "deque.h"


using namespace std;

int main()
{
	setlocale(LC_ALL, "pt_BR");

	StaticDeque deque = Create();

	char user;
	int elem;


	do
	{
		cout << "\n-------------------------------------------------------------";
		cout << "\nEscolha uma das opções abaixo: \n";
		cout << "\n[0]InsertFront (Insere um elemento no inicio da fila)\n";
		cout << "[1]InsertBack (Insere um elemento no final da fila)\n";
		cout << "[2]RemoveFront (Remove o primeiro elemento)\n";
		cout << "[3]RemoveBack (Remove o ultimo elemento)\n";
		cout << "[4]Front (Retorna qual elemento esta na frente)\n";
		cout << "[5]Back (Retorna qual elemento esta por ultimo)\n";
		cout << "[6]Size (Retorna a capacidade da fila) \n";
		cout << "[7]Count (Retorna a quantidade de elemento na fila) \n";
		cout << "[8]IsEmpty (Mostra se a fila esta vazia)\n";
		cout << "[9]Clear (Remove todos os elementos da fila)\n";
		cout << "[a]Sair\n";
		cout << "------------------------------------------------------------- \n";
		cin >> user;

		bool full = IsFull(deque);
		switch (user)
		{
		case '0':
			if (full == true)
			{
				cout << "Deque cheio!";
				break;
			}
			else
			{
				cout << "Digite o número a ser inserido no inicio da fila: \n";
				cin >> elem;
				InsertFront(deque, elem);
				cout << "Front: \n";
				Front(deque);
				for (int i = 0; i < STATIC_DEQUE_CAPACITY; i++)
				{
					cout << deque.values[i] << " ";
				}
				break;
			}

		case '1':
			if (full == true)
			{
				cout << "Deque cheio!";
				break;
			}
			else
			{
				cout << "Digite o número a ser inserido no fim da fila: \n";
				cin >> elem;
				InsertBack(deque, elem);
				cout << "Back: \n";
				Back(deque);
				for (int i = 0; i < STATIC_DEQUE_CAPACITY; i++)
				{
					cout << deque.values[i] << " ";
				}
				break;
			}
		case '2':
			cout << "\nRemove o valor no começo da fila: \n";
			RemoveFront(deque);
			cout << "Fila com Front removido: ";
			for (int i = 0; i < STATIC_DEQUE_CAPACITY; i++)
			{
				cout << deque.values[i] << " ";
			}
			break;


		case '3':
			cout << "\nRemove o valor no começo da fila: \n";
			RemoveBack(deque);
			cout << "Fila com Back removido: ";
			for (int i = 0; i < STATIC_DEQUE_CAPACITY; i++)
			{
				cout << deque.values[i] << " ";
			}
			break;

		case '4':
			cout << "Retorna o elemento no começo da Fila: \n" << Front(deque);
			break;

		case '5':
			cout << "Retorna o elemento no final da Fila: \n" << Back(deque);
			break;

		case '6':
			cout << "Capacidade da Fila: \n" << Size(deque);
			break;
		case '7':
			cout << "Quantidade de elementos na fila: \n" << Count(deque);
			break;
		case '8':
			cout << "Retorna false[0] se a fila não estiver vazia ou true[1] se a fila estiver vazia: \n" << IsEmpty(deque) << "\n";
			for (int i = 0; i < STATIC_DEQUE_CAPACITY; i++)
			{
				cout << deque.values[i] << " ";
			}
			break;
		case '9':
			cout << "Remove todos os elementos da fila:" << Clear(deque) << "\n";
			for (int i = 0; i < STATIC_DEQUE_CAPACITY; i++)
			{
				cout << deque.values[i] << " ";
			}
			break;
		}

	} while (user != 'a');
}