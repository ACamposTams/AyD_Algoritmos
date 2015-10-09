#include <iostream>
#include <vector>
#include <string>

// Este algoritmo funciona con programación ávida ya que únicamente toma en cuencta la solución del caso del momento en el que se evalúa
// Su complejidad es de O(n) ya que en el pero de los casos debe de detenerse en cada punto del arreglo de las gasolineras para cargar

int truck (int, std::vector<int>);

int main()
{
    int n = 400;
	std::vector<int> gas; // Kilometro en el que esta la gasolinera
	gas.push_back(10);
	gas.push_back(50);
	gas.push_back(90);
	gas.push_back(120);
	gas.push_back(130);
	gas.push_back(530);
	gas.push_back(830);

	std::cout << "Se realizaron: " << truck(n, gas) << " paradas en el recorrido" << std::endl;
}

int truck (int n, std::vector<int> gas) // O(n)
{
	int res = n;
	int stops = 0;
	int dist = 0;
	for (std::vector<int>::iterator i = gas.begin(); i < gas.end(); i++)
	{
		res = res - dist;
		if (i != gas.end()-1)
		{
			dist = *(i + 1) - *i;
		}
		else
		{
			dist = 0;
		}
		if (dist == 0)
		{
			std::cout << "Haz llegado a tu destino" << std::endl;
		}
		else if (res <= 0 || dist > res)
		{
			std::cout << "Detente en el km " << *i << std::endl;
			std::cout << "Siquiente gas: " << dist << std::endl;
			std::cout << "Km restantes de gas: " << res << std::endl << std::endl;
			stops++;
			res = n;
		}
		/*else
		{
			std::cout << "Continua en el km " << *i << std::endl;
			std::cout << "Siquiente gas: " << dist << std::endl;
			std::cout << "Km restantes de gas: " << res << std::endl << std::endl;
		}*/
	}
	return stops;
}