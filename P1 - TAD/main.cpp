/*		  -	Prova1 -
  Nome: Cássio Luis Junqueira Mellem Filho
  TIA: 32089694					*/


#include <iostream>

#include "StaticStack.h"

using namespace std;


void GeraLinha()
{
	//Apenas para uso de embelezamento, gera uma linha para facilitar a visualização

	int i = 0;
	cout << "\n";
	while (i < 50)
	{
		std::cout << "-";
		i++;
	}
}


int main()
{
	setlocale(LC_ALL, "pt-BR");


	StaticStack stackA = Create();
	StaticStack stackB = Create();


	int user, loop, sizeStack;
	char elem, elem2, popValue, topValue;
	bool empty;


	do
	{

		GeraLinha();
		cout << "\nEscolha uma das opções abaixo\n";
		cout << "\n[0]Enqueue (Insere um elemento no final da fila)\n";
		cout << "[1]Dequeue (Remove o primeiro elemento da fila)\n";
		cout << "[2]Front   (Mostra qual elemento esta no começo da fila)\n";
		cout << "[3]Size    (Mostra o tamanho da fila)\n";
		cout << "[4]IsEmpty (Mostra se a fila esta vazia)\n";
		cout << "[5]Clear   (Remove todos os elementos da fila)\n";
		cout << "[6]Sair\n";
		cin >> user;


		switch (user)
		{
			case 0:

				/*	A ideia por trás é utilizar 2 pilhas, sendo uma para armazenar o input do usuário em char
					Quando chega no fim da impletação da primeira pilha, entra em ação a outra.
					Será realizado um Top para saber qual o elemento no topo da pilha, juntamente com um Pop para remover este elemento.
					Por ultimo será realizado um push deste valor para a outra Stack, fazendo com que seja possível a impletação do tipo Fila	*/

				cout << "\nQual a quantidade de valores deseja adicionar na fila?\n";
				cout << "R: "; cin >> loop;
				if (loop > STATIC_STACK_CAPACITY)
				{
					cout << "Desculpe, valor fora de capacidade\n";
					cout << "Maximo: " << STATIC_STACK_CAPACITY;
				}
				else
				{
					for (int i = 0; i < loop; i++)
					{
						cout << "Digite o char a ser inserido na fila: "; cin >> elem;
						Push(stackA, elem);
					}

					for (int j = 0; j < loop; j++)
					{
						elem2 = Top(stackA);
						Pop(stackA);
						Push(stackB, elem2);
					}
				}

				break;

			case 1:

				/*	Para realizar o Dequeue, ou seja, o primeiro elemento da fila, só precisamos realizar um Pop na StackB.
					Pois o ultimo valor da Pilha é o primeiro da fila														*/

				empty = IsEmpty(stackB);
	
				if (empty == true)
				{
					cout << "Não é possivel continuar com a operação, pois fila esta vazia";
				}
				else{
					popValue = Pop(stackB);
					cout << "\nDado eliminado: " << popValue; 
				}

				break;


			case 2:
				topValue = Top(stackB);
				cout << "\nValor no começo da fila: " << topValue;

				break;
				

			case 3:
				sizeStack = Count(stackB);
				cout << "\nTamanho da fila: " << sizeStack;

				break;


			case 4:

				empty = IsEmpty(stackB);

				if(empty == true)
				{
					cout << "\nFila esta vazia";
				}
				else {
					cout << "\nFila não esta vazia";
				}
				
				break;
				

			case 5:

				empty = IsEmpty(stackB);

				if(empty == true)
				{
					cout << "Fila já esta vazia!";
				}
				else {
					Clear(stackB);
					cout << "\nTodos os dados da fila foram removidos";
				}

				break;


			case 6:
				exit;
		}

	} while (user != 6);

}