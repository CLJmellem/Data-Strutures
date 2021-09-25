//Nome: Cássio Luis Junqueira Mellem Filho
//TIA: 32089694

#include "Tree.h"
#include <sstream>

Tree::Tree()
	: root(nullptr)
{
}
Tree::Tree(Node* root) 
	: root(root)
{
}
Tree::~Tree() {
	root = nullptr;
}

Node* Tree::GetRoot() const {
	return root;
}
void Tree::SetRoot(Node* root) {
	this->root = root;
}

bool Tree::isEmpty() const {
	if (GetRoot() == nullptr) {
		return true;
	}
	else
		return false;
}

int Tree::GetTreeDegree() const {
	int degree = 0;
	return GetTreeDegreeInternal(this->root, degree);
}
int Tree::GetTreeDegreeInternal(const Node* node, int d) const {
	if (isEmpty() == true)
		return d;
	else {
		if (node->GetLeft() != nullptr && node->GetRight() != nullptr) { return 2; }
		else { return 1; }

		GetTreeDegreeInternal(node->GetLeft(), d);
		GetTreeDegreeInternal(node->GetRight(), d);
	}
}
int Tree::GetTreeHeight() const {
	if (isEmpty() == true)
		return 0;
	else
		return root->GetHeight();
}

//Percorrer a árvore em orderm:
//- Percorrer subarvore da esquerda
//- visitar no raiz
//- Percorrer a subarvore da direita
//Condição:
//-Se estiver vazia, não faz nada
std::string Tree::TraverseInOrder() const {
	return TraverseInOrderInternal(this->root);				
}

std::string Tree::TraverseInOrderInternal(const Node* node) const {
	if (node != nullptr)
	{
		std::ostringstream oss;
		oss << TraverseInOrderInternal(node->GetLeft());
		oss << node->GetData() << ' ';
		oss << TraverseInOrderInternal(node->GetRight());
		return oss.str();
	}
	return "";
}

//Percorrer a árvore em Pré-ordem:
//- Visitar a raiz
//- Percorrer a subarvore da esquerda
//- Percorrer a subarvore da direita
//Condição:
//-Se estiver vazia, não faz nada
std::string Tree::TraversePreOrder() const {
	return TraversePreOrderInternal(this->root);
}
std::string Tree::TraversePreOrderInternal(const Node* node) const {
	if (node != nullptr)
	{
		std::ostringstream oss;
		oss << node->GetData() << ' ';
		oss << TraversePreOrderInternal(node->GetLeft());
		oss << TraversePreOrderInternal(node->GetRight());
		return oss.str();
	}
	return "";
}

//Percorrer a árvore em Pré-ordem:
//- Percorrer a subarvore da esquerda
//- Percorrer a subarvore da direita
//- Visitar a raiz
//Condição:
//-Se estiver vazia, não faz nada
std::string Tree::TraversePostOrder() const {
	return TraversePostOrderInternal(this->root);
}
std::string Tree::TraversePostOrderInternal(const Node* node) const {
	if (node != nullptr)
	{
		std::ostringstream oss;
		oss << TraversePostOrderInternal(node->GetLeft());
		oss << TraversePostOrderInternal(node->GetRight());
		oss << node->GetData() << ' ';
		return oss.str();
	}
	return "";
}