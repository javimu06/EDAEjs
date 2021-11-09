// Javier Muñoz Martín de la Sierra
// VJ39


#include <iostream>
#include <iomanip>
#include <fstream>
#include <stack>
#include "Date.h"

struct Accidente {
	Date fecha;             //Fecha del accidente
	unsigned int muertes;   //Guarda las muertes 
};

// función que resuelve el problema
void resolver(std::stack<Accidente>& pila) {
	if (pila.empty())
	{
		std::cout << "NO HAY\n";
	}
	else {
		Accidente last = pila.top();
		//Si la ultima es mayor que ninguna de las anteriores, no hay
		//Si hay varios accidentes con mas muertes, hay que encontrar el primero que sea mayor
		while (!pila.empty() && last.muertes >= pila.top().muertes)
			pila.pop();


		if (pila.empty())
			std::cout << "NO HAY\n";
		else
			std::cout << pila.top().fecha;

		pila.push(last);
	}
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	int numCasos;
	std::cin >> numCasos;
	if (!std::cin)
		return false;

	std::stack<Accidente> pila;
	// escribir sol
	for (int i = 0; i < numCasos; ++i)
	{
		// leer los datos de la entrada
		Accidente accidente;
		std::cin >> accidente.fecha >> accidente.muertes;
		pila.push(accidente);
		// escribir sol
		resolver(pila);
	}
	std::cout << "---\n";

	return true;
}

int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
#ifndef DOMJUDGE
	std::ifstream in("datos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 


	while (resuelveCaso());


	// Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}