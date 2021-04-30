//Nome: C�ssio Luis Junqueira Mellem Filho
//TIA: 32089694

#include<iostream>

using namespace std;

int main()
{
	setlocale(LC_ALL, "pt_BR");


	int size;				//Tamanho do array
	int escolha;			//Elemento escolhido pelo user
	int counter = 0;		//Representa quantidade de elementos

	char limitBreaker;		//Escolha do user de aumentar ou n�o o array


	/*	Para criar um array dinamico iremos utilizar ponteiro com o input do usu�rio	*/
	cout << "Digite o tamanho do Array: "; cin >> size;
	int* array = new int[size];

	do 
	{
		/*	
			Queremos apenas numeros positivos, caso o usu�rio coloque um negativo (PARTE 1) ou ent�o o tamanho proposto pelo usu�rio 
				seja menor do que o tamanho atual (PARTE 2) o programa fecha.
																																		*/
		cout << "Informe um n�mero positivo para o elemento " << counter << ": ";
		cin >> escolha;


		//PARTE 1
		if (escolha < 0)
		{
			for(int i = counter; i < size; i++)
			{

				//Se o user colocar um n�mero negativo, este numero ser� desconsiderado e no lugar ser� -1, o restante das posi��es vazias tamb�m

				array[i] = -1;	 
				counter--;			//counter--, para evitar de entrar na segunda parte 
			}
		}else
		{

			//Caso n�o seja negativo o array recebe a escolha do usu�rio 

			array[counter] = escolha;
		}


		counter++;	


		//PARTE 2
		if(counter == size)
		{

			//Caso o array fique cheio, o programa pergunta ao user se ele quer aumentar

			cout << "O limite do array foi atingido. Deseja aumentar o tamanho do array ? (S / N) ";
			cin >> limitBreaker;

			if (limitBreaker == 's' || limitBreaker == 'S')
			{
				cout << "\nInforme o novo tamanho do array (atual: " << size << "): ";
				cin >> size;


				if (size < counter || size == counter)
				{

					//Se o user colocar um numero menor do que o atual o programa printa isso e fecha

					cout << "\nO tamanho do novo array n�o pode ser menor ou igual ao atual.\n";
					cout << "Encerrando...\n";
					size++;		//size++, para ter certeza de que o programa n�o realizar� o while
				}

				int* newArray = new int[size];				//	Para aumentar o tamanho do array, temos que criar um novo array tempor�rio 											
				for(int i = 0; i < size; i++)				//		depois precisamos copiar os elementos do array antigo para o tempor�rio e deletar o antigo, ap�s
				{											//		colocaremos os valores do novo para o "novo antigo".
					newArray[i] = array[i];					//	Como estamos utilizando ponteiros, n�o podemos deletar o array tempor�rio, pois se fizermos isso
				}											//		o "novo velho array" ter� seus elementos deletados tamb�m			
				delete[] array;																														
				array = newArray;
			}
		}

	} while (escolha > 0 && size > counter);



			/*	Printa os elementos do array	*/
	for(int i = 0; i < size; i++)
	{
		cout << "array[" << i << "]: " << array[i] << "\n";
	}

	delete[] array;
}