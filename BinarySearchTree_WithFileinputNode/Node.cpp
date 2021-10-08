//Nome: Cássio Luis Junqueira Mellem Filho
//TIA: 32089694
//João Vitor Lima Lipert
//TIA: 32088876
//Eric Felipeli César Dias Pereira
//TIA: 41911296

#include "Node.h"

Node::Node()
	: data("")
	, cargo("")
	, anoAdm("")
	, salary(0)
	, year(0)
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
	salary = 0;
	year = 0;
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
	this->level = parent->level + 1;
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
int Node::GetHeight() const {
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


/****************NEW_COMMIT********************/
int Node::GetSalary() const
{
	return this->salary;
}
void Node::SetSalary(int salary)
{
	this->salary = salary;
}

int Node::GetYear() const
{
	return this->year;
}
void Node::SetYear(int year)
{
	this->year = year;
}

std::string Node::GetCargo() const
{
	return this->cargo;
}
void Node::SetCargo(const std::string& cargo)
{
	this->cargo = cargo;
}

std::string Node::GetAnoAdm() const
{
	return this->anoAdm;
}
void Node::SetAnoAdm(const std::string& anoAdm)
{
	this->anoAdm = anoAdm;
}



/****************NEW_COMMIT************************/

Node* Node::PopulateTree(Node* node, Node* aux)
{
	return PopulateTreeInternal(node, aux);
}
Node* Node::PopulateTreeInternal(Node* node, Node* old)
{
	if (old == NULL) return node;
	if (node->GetSalary() < old->GetSalary()) {
		if (node->GetData() == old->GetData()) return old;
		else {
			old->SetLeft(PopulateTreeInternal(node, old->GetLeft()));
			return old;
		}
	}
	else if (node->GetSalary() >= old->GetSalary()) {
		if (node->GetData() == old->GetData()) return old;
		else {
			old->SetRight(PopulateTreeInternal(node, old->GetRight()));
			return old;
		}
	}

	return old;
}