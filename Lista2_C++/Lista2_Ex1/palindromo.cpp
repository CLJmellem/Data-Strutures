#include "StaticStack.h"
#include "palindromo.h"
#include <string>
#include <iostream>

bool palindromo(StaticStack &stack)
{
	std::string values = stack.values;

	values.erase(remove(values.begin(), values.end(), ' '), values.end());

	int n = values.size();
	int m = n / 2;
	int i = 0, j = n - 1, veri = 0;

	for (i; i < m; i++)
	{
		if (values[i] == values[j])
		{
			veri++;
			j--;
		}
	}

	if (veri == m)
	{
		return 1;
	}
	else { return 0; }
}