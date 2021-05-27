// Cássio Luis Junqueira Mellem Filho - 32089694

#include <string>
#include "LinkedList_v2.h"


LinkedList* Create()
{
	LinkedList* list = new LinkedList;

	list->count = 0;
	list->head = nullptr;
	list->tail = nullptr;

	return list;
}

Node* CreateNode(int id, Node* tail, Node* head, std::string name)
{
	Node* node = new Node;

	node->id = id;
	node->name = name;
	node->previous = tail;
	node->next = head;

	return node;
}


void Insert(LinkedList* list, int id, std::string name)
{
	/*	Para a implementação do Insert temos 2 possíveis casos, 1- caso estiver vazio ,2- caso ter algo na lista

		1- Parte mais simples pois simplesmente define esse nó como o começo e o fim da fila (tanto head quanto tail)
		2- Como queremos adicionar no começo da lista, primeiramente dizemos que o previous do nó head atual tem q apontar para o node (que será o novo head),
				pós isso podemos dizer que o head é igual aos dados do novo nó.

										New Head			   Old Head
								[previous][id][next] <--> [previous][id][next]

										New Head			        Tail
							|-> [previous][id][next]      [previous][id][next] <-|
							|----------------------------------------------------|																					*/


	Node* node = CreateNode(id, list->tail, list->head, name);

	if (IsEmpty(list))
	{
		list->tail = node;
		list->head = node;
		++list->count;
		return;
	}
	else
	{
		list->head->previous = node;
		list->head = node;
	}

	list->tail->next = list->head;
	++list->count;
}

void Append(LinkedList* list, int id, std::string name)
{
	/*	Para a implementação do Append temos 2 possíveis casos, 1- caso estiver vazio ,2- caso ter algo na lista
		1- Parte mais simples pois simplesmente define esse nó como o começo e o fim da fila (tanto head quanto tail)
		2- Como queremos adicionar no fim da lista, primeiramente dizemos que o next do nó head atual tem q apontar para o node (que será o novo tail),
				pós isso podemos dizer que o tail é igual aos dados do novo nó.

										Old Tail			      New Tail
								[previous][id][next] <--> [previous][id][next]
										Head			          New Tail
							|-> [previous][id][next]      [previous][id][next] <-|
							|----------------------------------------------------|																			*/

	Node* node = CreateNode(id, list->tail, list->head, name);

	if (IsEmpty(list))
	{
		list->tail = node;
		list->head = node;
	}
	else
	{
		list->tail->next = node;
		list->tail = node;
	}

	list->head->previous = list->tail;
	++list->count;
}


bool InsertBefore(LinkedList* list, int beforeId, int id, std::string name)
{
	// Algoritimo é O(n), pois por ter for, depende exclusivamente do tamanho. No caso, APENAS a parte do insert seria O(log n), pois nesse caso não seria 
	//		necessario modificar a lista inteira para adicionar um elemento e so seria necessario saber apenas de um elemento para a implementação, no caso o beforeID

	/*	1- A função irá verificar se a lista esta vazia, neste caso, deleta os nós e retorna false. 
		2- Caso não for vazio, irá realizar um loop até achar o id. Nest caso, irá adionar mais 1 no verify.
		3- No caso do verify ser 0, é pois o id do node inserido pelo user não existe, nest caso o nó é excluido e retorna false.
		4- No caso do verify ser diferente/maior de 0 passa-se a conectar o novo nó aos antigos e após os antigos no novo.


											   (1)	   Old nodes			(2)
								    [previous][id][next]--- --[previous][beforeID][next]
											  ^			   ||	   			^
											  |	           ||			    |
											  |		 	   \/			    |
									          |-[previous][id][next]--------|
														   (3)
										       		    New Node
																					
		->Para tal, o anterior(1) do novo node é o mesmo que o anterior do antigo com o beforeID(2), já o next é o proprio Node antigo(2)

		->Para os antigos:	O next do node 1 deve ser o novo node e o previous do node 2 deve ser o novo node								*/

	int verify = 0;

	Node* nodeB = CreateNode(id, list->tail, list->head, name);
	Node* nodeAux = list->head;

	if(IsEmpty(list))
	{
		DestroyNode(nodeB);
		DestroyNode(nodeAux);
		return false;
	}
	else {
		for(int i = 0; i < list->count; i++)
		{
			if(beforeId == nodeAux->id)
			{
				verify++;
			}
			else {
				nodeAux = nodeAux->next;
			}
		}

		if (verify == 0)
		{
			DestroyNode(nodeB);
			return false;
		}
		else {

			if(beforeId == list->head->id)
			{
				Insert(list, id, name);
			}
			else {
				nodeB->previous = nodeAux->previous;
				nodeB->next = nodeAux;

				nodeAux->previous->next = nodeB;
				nodeAux->previous = nodeB;

				list->count++;
			}

			return true;
		}
	}
}


