//Nome: Cássio Luis Junqueira Mellem Filho
//TIA: 32089694

#include <iostream>
#include "Tree.h"

int main() {
	Node* A = new Node();
	Node* B = new Node();
	Node* C = new Node();
	Node* D = new Node();
	Node* E = new Node();
	Node* F = new Node();

	Tree* t = new Tree(A);

	A->SetData("A");
	A->SetLeft(B);
	A->SetRight(C);

	B->SetData("B");
	B->SetLeft(D);

	C->SetData("C");
	C->SetLeft(E);
	C->SetRight(F);

	D->SetData("D");
	E->SetData("E");
	F->SetData("F");


	B->SetParent(A);
	C->SetParent(A);
	D->SetParent(B);
	E->SetParent(C);
	F->SetParent(C);

	std::cout << "A eh raiz? " << A->isRoot() << '\n';
	std::cout << "B eh raiz? " << B->isRoot() << '\n';
	std::cout << "C eh raiz? " << C->isRoot() << '\n';
	std::cout << "D eh raiz? " << D->isRoot() << '\n';
	std::cout << "E eh raiz? " << E->isRoot() << '\n';
	std::cout << "F eh raiz? " << F->isRoot() << '\n';
	
	std::cout << "A eh folha? " << A->isLeaf() << '\n';
	std::cout << "B eh folha? " << B->isLeaf() << '\n';
	std::cout << "C eh folha? " << C->isLeaf() << '\n';
	std::cout << "D eh folha? " << D->isLeaf() << '\n';
	std::cout << "E eh folha? " << E->isLeaf() << '\n';
	std::cout << "F eh folha? " << F->isLeaf() << '\n';
	
	std::cout << "*****************************************************\n";

	std::cout << "Grau de A " << A->GetDegree() << '\n';
	std::cout << "Grau de B " << B->GetDegree() << '\n';
	std::cout << "Grau de C " << C->GetDegree() << '\n';
	std::cout << "Grau de D " << D->GetDegree() << '\n';
	std::cout << "Grau de E " << E->GetDegree() << '\n';
	std::cout << "Grau de F " << F->GetDegree() << '\n';
	
	std::cout << "Nivel de A " << A->GetLevel() << '\n';
	std::cout << "Nivel de B " << B->GetLevel() << '\n';
	std::cout << "Nivel de C " << C->GetLevel() << '\n';
	std::cout << "Nivel de D " << D->GetLevel() << '\n';
	std::cout << "Nivel de E " << E->GetLevel() << '\n';
	std::cout << "Nivel de F " << F->GetLevel() << '\n';

	std::cout << "Altura do node A " << A->GetHeight() << '\n';
	std::cout << "Altura do node B " << B->GetHeight() << '\n';
	std::cout << "Altura do node C " << C->GetHeight() << '\n';
	std::cout << "Altura do node D " << D->GetHeight() << '\n';
	std::cout << "Altura do node E " << E->GetHeight() << '\n';
	std::cout << "Altura do node F " << F->GetHeight() << '\n';

	std::cout << "*****************************************************\n";
	std::cout << "***********************arvore************************\n";
	std::cout << "*****************************************************\n";

	std::cout << "Arvore vazia? " << t->isEmpty() << '\n';
	std::cout << "Grau da arvore " << t->GetTreeDegree() << '\n';
	std::cout << "Altura da arvore " << t->GetTreeHeight() << '\n';

	std::cout << "*****************************************************\n";

	std::cout << "ARVORE EM ORDEM: " << t->TraverseInOrder() << '\n';
	std::cout << "ARVORE EM PRE-ORDEM: " << t->TraversePreOrder() << '\n';
	std::cout << "ARVORE EM POS-ORDEM: " << t->TraversePostOrder() << '\n';

	
	delete t;
	delete F;
	delete E;
	delete D;
	delete C;
	delete B;
	delete A;
}