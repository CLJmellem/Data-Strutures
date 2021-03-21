#include <iostream>
#include "PalindromoSymbol.h"
#include "StaticStack.h"


int main()
{
	StaticStack stack = Create();

	std::string frase; std::cout << "Digite a frase: "; std::cin >> frase;

	for (int i = 0; i < frase.size(); i++)
	{
		Push(stack, frase[i]);
	}

	std::cout << palindromo(stack);
}