bool InsertAfter(LinkedList* list, int beforeId, int id, std::string name)
{
	// Algoritimo é O(n), pois por ter for, depende exclusivamente do tamanho. No caso, APENAS a parte do insert seria O(log n), pois nesse caso não seria 
	//		necessario modificar a lista inteira para adicionar um elemento e so seria necessario saber apenas de um elemento para a implementação, no caso o beforeID

	//Igual o InsertBefore, porém este é invertido.

	int verify = 0;

	Node* nodeA = CreateNode(id, list->tail, list->head, name);
	Node* nodeAux = list->tail;

	if (IsEmpty(list))
	{
		DestroyNode(nodeA);
		DestroyNode(nodeAux);
		return false;
	}
	else {
		for (int i = 0; i < list->count; i++)
		{
			if (beforeId == nodeAux->id)
			{
				verify++;
			}
			else {
				nodeAux = nodeAux->previous;
			}
		}

		if (verify == 0)
		{
			DestroyNode(nodeA);
			return false;
		}
		else {

			if (beforeId == list->tail->id)
			{
				Append(list, id, name);
			}
			else {
				nodeA->next = nodeAux->next;
				nodeA->previous = nodeAux;

				nodeAux->next->previous = nodeA;
				nodeAux->next = nodeA;

				list->count++;
			}
			return true;
		}
	}
}


Node* RemoveHead(LinkedList* list)
{
	/*	Para a implementação do RemoveHead temos 2 possíveis casos, 1- caso estiver vazio ,2- caso ter algo na lista

		1- Simplesmente retorna nullptr, pois não existe nada na lista
		2- Para realizar a operção precisa-se "pular" este nó e ligar o anterior e o next deste. Para isso, o head passa a apontar para o seu próximo
				e o seu anterior passa a apontar para o tail da lista (por conta de ser circular), o tail next aponta para o head (por conta de ser circular)
				e por fim, diminui 1 do count, pois foi retirado um número da lista.																			*/

	Node* removeH = list->head;

	if (removeH == nullptr)
	{
		DestroyNode(removeH);
		return nullptr;
	}
	else {
		list->head = list->head->next;
		list->head->previous = list->tail;
		list->tail->next = list->head;

		list->count--;

		return removeH;
	}
}

Node* RemoveTail(LinkedList* list)
{
	//	Principio é o mesmo do RemoveHead, porém mudam algumas operação para se adaptar ao Tail.

	Node* removeT = list->tail;

	if (removeT == nullptr)
	{
		DestroyNode(removeT);
		return nullptr;
	}
	else {
		list->tail = list->tail->previous;
		list->tail->next = list->head;
		list->head->previous = list->tail;

		list->count--;

		return removeT;
	}
}

Node* RemoveNode(LinkedList* list, int id)
{
	/*	Principio é o mesmo do RemoveHead, porém mudam algumas operação para se adaptar ao Node. Porém tem-se agora que toda vez que o id do removeN for diferente
			vai para frente uma posição até suprir a necessidade.																									*/

	Node* removeN = list->head;

	for (int i = 0; i < list->count; i++)
	{
		if (removeN == nullptr)
		{
			return nullptr;
		}
		else if (removeN->id == id)
		{
			removeN->previous->next = removeN->next;
			removeN->next->previous = removeN->previous;

			list->count--;

			return removeN;
		}
		else {
			removeN = removeN->next;
		}
	}

	return nullptr;
}


Node* GetHead(const LinkedList* list)
{
	return list->head;
}

Node* GetTail(const LinkedList* list)
{
	return list->tail;
}

void Clear(LinkedList* list)
{

	Node* aux = list->head;
	Node* next = nullptr;

	for (int i = 0; i < list->count; i++)
	{
		next = aux->next;
		DestroyNode(aux);
		aux = next;
	}

	list->head = nullptr;
	list->tail = nullptr;

	list->count = 0;
}


int Count(const LinkedList* list)
{
	return list->count;
}

bool IsEmpty(const LinkedList* list)
{
	return list->head == nullptr && list->tail == nullptr;
}


void Destroy(LinkedList* list)
{
	Clear(list);

	delete list;
	list = nullptr;
}
void DestroyNode(Node* node)
{
	delete node;
	node = nullptr;
}