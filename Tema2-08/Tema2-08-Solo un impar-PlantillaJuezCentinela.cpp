// Javier Muñoz Martin de la Sierra
// VJ39


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>


// función que resuelve el problema
int resolver(const std::vector<int>& datos, const int& init, const int& fin) {
	//Caso Base
	if (fin - init == 1)
		return datos[init];

	int i = 0;
	int suma = 0;
	bool searching = true;
	//Recorremos la primera mitad del vector hasta que encontremos una suma impar o acabemos el recorrido
	while (searching && i <= (init + fin) / 2) {
		//Si encontramos un numero que al dividir entre 2 no de resto 0, hemos encontrado un impar
		if (suma % 2 != 0)
			searching = false;
		//Sumamos y avanzamos la i
		suma += datos[i];
		i++;
	}
	//Distinguimos si hemos encontrado un impar(mitad izquierda) o si no lo hemos encontrado (el impar esta en la otra mitad)
	if (!searching) return resolver(datos, init, (init + fin) / 2);
	else return resolver(datos, (init + fin) / 2, fin);
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	int nElems;
	std::cin >> nElems;
	if (nElems == 0)
		return false;
	std::vector<int>nArray(nElems);
	for (int i = 0; i < nElems; i++)
		std::cin >> nArray[i];

	int sol = resolver(nArray, 0, nElems);
	// escribir sol
	std::cout << sol<<"\n";

	return true;
}

int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
#ifndef DOMJUDGE
	std::ifstream in("datos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 


	while (resuelveCaso())
		;


	// Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}
