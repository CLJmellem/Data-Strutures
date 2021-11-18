//Nome: Cássio Luis Junqueira Mellem Filho - 32089694
//Nome: João Paulo Bulhões Pequeno - 32089988
//Nome: Pedro Lopes de Lucena - 32055633


#ifndef __NODE_AVL_H__
#define __NODE_AVL_H__

#include <string>

class NodeAVL
{
public:
	NodeAVL(int id);
	~NodeAVL();

	int GetID() const;
	void SetID(int id);

	std::string GetData() const;
	void SetData(const std::string& data);

	NodeAVL* GetParent() const;
	void SetParent(NodeAVL* parent);

	NodeAVL* GetLeft() const;
	void SetLeft(NodeAVL* left);

	NodeAVL* GetRight() const;
	void SetRight(NodeAVL* right);

	bool IsRoot() const;
	bool IsLeaf() const;
	int GetDegree() const;
	int GetDepth() const;
	int GetHeight() const;

	NodeAVL* RR(NodeAVL* node);
	NodeAVL* LL(NodeAVL* node);

	int GetFB(NodeAVL* node);

private:
	int m_FB;

	int m_ID;
	std::string m_Data;

	NodeAVL* m_Parent;
	NodeAVL* m_Left;
	NodeAVL* m_Right;


	int GetDepthInternal(const NodeAVL* node) const;
	int GetHeightInternal(const NodeAVL* node) const;
};

#endif // !__NODE_AVL_H__
