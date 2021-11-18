//Nome: Cássio Luis Junqueira Mellem Filho - 32089694
//Nome: João Paulo Bulhões Pequeno - 32089988
//Nome: Pedro Lopes de Lucena - 32055633


#ifndef __TREE_AVL_H__
#define __TREE_AVL_H__

#include "NodeAVL.h"

class TreeAVL
{
public:
	TreeAVL();
	TreeAVL(NodeAVL* root);
	~TreeAVL();

	NodeAVL* GetRoot() const;
	NodeAVL* SetRoot(NodeAVL* newRoot);
	bool IsEmpty() const;
	int GetDegree() const;
	int GetHeight() const;

	std::string TraverseInOrder() const;
	std::string TraversePreOrder() const;
	std::string TraversePostOrder() const;

	NodeAVL* FindMin() const;
	NodeAVL* FindMax() const;
	NodeAVL* Predecessor(int id) const;
	NodeAVL* Successor(int id) const;
	NodeAVL* Search(int id) const;

	NodeAVL* Insert(NodeAVL* r, NodeAVL* new_node);
	NodeAVL* DeleteNode(NodeAVL* r, int id);

	bool Remove(int id);

private:
	NodeAVL* m_Root;

	void Destroy(NodeAVL* node);

	int GetDegreeInternal(const NodeAVL* node) const;

	std::string TraverseInOrderInternal(const NodeAVL* node) const;
	std::string TraversePreOrderInternal(const NodeAVL* node) const;
	std::string TraversePostOrderInternal(const NodeAVL* node) const;

	NodeAVL* FindMinInternal(NodeAVL* node) const;
	NodeAVL* FindMaxInternal(NodeAVL* node) const;

	NodeAVL* PredecessorInternal(NodeAVL* node) const;
	NodeAVL* SuccessorInternal(NodeAVL* node) const;

	NodeAVL* SearchInternal(NodeAVL* node, int& id) const;

	bool RemoveInternal(NodeAVL* node, int id);
	void RemoveNode(NodeAVL* node);

	void UpdateParentChild(NodeAVL* parent, const NodeAVL* child,
		NodeAVL* newChild);
};

#endif