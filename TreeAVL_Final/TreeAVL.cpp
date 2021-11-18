//Nome: Cássio Luis Junqueira Mellem Filho - 32089694
//Nome: João Paulo Bulhões Pequeno - 32089988
//Nome: Pedro Lopes de Lucena - 32055633


#include <sstream>
#include "TreeAVL.h"
#include "Utils.h"


TreeAVL::TreeAVL()
	: m_Root(nullptr)
{
}
TreeAVL::TreeAVL(NodeAVL* root)
	: m_Root(root)
{
}
TreeAVL::~TreeAVL()
{
	Destroy(m_Root);
}
void TreeAVL::Destroy(NodeAVL* node)
{
	if (node != nullptr)
	{
		Destroy(node->GetLeft());
		Destroy(node->GetRight());
		delete node;
		node = nullptr;
	}
}

NodeAVL* TreeAVL::SetRoot(NodeAVL* newRoot)
{
	m_Root = newRoot;
	return m_Root;
}


NodeAVL* TreeAVL::Search(int id) const
{
	return SearchInternal(m_Root, id);
}
NodeAVL* TreeAVL::SearchInternal(NodeAVL* node, int& id) const
{
	if (node == nullptr)
		return nullptr;
	else if (node->GetID() == id)
		return node;
	else if (node->GetID() > id)
		return SearchInternal(node->GetLeft(), id);
	else
		return SearchInternal(node->GetRight(), id);
}

NodeAVL* TreeAVL::Insert(NodeAVL* r, NodeAVL* new_node) 
{

	if (r == nullptr) 
	{
		r = new_node;
		return r;
	}

	if (new_node->GetID() < r->GetID()) {
		r->SetLeft(Insert(r->GetLeft(), new_node));
	}
	else if (new_node->GetID() > r->GetID()) {
		r->SetRight(Insert(r->GetRight(), new_node));
	}
	else 
		return r;


	int FB = r->GetFB(r);
	// Left Left   
	if (FB > 1 && new_node->GetID() < r->GetLeft()->GetID())
		return r->LL(r);

	// Right Right 
	if (FB < -1 && new_node->GetID() > r->GetRight()->GetID())
		return r->RR(r);

	// Left Right 
	if (FB > 1 && new_node->GetID() > r->GetLeft()->GetID()) 
	{
		r->SetLeft(r->RR(r->GetLeft()));
		return r->LL(r);
	}

	// Right Left 
	if (FB < -1 && new_node->GetID() < r->GetRight()->GetID()) 
	{
		r->SetRight(r->LL(r->GetRight()));
		return r->RR(r);
	}

	return r;

}
NodeAVL* TreeAVL::DeleteNode(NodeAVL* r, int id) {

	if (r == nullptr)	return nullptr;
	else if (id < r->GetID())
		r->SetLeft(DeleteNode(r->GetLeft(), id));

	else if (id > r->GetID())
		r->SetRight(DeleteNode(r->GetRight(), id));

	else 
	{
		if (r->GetLeft() == nullptr) 
		{
			NodeAVL* aux = r->GetRight();
			delete r;
			return aux;
		}
		else if (r->GetRight() == nullptr) 
		{
			NodeAVL* aux = r->GetLeft();
			delete r;
			return aux;
		}
		else 
		{
			TreeAVL* treeAux = new TreeAVL(r->GetRight());

			NodeAVL* aux = treeAux->FindMin();
			r->SetID(aux->GetID());
			r->SetRight(DeleteNode(r->GetRight(), aux->GetID()));
		}
	}
}

bool TreeAVL::Remove(int id)
{
	return RemoveInternal(m_Root, id);
}
bool TreeAVL::RemoveInternal(NodeAVL* node, int id)
{
	if (node == nullptr)
		return false;
	else if (node->GetID() == id)
	{
		RemoveNode(node);
		return true;
	}
	else if (node->GetID() > id)
		return RemoveInternal(node->GetLeft(), id);
	else
		return RemoveInternal(node->GetRight(), id);
}
void TreeAVL::RemoveNode(NodeAVL* node)
{
	// Caso 1: o nó a ser removido é uma folha.
	if (node->IsLeaf())
	{
		UpdateParentChild(node->GetParent(), node, nullptr);
	}
	// Caso 2: o nó a ser removido não possui filho esquerdo.
	else if (node->GetLeft() == nullptr)
	{
		NodeAVL* parent = node->GetParent();
		NodeAVL* newChild = node->GetRight();
		UpdateParentChild(parent, node, newChild);
	}
	// Caso 3: o nó a ser removido não possui filho direito.
	else if (node->GetRight() == nullptr)
	{
		NodeAVL* parent = node->GetParent();
		NodeAVL* newChild = node->GetLeft();
		UpdateParentChild(parent, node, newChild);
	}
	// Caso 4: o nó a ser removido possui os dois filhos.
	else
	{
		NodeAVL* toSwap = Predecessor(node->GetID());
		NodeAVL* toSwapOrigParent = toSwap->GetParent();
		NodeAVL* parent = node->GetParent();
		NodeAVL* newChild = toSwap;
		UpdateParentChild(parent, node, newChild);
		if (toSwapOrigParent != nullptr && toSwapOrigParent != node)
			UpdateParentChild(toSwapOrigParent, toSwap,
				toSwap->GetLeft());
		if (toSwap != node->GetLeft())
			UpdateParentChild(toSwap, toSwap->GetLeft(),
				node->GetLeft());
		UpdateParentChild(toSwap, toSwap->GetRight(),
			node->GetRight());
	}
	delete node;
	node = nullptr;
}
void TreeAVL::UpdateParentChild(NodeAVL* parent, const NodeAVL*
	child, NodeAVL* newChild)
{
	if (parent != nullptr)
	{
		if (parent->GetLeft() == child)
			parent->SetLeft(newChild);
		else
			parent->SetRight(newChild);
	}
	else
	{
		m_Root = newChild;
	}
	if (newChild != nullptr)
		newChild->SetParent(parent);
}

