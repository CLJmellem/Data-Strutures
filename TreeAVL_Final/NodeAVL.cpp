//Nome: Cássio Luis Junqueira Mellem Filho - 32089694
//Nome: João Paulo Bulhões Pequeno - 32089988
//Nome: Pedro Lopes de Lucena - 32055633


#include "NodeAVL.h"
#include "Utils.h"

NodeAVL::NodeAVL(int id)
	: m_ID(id)
	, m_Data("")
	, m_Parent(nullptr)
	, m_Left(nullptr)
	, m_Right(nullptr)
	, m_FB(0)
{
}
NodeAVL::~NodeAVL()
{
	m_Parent = nullptr;
	m_Left = nullptr;
	m_Right = nullptr;
}

int NodeAVL::GetID() const
{
	return m_ID;
}
void NodeAVL::SetID(int id)
{
	m_ID = id;
}


std::string NodeAVL::GetData() const
{
	return m_Data;
}
void NodeAVL::SetData(const std::string& data)
{
	m_Data = data;
}
NodeAVL* NodeAVL::GetParent() const
{
	return m_Parent;
}
void NodeAVL::SetParent(NodeAVL* parent)
{
	m_Parent = parent;
}
NodeAVL* NodeAVL::GetLeft() const
{
	return m_Left;
}
void NodeAVL::SetLeft(NodeAVL* left)
{
	m_Left = left;
}
NodeAVL* NodeAVL::GetRight() const
{
	return m_Right;
}
void NodeAVL::SetRight(NodeAVL* right)
{
	m_Right = right;
}

bool NodeAVL::IsRoot() const
{
	return m_Parent == nullptr;
}
bool NodeAVL::IsLeaf() const
{
	return m_Left == nullptr && m_Right == nullptr;
}
int NodeAVL::GetDegree() const
{
	int degree = 0;
	if (m_Left != nullptr)
		++degree;
	if (m_Right != nullptr)
		++degree;
	return degree;
}
int NodeAVL::GetDepth() const
{
	return GetDepthInternal(this);
}
int NodeAVL::GetDepthInternal(const NodeAVL* node) const
{
	if (node->IsRoot())
	{
		return 0;
	}
	else
	{
		return 1 + GetDepthInternal(node->GetParent());
	}
}
int NodeAVL::GetHeight() const
{
	return GetHeightInternal(this);
}
int NodeAVL::GetHeightInternal(const NodeAVL* node) const
{
	if (node == nullptr)
	{
		return 0;
	}
	else
	{
		return 1 + Utils::Max(GetHeightInternal(node->GetLeft()),
			GetHeightInternal(node->GetRight()));
	}
}

NodeAVL* NodeAVL::RR(NodeAVL* node)
{
	NodeAVL* rAux = node->GetRight();
	NodeAVL* rAux2 = rAux->GetLeft();

	rAux->SetLeft(node);
	node->SetRight(rAux2);

	return rAux;
}
NodeAVL* NodeAVL::LL(NodeAVL* node)
{
	NodeAVL* lAux = node->GetLeft();
	NodeAVL* lAux2 = lAux->GetRight();

	lAux->SetRight(node);
	node->SetLeft(lAux2);

	return lAux;
}
int NodeAVL::GetFB(NodeAVL* node)
{
	if (node == nullptr)
		return -1;
	return node->GetLeft()->GetHeight() - node->GetRight()->GetHeight();
}