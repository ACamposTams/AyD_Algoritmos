//funcion creada para rellenar numeros.txt con 1000000 de números diferentes

#include <algorithm>
#include <iostream>
#include <fstream>

int main()
{

    std::ofstream file;

    file.open("./numeros.txt");

    for(int i = 0; i < 1000000; ++i)
    {
            file << rand() % 10000 << std::endl;
    }

    return 0;
}