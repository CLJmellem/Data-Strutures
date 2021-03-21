#ifndef __STATIC_STACK_H__
#define __STATIC_STACK_H__

// Define uma pilha usando um vetor (array).
const int STATIC_STACK_CAPACITY = 10;

struct StaticStack
{
	int count; // Quantidade de elementos empilhados (índice do elemento no topo da pilha = count - 1).
	char values[STATIC_STACK_CAPACITY]; // Dados da pilha.
};

//Create()
//Cria e retorna uma pilha vazia.
//
//Pré - condição : N / A.
//Pós - condição : Uma nova pilha vazia é criada.
// sintaxe de funções:
// <retorno> <nome>(<parâmetros, caso aplicável>);
StaticStack Create();

//Push(stack, elem)
//Insere o elemento elem no topo da pilha stack, se a pilha não estiver cheia.
//
//Pré - condição: A pilha stack é válida.
//Pós - condição : O topo da pilha contém o elemento elem OU erro se a pilha estiver cheia.
bool Push(StaticStack& stack, char elem);

//Pop(stack)
//Remove o elemento do topo da pilha stack, se a pilha não estiver vazia.
//
//Pré - condição : A pilha stack é válida.
//Pós - condição : Remove e retorna o elemento do topo da pilha OU erro se a pilha estiver vazia.
char Pop(StaticStack& stack);

//Top(stack)
//Retorna uma referência do elemento que está no topo da pilha(mas não o remove), se a pilha não estiver vazia.
//
//Pré - condição : A pilha stack é válida.
//Pós - condição : Retorna o elemento do topo da pilha, sem removê - lo OU erro se a pilha estiver vazia.
char Top(const StaticStack& stack);

//Size(stack)
//Retorna a capacidade da pilha.
//
//Pré - condição : A pilha stack é válida.
//Pós - condição : N / A.
int Size(const StaticStack& stack);

//Count(stack)
//Retorna a quantidade de elementos na pilha.
//
//Pré - condição : A pilha stack é válida.
//Pós - condição : N / A.
int Count(const StaticStack& stack);

//IsEmpty(stack)
//Retorna true se a pilha estiver vazia ou falso, caso contrário.
//
//Pré - condição : A pilha stack é válida.
//Pós - condição : N / A.
bool IsEmpty(const StaticStack& stack);

//Clear(stack)
//Esvazia a pilha(remove todos os elementos da pilha).
//
//Pré - condição : A pilha stack é válida.
//Pós - condição : A pilha stack está vazia.
bool Clear(StaticStack& stack);

#endif // __STATIC_STACK_H__

