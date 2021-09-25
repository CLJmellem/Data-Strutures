#ifndef __TREE_H__
#define __TREE_H__

//Nome: Cássio Luis Junqueira Mellem Filho
//TIA: 32089694

#include "Node.h"

class Tree {
public:
	Tree();				//Criando uma arvore sem ter nenhuma raiz
	Tree(Node* root);	//Cria uma arvore com uma raiz ja 
	~Tree();

	Node* GetRoot() const;
	void SetRoot(Node* root);

	bool isEmpty() const;

	int GetTreeDegree() const;
	int GetTreeHeight() const;

	std::string TraverseInOrder() const;
	std::string TraversePreOrder() const;
	std::string TraversePostOrder() const;

private:
	Node* root;

	std::string TraverseInOrderInternal(const Node* node) const;
	std::string TraversePreOrderInternal(const Node* node) const;
	std::string TraversePostOrderInternal(const Node* node) const;

	int GetTreeDegreeInternal(const Node* node, int d) const;
};

#endif
