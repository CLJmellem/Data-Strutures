//Nome: Cássio Luis Junqueira Mellem Filho
//TIA: 32089694

#include<iostream>

using namespace std;

int main()
{
	setlocale(LC_ALL, "pt_BR");


	int size;				//Tamanho do array
	int escolha;			//Elemento escolhido pelo user
	int counter = 0;		//Representa quantidade de elementos

	char limitBreaker;		//Escolha do user de aumentar ou não o array


	/*	Para criar um array dinamico iremos utilizar ponteiro com o input do usuário	*/
	cout << "Digite o tamanho do Array: "; cin >> size;
	int* array = new int[size];

	do 
	{
		/*	
			Queremos apenas numeros positivos, caso o usuário coloque um negativo (PARTE 1) ou então o tamanho proposto pelo usuário 
				seja menor do que o tamanho atual (PARTE 2) o programa fecha.
																																		*/
		cout << "Informe um número positivo para o elemento " << counter << ": ";
		cin >> escolha;


		//PARTE 1
		if (escolha < 0)
		{
			for(int i = counter; i < size; i++)
			{

				//Se o user colocar um número negativo, este numero será desconsiderado e no lugar será -1, o restante das posições vazias também

				array[i] = -1;	 
				counter--;			//counter--, para evitar de entrar na segunda parte 
			}
		}else
		{

			//Caso não seja negativo o array recebe a escolha do usuário 

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

					cout << "\nO tamanho do novo array não pode ser menor ou igual ao atual.\n";
					cout << "Encerrando...\n";
					size++;		//size++, para ter certeza de que o programa não realizará o while
				}

				int* newArray = new int[size];				//	Para aumentar o tamanho do array, temos que criar um novo array temporário 											
				for(int i = 0; i < size; i++)				//		depois precisamos copiar os elementos do array antigo para o temporário e deletar o antigo, após
				{											//		colocaremos os valores do novo para o "novo antigo".
					newArray[i] = array[i];					//	Como estamos utilizando ponteiros, não podemos deletar o array temporário, pois se fizermos isso
				}											//		o "novo velho array" terá seus elementos deletados também			
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