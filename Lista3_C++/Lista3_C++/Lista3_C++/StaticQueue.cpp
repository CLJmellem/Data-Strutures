#include "StaticQueue.h"
#include <iostream>

//Create()
//Cria e retorna uma fila vazia.
//
//Pré - condição: N / A.
//Pós - condição : Uma nova fila vazia é criada.
StaticQueue Create()
{
	StaticQueue queueA =
	{
		0, // int front;
		0, // int rear;
		0, // int count;
		{ 0 } // int values[STATIC_QUEUE_CAPACITY];
	};

	StaticQueue queueB =
	{
		0, // int front;
		0, // int rear;
		0, // int count;
		{ 0 } // int values[STATIC_QUEUE_CAPACITY];
	};


	return queueA, queueB;
}


//Enqueue(queue, elem)
//Insere o elemento elem no fim da fila queue, se a fila não estiver cheia.
//
//Pré - condição: A fila queue é válida.
//Pós - condição : O final da fila contém o elemento elem OU erro se a fila estiver cheia.
bool EnqueueA(StaticQueue& queueA, int marca, int data, int estante, int prateleira, int gaveta)
{
	// Verifica se a fila está cheia.
	if (queueA.count == SizeA(queueA))
	{
		return false;
	}

	// Insere elem no final da fila (vetor da queue).

	queueA.values[queueA.rear][0] = marca;
	queueA.values[queueA.rear][1] = data;
	queueA.values[queueA.rear][2] = estante;
	queueA.values[queueA.rear][3] = prateleira;
	queueA.values[queueA.rear][4] = gaveta;
	

	// "Vetor circular": se chegou no final do vetor (no limite/capacidade do vetor),
	// a variável rear, que é usada para indicar o índice correto para um novo elemento da fila,
	// volta pro início do vetor.
	queueA.rear = (queueA.rear + 1) % SizeA(queueA); // Mantém queue.rear no intervalo 0 <= queue.rear < Size(queue).

	// A linha acima equivale à:
	// ++queue.rear;
	// if (queue.rear == Size(queue))
	// {
	// 	queue.rear = 0;
	// }

	++queueA.count;

	return true;
}

bool EnqueueB(StaticQueue& queueB, int marca, int data, int estante, int prateleira, int gaveta)
{
	// Verifica se a fila está cheia.
	if (queueB.count == SizeB(queueB))
	{
		return false;
	}

	// Insere elem no final da fila (vetor da queue).

	queueB.values[queueB.rear][0] = marca;
	queueB.values[queueB.rear][1] = data;
	queueB.values[queueB.rear][2] = estante;
	queueB.values[queueB.rear][3] = prateleira;
	queueB.values[queueB.rear][4] = gaveta;


	// "Vetor circular": se chegou no final do vetor (no limite/capacidade do vetor),
	// a variável rear, que é usada para indicar o índice correto para um novo elemento da fila,
	// volta pro início do vetor.
	queueB.rear = (queueB.rear + 1) % SizeB(queueB); // Mantém queue.rear no intervalo 0 <= queue.rear < Size(queue).

	// A linha acima equivale à:
	// ++queue.rear;
	// if (queue.rear == Size(queue))
	// {
	// 	queue.rear = 0;
	// }

	++queueB.count;

	return true;
}



void DequeueA(StaticQueue& queueA)
{

	if (IsEmptyA(queueA))
	{
		std::cout << "Fila cheia";
	}
	
	std::cout << "\nEstante: " << queueA.values[queueA.front][2] << " Prateleira: " << queueA.values[queueA.front][3] << " Gaveta: " << queueA.values[queueA.front][4] << " foi removido!";
	

	// Como remover e retornar o primeiro elemento da fila?
	for(int i = 0; i < 5; i++)
	{
		queueA.values[queueA.front][i] = '\0';
	}

	// "Vetor circular": se chegou no final do vetor (no limite/capacidade do vetor),
	// a variável front, que é usada para indicar o índice correto do primeiro elemento da fila,
	// volta pro início do vetor.
	queueA.front = (queueA.front + 1) % SizeA(queueA); // Mantém queue.front no intervalo 0 <= queue.front < Size(queue).

	// A linha acima equivale à:
	// ++queue.front;
	// if (queue.front == Size(queue))
	// {
	// 	queue.front = 0;
	// }

	--queueA.count;

}

void DequeueB(StaticQueue& queueB)
{

	if (IsEmptyB(queueB))
	{
		std::cout << "Fila cheia";
	}

	std::cout << "\nEstante: " << queueB.values[queueB.front][2] << " Prateleira: " << queueB.values[queueB.front][3] << " Gaveta: " << queueB.values[queueB.front][4] << " foi removido!\n";


	// Como remover e retornar o primeiro elemento da fila?
	for (int i = 0; i < 5; i++)
	{
		queueB.values[queueB.front][i] = '\0';
	}

	// "Vetor circular": se chegou no final do vetor (no limite/capacidade do vetor),
	// a variável front, que é usada para indicar o índice correto do primeiro elemento da fila,
	// volta pro início do vetor.
	queueB.front = (queueB.front + 1) % SizeB(queueB); // Mantém queue.front no intervalo 0 <= queue.front < Size(queue).

	// A linha acima equivale à:
	// ++queue.front;
	// if (queue.front == Size(queue))
	// {
	// 	queue.front = 0;
	// }

	--queueB.count;

}


int CountA(const StaticQueue& queueA)
{
	return queueA.count;
}

int CountB(const StaticQueue& queueB)
{
	return queueB.count;
}

int SizeA(const StaticQueue& queueA)
{
	return sizeof(queueA.values) / sizeof(queueA.values[0]); // return STATIC_QUEUE_CAPACITY;
}

int SizeB(const StaticQueue& queueB)
{
	return sizeof(queueB.values) / sizeof(queueB.values[0]); // return STATIC_QUEUE_CAPACITY;
}


bool IsEmptyA(const StaticQueue& queueA)
{
	return queueA.count == 0;
}

bool IsEmptyB(const StaticQueue& queueB)
{
	return queueB.count == 0;
}


