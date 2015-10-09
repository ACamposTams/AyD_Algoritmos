#include <iostream>
#include <vector>
#include <string>

// El algoritmo de las subsecuencias en donde no se considera el orden de las mismas funciona con programación dinámica ya que primero se gener auna tabla 
// con las posibles soluciones al problema y después se consulta esa tabla para resolver el problema.
// Tiene una comlejidad de O(n*m) ya que en el peor caso se tiene que recorrer toda la tabla y no se lleg a encontrar ninguna subsecuencia

template <class T>
std::vector<T> maxSubsequence(std::vector<T>, std::vector<T>);

int main()
{
    // Prueba con enteros
    /*std::vector<int> x;
	for (int i = 1; i <= 5; i++)
	{
		x.push_back(i);
	}
	std::vector<int> y;
	for (int i = 2; i <= 6; i++)
	{
		y.push_back(i);
	}*/

	// Prueba con char
	std::vector<char> c;
	c.push_back(*"a");
	c.push_back(*"b");
	c.push_back(*"c");
	c.push_back(*"b");
	c.push_back(*"d");
	c.push_back(*"a");
	c.push_back(*"b");

	std::vector<char> a;
	a.push_back(*"b");
	a.push_back(*"d");
	a.push_back(*"c");
	a.push_back(*"a");
	a.push_back(*"b");
	a.push_back(*"a");

	std::cout << "La subsecuencia más grande es: ";
	
	std::vector<char> subsequence = maxSubsequence<char>(a, c);

	for (int i = subsequence.size()-1; i >= 0;i--)
	{
		std::cout << subsequence[i] << " ";
	}

	std::cout << std::endl;
}

template <class T>
std::vector<T> maxSubsequence(std::vector<T> x, std::vector<T> y)
{
	std::vector<T> largestSubsequence;
	std::vector<T> tempSubsequence;
	std::vector<std::vector<T>> table (x.size()+1, std::vector<T>(y.size()+1));

	for (int i = 1; i <= x.size(); i++)
	{
		for (int j = 1; j <= y.size(); j++)
		{
			if (x[i-1] == y[j-1])
			{
				table[i][j] = 1 + table[i-1][j-1];
			}
			else
			{
				if (table[i-1][j] >= table[i][j-1])
				{
					table[i][j] = table[i-1][j];
				}
				else
				{
					table[i][j] = table[i][j-1];
				}
			}
		}
	}

	int column = x.size();
	int row = y.size();

	while (row != 0 && column != 0)
	{
		if (x[column-1] == y[row-1])
		{
			largestSubsequence.push_back(x[column-1]);
			row--;
			column--;
		}
		else
		{
			if (table[column - 1][row] > table[column][row - 1])
			{
				column--;
			}
			else
			{
				row--;
			}
		}
	}
	return largestSubsequence;
	
	// En caso de que la subsecuencia deba ser continua se aplica este algoritmo que emplea programacion avida y cuya complejidad es de O(n^3)
	/*for (int i = 0; i < x.size()-1; i++)
	{
		int j = i;
		for (int k = 0; k < y.size()-1; k++)
		{
		int l = k;
		while (j<=x.size()-1 && k<=y.size()-1 && x[j] == y[k])
		{
			tempSubsequence.push_back(x[j]);
			j++;
			k++;
		}
		if (tempSubsequence.size() > largestSubsequence.size())
		{
			largestSubsequence.clear();
			largestSubsequence = tempSubsequence;
		}
			tempSubsequence.clear();
		}
	}
	
	return largestSubsequence; */
}