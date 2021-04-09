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

// Sintaxe de função:
// <tipo do retorno> <nome da função>(<parâmetros, caso exista>);

//Create()
//Cria e retorna uma fila vazia.
//
//Pré - condição: N / A.
//Pós - condição : Uma nova fila vazia é criada.
StaticQueue Create();

//Enqueue(queue, elem)
//Insere o elemento elem no fim da fila queue, se a fila não estiver cheia.
//
//Pré - condição: A fila queue é válida.
//Pós - condição : O final da fila contém o elemento elem OU erro se a fila estiver cheia.
bool EnqueueA(StaticQueue& queue, int marca, int data, int estante,  int prateleira, int gaveta);
bool EnqueueB(StaticQueue& queue, int marca, int data, int estante, int prateleira, int gaveta);

//Dequeue(queue)
//Remove e retorna o primeiro elemento da fila queue, se a fila não estiver vazia.
//
//Pré - condição: A fila queue é válida.
//Pós - condição : Remove e retorna o primeiro elemento da fila OU erro se a fila estiver vazia.
void DequeueA(StaticQueue& queue);
void DequeueB(StaticQueue& queue);


//Size(queue)
//Retorna a capacidade da fila.
//
//Pré - condição: A fila queue é válida.
//Pós - condição : N / A.
int SizeA(const StaticQueue& queue);
int SizeB(const StaticQueue& queue);

//Count(queue)
//Retorna a quantidade de elementos na fila.
//
//Pré - condição: A fila queue é válida.
//Pós - condição : N / A.
int CountA(const StaticQueue& queue);
int CountB(const StaticQueue& queue);

//IsEmpty(queue)
//Retorna true se a fila estiver vazia ou falso, caso contrário.
//
//Pré - condição: A fila queue é válida.
//Pós - condição : N / A.
bool IsEmptyA(const StaticQueue& queue);
bool IsEmptyB(const StaticQueue& queue);




#endif // __STATIC_QUEUE_H__