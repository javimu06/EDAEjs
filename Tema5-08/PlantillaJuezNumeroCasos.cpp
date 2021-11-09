// Javier Muñoz Martin de la Sierra
// VJ39


#include <iostream>
#include <iomanip>
#include <fstream>
#include "queue_eda.h"

// función que resuelve el problema
void resolver(queue<int>& original,const int pringao, queue<int>& chavales) {
	original.print();
	original.colar(pringao, chavales);
	original.print();
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
	// leer los datos de la entrada
	bool reading = true;
	queue<int> colaOriginal;
	while (reading) {
		int x;
		std::cin >> x;
		if (x == -1)
			reading = false;
		else {
			colaOriginal.push(x);
		}
	}
	reading = true;
	int pringao;
	std::cin >> pringao;

	queue<int> chavales;
	while (reading) {
		int x;
		std::cin >> x;
		if (x == -1)
			reading = false;
		else {
			chavales.push(x);
		}
	}

	resolver(colaOriginal, pringao, chavales);
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