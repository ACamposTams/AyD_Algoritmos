#include <iostream>
#include <vector>

// Este algoritmo es de tipo Backtracking ya que se tienen soluciones parciales que se llegan a deshechar hasta encontrar las más óptimas. 
// Su complejidad es de O(n^2) ya que en el pero de los casos necesita recorrer a todos los hombre y las mujeres ya que aún no han encontrado su pareja estable

void couples(std::vector<std::vector<int>>, std::vector<std::vector<int>>, int);

int main()
{
    int n = 4;

	std::vector<int> men1 = {2,1,0,3};
	std::vector<int> men2 = {1,3,0,2};
	std::vector<int> men3 = {2,0,3,1};
	std::vector<int> men4 = {0,1,2,3};

	std::vector<int> women1 = { 0,2,1,3 };
	std::vector<int> women2 = { 2,3,1,0 };
	std::vector<int> women3 = { 1,2,3,0 };
	std::vector<int> women4 = { 3,1,0,2 };

	std::vector<std::vector<int>> men(n, std::vector<int>(n));

	men = { {men1},{men2},{men3},{men4}};

	std::vector<std::vector<int>> women(n, std::vector<int>(n));

	women = { { women1 },{ women2 },{ women3 },{ women4 }};

	couples(men, women, n);

	return 0;
}

void couples(std::vector<std::vector<int>> womenPreferences, std::vector<std::vector<int>> menPreferences, int n)
{
	std::vector<int>  womenAvailable (n);
	std::vector<bool> menAvailable (n);

	for (int i = 0; i < n; i++)
	{
		womenAvailable[i] = -1;
		menAvailable[i] = true;
	}

	int freeMen = n;
	int currentMan;

	while (freeMen > 0)
	{
		for (int i = 0; i < n; i++)
		{
			if (menAvailable[i] == true)
			{
				currentMan = i;
				break;
			}
		}
		for (int i = 0; i < n && menAvailable[currentMan] == true; i++)
		{
			int woman = womenPreferences[currentMan][i];
			if (womenAvailable[woman] == -1)
			{
				womenAvailable[woman] = currentMan;
				menAvailable[currentMan] = false;
				freeMen--;
			}
			else
			{
				int man = womenAvailable[woman];
				bool preference;
				for (int i = 0; i < n; i++)
				{
					if (menPreferences[woman][i] == man)
					{
						preference = true;
					}
					if (menPreferences[woman][i] == currentMan)
					{
						preference = false;
					}
				}
				if (preference == false)
				{
					womenAvailable[woman] = currentMan;
					menAvailable[currentMan] = false;
					menAvailable[man] = true;
				}
			}
		}
	}
	
	int i = 0;
	for (auto j : womenAvailable)
	{
		std::cout << "Woman: " << i << " goes with Men: " << j << std::endl;
		i++;
	}
}