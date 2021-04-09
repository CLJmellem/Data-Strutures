#ifndef __STATIC_QUEUE_H__
#define __STATIC_QUEUE_H__


// Estrutura de dados do tipo Fila.
const int STATIC_QUEUE_CAPACITY = 8;

struct StaticQueue
{
	int front;
	int rear;
	int count;

	int values[STATIC_QUEUE_CAPACITY][5];
};

// Sintaxe de fun��o:
// <tipo do retorno> <nome da fun��o>(<par�metros, caso exista>);

//Create()
//Cria e retorna uma fila vazia.
//
//Pr� - condi��o: N / A.
//P�s - condi��o : Uma nova fila vazia � criada.
StaticQueue Create();

//Enqueue(queue, elem)
//Insere o elemento elem no fim da fila queue, se a fila n�o estiver cheia.
//
//Pr� - condi��o: A fila queue � v�lida.
//P�s - condi��o : O final da fila cont�m o elemento elem OU erro se a fila estiver cheia.
bool EnqueueA(StaticQueue& queue, int marca, int data, int estante,  int prateleira, int gaveta);
bool EnqueueB(StaticQueue& queue, int marca, int data, int estante, int prateleira, int gaveta);

//Dequeue(queue)
//Remove e retorna o primeiro elemento da fila queue, se a fila n�o estiver vazia.
//
//Pr� - condi��o: A fila queue � v�lida.
//P�s - condi��o : Remove e retorna o primeiro elemento da fila OU erro se a fila estiver vazia.
void DequeueA(StaticQueue& queue);
void DequeueB(StaticQueue& queue);


//Size(queue)
//Retorna a capacidade da fila.
//
//Pr� - condi��o: A fila queue � v�lida.
//P�s - condi��o : N / A.
int SizeA(const StaticQueue& queue);
int SizeB(const StaticQueue& queue);

//Count(queue)
//Retorna a quantidade de elementos na fila.
//
//Pr� - condi��o: A fila queue � v�lida.
//P�s - condi��o : N / A.
int CountA(const StaticQueue& queue);
int CountB(const StaticQueue& queue);

//IsEmpty(queue)
//Retorna true se a fila estiver vazia ou falso, caso contr�rio.
//
//Pr� - condi��o: A fila queue � v�lida.
//P�s - condi��o : N / A.
bool IsEmptyA(const StaticQueue& queue);
bool IsEmptyB(const StaticQueue& queue);




#endif // __STATIC_QUEUE_H__