// Javier Muñoz Martin de la Sierra
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
void resuelveCaso(std::stack<Accidente>& pila) {
	// leer los datos de la entrada
	Accidente accidente;
	std::cin >> accidente.fecha >> accidente.muertes;
	pila.push(accidente);
	// escribir sol
	resolver(pila);
}

int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
#ifndef DOMJUDGE
	std::ifstream in("datos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 


	int numCasos;
	std::cin >> numCasos;
	std::stack<Accidente> pila;
	for (int i = 0; i < numCasos; ++i)
		resuelveCaso(pila);
	std::cout << "---\n";


	// Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}