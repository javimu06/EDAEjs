// Javier Muñoz Martin de la Sierra
// VJ39


#include <iostream>
#include <iomanip>
#include <fstream>
#include "queue_eda.h"


// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
	// leer los datos de la entrada
	queue<int> colaOriginal;
	queue<int> colegas;
	int pringao;

	int x;
	std::cin >> x;
	while (x != -1) {
		colaOriginal.push(x);
		std::cin >> x;
	}

	std::cin >> pringao;

	std::cin >> x;
	while (x != -1) {
		colegas.push(x);
		std::cin >> x;
	}


	// escribir sol
	colaOriginal.print();
	colaOriginal.cuela(pringao, colegas);
	colaOriginal.print();

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