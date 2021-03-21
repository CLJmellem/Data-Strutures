#include <iostream>
#include "PalindromoDate.h"
#include "StaticStack.h"


int main()
{
	StaticStack stack = Create();

	std::string data; std::cout << "Digite a data: "; std::cin >> data;

	for (int i = 0; i < data.size(); i++)
	{
		Push(stack, data[i]);
	}

	std::cout << palindromo(stack);
}


