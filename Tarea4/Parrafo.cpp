#include <iostream>
#include <vector>
#include <math.h>

// Este algoritmo es ávido ya que prueba en cada palabra por separado si esta cabe dentro de la línea sin considerar las palabras que siguen
// Su complejidad es de O(n) ya que solamente recorre el string que se le da como parametro palabra por palabra hasta llegar a n palabras

void paragraph (float, float, std::string);

int main ()
{
    float L = 30; // tamaño línea
	float b = 2; // tamaño del espacio

	std::string line = "Esta es la frase a colocar dentro del parrafo";

	std::cout << "Si L = 30 y b = 2: " << std::endl;
	paragraph(L,b,line);

	b = 1;
	
	std::cout << "Si L = 30 y b = 1: " << std::endl;
	paragraph(L, b, line);
}

void paragraph(float sizeLine, float b, std::string line)
{
	std::vector<int> wordSizes;
	std::vector<std::string> words;
	int wordSize = 0;
	std::string word;
	float bPrime = 0;
	std::vector<std::string> realLine;
	float tempSizeLine = 0; // Linea con los valores insertados y con sus espacios
	float residue = 0;
	float bIfReduce = 0;
	int j = 0;
	float currentLen = 0; // Linea con los valores insertados
	bool printed = true;

	for (int i = 0; i < line.size(); i++)
	{
		if (line[i] != *" ")
		{
			wordSize++;
			word = word + line[i];
		}
		else
		{
			wordSizes.push_back(wordSize);
			words.push_back(word);
			wordSize = 0;
			word = "";
		}
	}
	wordSizes.push_back(wordSize);
	words.push_back(word);

	for (int i = 0; i < words.size(); i++)
	{
		if (printed)
		{
			j = i;
			printed = false;
			realLine.clear();
			currentLen = 0;
		}
		
		currentLen = currentLen + wordSizes[i];
		tempSizeLine = currentLen + ((i - j)*b);

		if (tempSizeLine > sizeLine)
		{
			residue = tempSizeLine - sizeLine;
			bIfReduce = b - (residue / (i - j));
			bPrime = b + (sizeLine - ((currentLen - wordSizes[i]) + (b*(i - j - 1)))) / (i - j - i);
			if (bIfReduce > 0 && ((fabs(bPrime - b)*(i - j - 1)) > (fabs(bIfReduce - b)*(j - i))))
			{
				realLine.push_back(words[i]);
				for (auto t : realLine)
				{
					std::cout << t << " ";
				}
				std::cout << " ||||||Tamaño del espacio " << bIfReduce << std::endl;
				printed = true;
			}
			else
			{
				for (auto t : realLine)
				{
					std::cout << t << " ";
				}
				std::cout << "||||||Tamaño del espacio " << bPrime << std::endl;
				j--;
				printed = true;
			}
		}
		else
		{
			realLine.push_back(words[i]);
		}
	}

	for (auto t : realLine)
	{
		std::cout << t << " ";
	}

	std::cout << std::endl << std::endl;

}