NodeAVL* TreeAVL::FindMin() const
{
	return FindMinInternal(m_Root);
}
NodeAVL* TreeAVL::FindMinInternal(NodeAVL* node) const
{
	if (node == nullptr)
		return nullptr;
	else if (node->GetLeft() == nullptr)
		return node;
	else
		return FindMinInternal(node->GetLeft());
}
NodeAVL* TreeAVL::FindMax() const
{
	return FindMaxInternal(m_Root);
}
NodeAVL* TreeAVL::FindMaxInternal(NodeAVL* node) const
{
	if (node == nullptr)
		return nullptr;
	else if (node->GetRight() == nullptr)
		return node;
	else
		return FindMaxInternal(node->GetRight());
}


NodeAVL* TreeAVL::Predecessor(int id) const
{
	NodeAVL *node = SearchInternal(m_Root, id);
	return node == nullptr ? nullptr : PredecessorInternal(node);
}
NodeAVL* TreeAVL::PredecessorInternal(NodeAVL* node) const
{
	if (node->GetLeft() != nullptr)
	{
		return FindMaxInternal(node->GetLeft());
	}
	else
	{
		NodeAVL* current = node;
		NodeAVL* currentParent = node->GetParent();
		while (currentParent != nullptr
			&& current == currentParent->GetLeft())
		{
			current = currentParent;
			currentParent = current->GetParent();
		}
		return currentParent;
	}
}
NodeAVL* TreeAVL::Successor(int id) const
{
	NodeAVL* node = SearchInternal(m_Root, id);
	return node == nullptr ? nullptr : SuccessorInternal(node);
}
NodeAVL *TreeAVL::SuccessorInternal(NodeAVL* node) const
{
	if (node->GetRight() != nullptr)
	{
		return FindMinInternal(node->GetRight());
	}
	else
	{
		NodeAVL* current = node;
		NodeAVL* currentParent = node->GetParent();
		while (currentParent != nullptr
			&& current == currentParent->GetRight())
		{
			current = currentParent;
			currentParent = current->GetParent();
		}
		return currentParent;
	}
}



std::string TreeAVL::TraverseInOrder() const
{
	return TraverseInOrderInternal(m_Root);
}
std::string TreeAVL::TraverseInOrderInternal(const
	NodeAVL* node) const
{
	if (node != nullptr)
	{
		std::ostringstream oss;
		oss << TraverseInOrderInternal(node->GetLeft());
		oss << node->GetID() << ' ';
		oss << TraverseInOrderInternal(node->GetRight());
		return oss.str();
	}
	return "";
}
std::string TreeAVL::TraversePreOrder() const
{
	return TraversePreOrderInternal(m_Root);
}
std::string TreeAVL::TraversePreOrderInternal(const
	NodeAVL* node) const
{
	if (node != nullptr)
	{
		std::ostringstream oss;
		oss << node->GetID() << ' ';
		oss << TraversePreOrderInternal(node->GetLeft());
		oss << TraversePreOrderInternal(node->GetRight());
		return oss.str();
	}
	return "";
}
std::string TreeAVL::TraversePostOrder() const
{
	return TraversePostOrderInternal(m_Root);
}
std::string TreeAVL::TraversePostOrderInternal(const
	NodeAVL* node) const
{
	if (node != nullptr)
	{
		std::ostringstream oss;
		oss << TraversePostOrderInternal(node->GetLeft());
		oss << TraversePostOrderInternal(node->GetRight());
		oss << node->GetID() << ' ';
		return oss.str();
	}
	return "";
}

bool TreeAVL::IsEmpty() const
{
	return m_Root == nullptr;
}

NodeAVL* TreeAVL::GetRoot() const
{
	return m_Root;
}

int TreeAVL	::GetDegree() const
{
	return GetDegreeInternal(m_Root);
}
int TreeAVL::GetDegreeInternal(const NodeAVL* node) const
{
	if (node != nullptr)
	{
		int left = GetDegreeInternal(node->GetLeft());
		int right = GetDegreeInternal(node->GetRight());
		return Utils::Max(node->GetDegree(), Utils::Max(left,
			right));
	}
	return 0;
}
int TreeAVL::GetHeight() const
{
	if (m_Root == nullptr)
		return -1;
	return m_Root->GetHeight();
}



