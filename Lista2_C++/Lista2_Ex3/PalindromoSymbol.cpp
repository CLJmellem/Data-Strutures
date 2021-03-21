#include "StaticStack.h"
#include "PalindromoSymbol.h"
#include <string>
#include <iostream>

bool palindromo(StaticStack& stack)
{
	std::string values = stack.values;

	values.erase(remove(values.begin(), values.end(), ' '), values.end());

	int n = values.size();
	char valuesAux[50];
	int i = 0, veri = 0, veriStr = 0, arrX = 0;

	for (int l = 0; l < n; l++) 
	{
		if(values[l] == '{' || values[l] == '}')
		{
			valuesAux[arrX] = '1';
			arrX++;
			veriStr++;
		} 
		if (values[l] == '(' || values[l] == ')')
		{
			valuesAux[arrX] = '2';
			arrX++;
			veriStr++;
		}
		if (values[l] == '[' || values[l] == ']')
		{
			valuesAux[arrX] = '3';
			arrX++;
			veriStr++;
		}
		if (values[l] == '<' || values[l] == '>')
		{
			valuesAux[arrX] = '4';
			arrX++;
			veriStr++;
		}
		if (values[l] == '&')
		{
			valuesAux[arrX] = '5';
			arrX++;
			veriStr++;
		}
		if (values[l] == '|')
		{
			valuesAux[arrX] = '6';
			arrX++;
			veriStr++;
		}

	}

	std::string values2 = valuesAux;
	int j = veriStr - 1;


	for (i; i < veriStr; i++)
	{
		if (values2[i] == values2[j])
		{
			veri++;
			j--;
		}
	}

	if (veri == veriStr)
	{
		return 1;
	}
	else { return 0; }
}