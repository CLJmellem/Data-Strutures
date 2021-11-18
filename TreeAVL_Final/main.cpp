//Nome: Cássio Luis Junqueira Mellem Filho - 32089694
//Nome: João Paulo Bulhões Pequeno - 32089988
//Nome: Pedro Lopes de Lucena - 32055633

/*	
REFERENCIAS:
		CELES, W.; CERQUEIRA, R.; RANGEL, J. L. Introdução a Estrutura de Dados: com 
Técnicas de Programação em C, 2ª ed. Rio de Janeiro: Elsevier, 2006.

		Notas de aula_v4_0
		Notas de aula_v5_1
		
		https://www.youtube.com/watch?v=Au-6c55J90c

*/

#include <iostream>
#include <string>

#include "TreeAVL.h"


int main()
{
	setlocale(LC_ALL, "pt_BR");

	TreeAVL* T = new TreeAVL();


	/*	
		Codigo dividido em 2 partes, sendo a segunda a entrega para o dia 19, com a implementação do Remove,
		Para executar -> Retirar os comentarios de cada exercicio e da main

	*/


	//	Ex 1 - 4	***********************	Parte 1	*******************************
	
	//Exercicio 1
	//NodeAVL* node1 = new NodeAVL(1);
	//NodeAVL* node2 = new NodeAVL(2);
	//NodeAVL* node3 = new NodeAVL(3);

	//Exercicio 2
	//NodeAVL* node1 = new NodeAVL(3);
	//NodeAVL* node2 = new NodeAVL(2);
	//NodeAVL* node3 = new NodeAVL(1);
	
	//Exercicio 3
	//NodeAVL* node1 = new NodeAVL(3);
	//NodeAVL* node2 = new NodeAVL(1);
	//NodeAVL* node3 = new NodeAVL(2);
	
	//Exercicio 4
	//NodeAVL* node1 = new NodeAVL(1);
	//NodeAVL* node2 = new NodeAVL(3);
	//NodeAVL* node3 = new NodeAVL(2);

	/*
	T->SetRoot(T->Insert(T->GetRoot(), node1));
	T->SetRoot(T->Insert(T->GetRoot(), node2));
	T->SetRoot(T->Insert(T->GetRoot(), node3));
	std::cout << "Essa é a raiz: " << T->GetRoot()->GetID() << std::endl;
	std::cout << "Esse é o esquerdo: " << T->GetRoot()->GetLeft()->GetID()
		<< std::endl;
	std::cout << "Esse é o direito: " << T->GetRoot()->GetRight()->GetID()
		<< std::endl;

	delete node1;
	delete node2;
	delete node3;	
	*/

	//Exercicio 5 - **********************	Parte 2	******************************
	/*
	NodeAVL* node1 = new NodeAVL(5);
	NodeAVL* node2 = new NodeAVL(4);
	NodeAVL* node3 = new NodeAVL(3);
	NodeAVL* node4 = new NodeAVL(1);
	NodeAVL* node5 = new NodeAVL(2);
	NodeAVL* node6 = new NodeAVL(6);
	NodeAVL* node7 = new NodeAVL(7);
	NodeAVL* node8 = new NodeAVL(9);
	NodeAVL* node9 = new NodeAVL(8);
	
	T->SetRoot(T->Insert(T->GetRoot(), node1));
	T->SetRoot(T->Insert(T->GetRoot(), node2));
	T->SetRoot(T->Insert(T->GetRoot(), node3));
	T->SetRoot(T->Insert(T->GetRoot(), node4));
	T->SetRoot(T->Insert(T->GetRoot(), node5));
	T->SetRoot(T->Insert(T->GetRoot(), node6));
	T->SetRoot(T->Insert(T->GetRoot(), node7));
	T->SetRoot(T->Insert(T->GetRoot(), node8));
	T->SetRoot(T->Insert(T->GetRoot(), node9));
	
	T->DeleteNode(T->GetRoot(), 4);
	T->DeleteNode(T->GetRoot(), 5);
	T->DeleteNode(T->GetRoot(), 1);

	std::cout << "Left, Right, Root"
		<< std::endl;
	std::cout << T->TraverseInOrder();

	delete node2;
	delete node8;
	delete node7;
	delete node3;
	delete node9;
	delete node5;
	*/

}

