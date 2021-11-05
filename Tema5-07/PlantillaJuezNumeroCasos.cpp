// Javier Muñoz Martin de la Sierra
// VJ39


#include <iostream>
#include <iomanip>
#include <fstream>
#include "queue_eda.h"


// función que resuelve el problema
void resolver(queue<unsigned int>& a, queue<unsigned int>& b) {


}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
	// leer los datos de la entrada
	queue<unsigned int> a;
	queue<unsigned int> b;
	bool readA = true;
	bool readB = true;
	while (readB) {
		int next;
		std::cin >> next;
		if (readA) {
			if (next == 0)
				readA = false;
			else
				a.push(next);
		}
		else {
			if (next == 0)
				readB = false;
			else
				b.push(next);
		}
	}
	resolver(a, b);
	// escribir sol
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
	for (int i = 0; i < numCasos; ++i)
		resuelveCaso();


	// Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}