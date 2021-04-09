//Nome: Cássio Luis Junqueira Mellem Filho
//TIA: 32089694

#include <iostream>
#include <ctime>
#include <string>

#include "StaticQueue.h"


using namespace std;


void Time(const time_t tempo)
{
	//Calculo da data e da hora do produto quando entra no estoque, de acordo com o exemplo proposto em aula do professor

	tm timeInfo;
	localtime_s(&timeInfo, &tempo);

	int year = timeInfo.tm_year + 1900;
	int month = timeInfo.tm_mon + 1;
	int day = timeInfo.tm_mday;

	int hour = timeInfo.tm_hour;
	int minutes = timeInfo.tm_min;
	int seconds = timeInfo.tm_sec;

	std::cout << day << "/" << month << "/" << year << " às " << hour << ":" << minutes << ":" << seconds;

}

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

	setlocale(LC_ALL, "pt_BR");

	StaticQueue queueA = Create();   /* irei utilizar 2 filas, uma para A e outra para os valores de B*/
	StaticQueue queueB = Create();
	

	int user;
	int escolha, escolhaMarca, loop;
	int counterLoop = 0;

	char marca;
	int marcaInt, estante, prateleira, gaveta;


	do 
	{
		GeraLinha();
		cout << "\nEsolha: \n";
		cout << "\nVendedor[0] "; cout << " Cliente[1] " << " Sair[2]\n "; 
		cout << "R: "; cin >> user;

		/*	Existem 3 opções iniciais para o usuario, caso escolha a opção VENDEDOR, este irá colocar o produto dentro de uma das 2 filas realizado pelo Enqueue, de acordo com a marca (A ou B)
													  caso escolha a opçãp CLIENTE, este irá escolher entre uma das duas marcas, dependendo da escolha, este produto é retirado da Fila pelo Dequeue
													  ou simplesmente sair do programa, executando o exit					*/

		if (user == 0)
		{
			GeraLinha();
			cout << "\nQual operação deseja realizar?\n";
			cout << "\nAdicionar[0]\n";
			cout << "Voltar ao menu anterior[1]\n";
			cout << "R: "; cin >> escolha;


			if (escolha == 0)
			{
				do {
					GeraLinha();
					cout << "\nDigite o nome da marca (A ou B): "; cin >> marca;
					cout << "\nDigite o numero da estante para adicionar o produto: "; cin >> estante;
					cout << "\nDigite o numero da prateleira onde sera armazenada: "; cin >> prateleira;
					cout << "\nDigite o numero da gaveta onde sera armazenada: "; cin >> gaveta;

					if (marca == 'A' || marca == 'a')
					{
						marcaInt = 0;
						time_t t = time(nullptr);
						cout << "\n\nProduto adicionado em: ";
						Time(t);

						EnqueueA(queueA, marcaInt, t, estante, prateleira, gaveta);
						GeraLinha();
					}

					if (marca == 'B' || marca == 'b')
					{
						marcaInt = 1;
						time_t t = time(nullptr);
						cout << "\n\nProduto adicionado em: ";
						Time(t);

						EnqueueB(queueB, marcaInt, t, estante, prateleira, gaveta);
						GeraLinha();
					}

					cout << "\n\nDeseja adicionar outro produto? [1] para sim e [0] para nao\n"; 
					cout << "R: "; cin >> loop;
					counterLoop++;

				} while (loop == 1 && counterLoop <= STATIC_QUEUE_CAPACITY);

				GeraLinha();

			}
			
		}



		if(user == 1)
		{
			GeraLinha();
			cout << "\nDe qual marca deseja comprar?\n";
			cout << "\nMarca A[0]\n";
			cout << "Marca B[1]\n";
			cout << "Qualquer uma[2]\n";
			cout << "R: "; cin >> escolhaMarca;
			
			if(escolhaMarca == 0)
			{
				bool vazio = IsEmptyA(queueA);
				if(vazio == true)
				{
					cout << "Marca A não possui produtos";
				}
				else {
					cout << "Data de quando o produto foi inserido: "; Time(queueA.values[queueA.front][1]);
					DequeueA(queueA);
				}	
			}

			if (escolhaMarca == 1)
			{
				bool vazio = IsEmptyB(queueB);
				if (vazio == true)
				{
					cout << "Marca B não possui produtos";
				}
				else {
					cout << "Data de quando o produto foi inserido: "; Time(queueB.values[queueB.front][1]);
					DequeueB(queueB);
				}
			}

			if(escolhaMarca == 2)
			{
				bool vazioA = IsEmptyA(queueA);
				bool vazioB = IsEmptyB(queueB);

				if(vazioA == true && vazioB == true)
				{
					cout << "Não possui nenhum produto no estoque";
				}
				else {
					int dataA = queueA.values[queueA.front][1];
					int dataB = queueB.values[queueB.front][1];

					if(dataA == 0)
					{
						cout << "\nData de quando o produto foi inserido: "; Time(queueB.values[queueB.front][1]);
						cout << "\nProduto da marca B\n";
						DequeueB(queueB);
					}else if(dataB == 0)
					{
						cout << "\nData de quando o produto foi inserido: "; Time(queueA.values[queueA.front][1]);
						cout << "\nProduto da marca A\n";
						DequeueA(queueA);

					}else if(dataA > dataB)
					{
						cout << "\nData de quando o produto foi inserido: "; Time(queueB.values[queueB.front][1]);
						cout << "\nProduto da marca B\n";
						DequeueB(queueB);
					}
					else {
						cout << "\nData de quando o produto foi inserido: "; Time(queueA.values[queueA.front][1]);
						cout << "\nProduto da marca A\n";
						DequeueA(queueA);
					}
				}

			}
		}


		if (user == 2) { exit; }


	} while (user != 2 );
	

}