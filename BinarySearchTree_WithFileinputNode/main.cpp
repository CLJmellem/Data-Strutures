//Nome: Cássio Luis Junqueira Mellem Filho
//TIA: 32089694
//João Vitor Lima Lipert
//TIA: 32088876
//Eric Felipeli César Dias Pereira
//TIA: 41911296


#include <iostream>
#include <sstream>
#include <cstdlib>
#include <fstream>
#include "Tree.h"


int main()
{
	int salary, year, gastos[62], gastosF = 0, sum = 0, idade[62], j = 0, maior, menor, cargosF = 62;
	std::string cargos[62];
	setlocale(LC_ALL, "pt_BR.UTF-8");
	int totalFunc = 0;
	std::ifstream inFile;

	inFile.open("DataSetFinal.txt");

	Node* aux = new Node();
	Tree* t = new Tree();

	//Check for Error
	if (inFile.fail()) {
		std::cerr << "Error Opening File";
		exit(1);
	}
	else
	{
		std::string line, cell;
		std::string cellArr[5];

		while (std::getline(inFile, line))
		{
			int i = 0;
			totalFunc++;
			std::stringstream lineStream(line);

			Node* node = new Node();

			while (std::getline(lineStream, cell, ';'))
			{
				cellArr[i] = cell;
				i++;
			}

			salary = std::stoi(cellArr[4]);
			year = std::stoi(cellArr[3]);

			node->SetData(cellArr[0]);
			node->SetCargo(cellArr[1]);
			node->SetAnoAdm(cellArr[2]);
			node->SetYear(year);
			node->SetSalary(salary);
			node->SetParent(aux);
			gastos[j] = node->GetSalary();
			idade[j] = 2020 - node->GetYear();
			cargos[j] = node->GetCargo();
			if (t->GetRoot() == NULL)
			{
				t->SetRoot(node);
				aux = t->GetRoot();
			}
			else
			{
				aux = aux->PopulateTree(node, aux);
			}
			j++;
		}

	}
	for (int i = 0; i < 62; i++)
	{
		gastosF += gastos[i];
	}
	for (int i = 0; i < 62; i++) {
		sum += idade[i];
	}
	maior = gastos[0];
	for (int i = 0; i < 62; i++)
	{
		if (maior < gastos[i])
			maior = gastos[i];
	}
	menor = gastos[0];
	for (int i = 0; i < 62; i++)
	{
		if (menor > gastos[i])
			menor = gastos[i];
	}
	for (int i = 0; i < 62; i++)
	{
		for (int j = i + 1; j < 62; j++)
		{
			if (cargos[i] == cargos[j])
			{
				cargos[i] = "";
				cargosF--;
			}
		}
	}


	std::cout << "Numero Total De Funcionarios: " << totalFunc << "\n";
	std::cout << "Media Idade:" << sum / 62 << "\n";
	std::cout << "Montante Gasto Com Salarios: " << gastosF << "\n";
	std::cout << "Media Salarial:" << gastosF / 62 << "\n";
	std::cout << "Maior:" << maior << " Menor:" << menor << "\n";
	std::cout << "Quantidade de cargos diferentes: " << cargosF << "\n";
	std::cout << "Cargos que existem na empresa: ";
	for (int i = 0; i < 62; i++)
	{
		if (cargos[i] != "")
		{
			std::cout << cargos[i] << ", ";
		}
	}

	inFile.close();

	delete t;
}

//Referências utilizadas no Projeto
//https://stackoverflow.com/questions/415515/how-can-i-read-and-manipulate-csv-file-data-in-c
//https://simplesnippets.tech/what-is-binary-search-tree-bst-with-full-code-dsa/