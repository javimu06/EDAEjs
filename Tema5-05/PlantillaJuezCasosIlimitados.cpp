// Javier Muñoz Martín de la Sierra
// VJ39


#include <iostream>
#include <iomanip>
#include <fstream>
#include "queue_eda.h"



// función que resuelve el problema
void resolver(queue<int>& cola) {
	cola.invertir();
	cola.print();
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	bool reading = true;
	queue<int> cola;
	while (reading) {
		int n;
		std::cin >> n;
		if (!std::cin)
			return false;
		if (n == 0)
			reading = false;
		else {
			cola.push(n);
		}
	}
	// escribir sol
	resolver(cola);

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