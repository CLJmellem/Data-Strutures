//Nome: Cássio Luis Junqueira Mellem Filho
//TIA: 32089694

#include "Node.h"

Node::Node()
	: data("")
	, parent(nullptr)
	, left(nullptr)
	, right(nullptr)
	, level(0)
{
}
Node::~Node() {
	parent = nullptr;
	left = nullptr;
	right = nullptr;
	level = 0;
}

std::string Node::GetData() const {
	return data;
}
void Node::SetData(const std::string& data) {
	this->data = data;
}

Node* Node::GetParent() const {
	return parent;
}
void Node::SetParent(Node* parent) {
	this->parent = parent;
	this->level= parent->level + 1;
}

Node* Node::GetLeft() const {
	return left;
}
void Node::SetLeft(Node* left) {
	this->left = left;
}

Node* Node::GetRight() const {
	return right;
}
void Node::SetRight(Node* right) {
	this->right = right;
}

bool Node::isRoot() const {
	if (parent == nullptr && (left != nullptr || right != nullptr)) 
		return true;
	else
		return false;
}
bool Node::isLeaf() const {
	if (parent != nullptr && left == nullptr && right == nullptr) 
		return true;
	else
		return false;
}

int Node::GetDegree() const {
	if (left == nullptr && right == nullptr) { return 0; }
	else if (left != nullptr && right != nullptr) { return 2; }
	else { return 1; }
}
int Node::GetLevel() const {
	return this->level;
}
int Node::GetHeight() const{
	int maxH = -1;
	return GetHeightInternal(this, maxH);
}
int Node::GetHeightInternal(const Node* node, int h) const {
	if (node == nullptr) {
		return h;
	}
	else {
		h++;
		int left = GetHeightInternal(node->GetLeft(), h);
		int right = GetHeightInternal(node->GetRight(), h);

		if (left > right) 
			return left;
		else 
			return right;
	}		
}