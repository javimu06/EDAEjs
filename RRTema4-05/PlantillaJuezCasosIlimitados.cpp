// Javier Muñoz Martín de la Sierra
// VJ39


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include "Set.h"


// función que resuelve el problema
void resolver(const std::vector<int>& elementos, const int& nElementos) {
	Set<int> set;

	for (int i = 0; i < elementos.size(); ++i) {
		set.add(elementos[i]);
	}

	for (int i = 0; i < nElementos; ++i) {
		int x;
		x = set.getMin();
		set.removeMin();
		std::cout << x << " ";
	}
	std::cout << "\n";

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	int nElementos;
	std::cin >> nElementos;
	if (nElementos == 0)
		return false;

	int x;
	std::vector<int> elementos;
	std::cin >> x;
	while (x != -1) {
		elementos.push_back(x);
		std::cin >> x;
	}

	resolver(elementos, nElementos);

	// escribir sol


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