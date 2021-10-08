#pragma once
//Nome: Cássio Luis Junqueira Mellem Filho
//TIA: 32089694
//João Vitor Lima Lipert
//TIA: 32088876
//Eric Felipeli César Dias Pereira
//TIA: 41911296

#ifndef __NODE_H__
#define __NODE_H__

#include <string>

class Node {
public:
	Node();
	~Node();

	std::string GetData() const;
	void SetData(const std::string& data);

	Node* GetParent() const;
	void SetParent(Node* parent);

	Node* GetLeft() const;
	void SetLeft(Node* left);

	Node* GetRight() const;
	void SetRight(Node* right);

	int GetSalary() const;
	void SetSalary(int salary);

	int GetYear() const;
	void SetYear(int year);

	std::string GetCargo() const;
	void SetCargo(const std::string& cargo);

	std::string GetAnoAdm() const;
	void SetAnoAdm(const std::string& anoAdm);

	bool isRoot() const;
	bool isLeaf() const;

	int GetDegree() const;
	int GetLevel() const;
	int GetHeight() const;

	Node* PopulateTree(Node* node, Node* aux);

private:
	std::string data;
	std::string cargo;
	std::string anoAdm;
	int salary;
	int year;

	Node* parent;

	Node* left;
	Node* right;

	int level;

	int GetHeightInternal(const Node* node, int h) const;

	Node* PopulateTreeInternal(Node* node, Node* old);
};


#endif __NODE_H__