// Javier Muñoz Martin de la Sierra
// VJ39


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

#include "bintree_eda.h"

// función que resuelve el problema
void calculaFrontera(const bintree<int>& tree, std::vector<int>& frontera) {
	if (!tree.empty()) {
		calculaFrontera(tree.left(), frontera);
		calculaFrontera(tree.right(), frontera);

		if (tree.left().empty() && tree.right().empty())
			frontera.push_back(tree.root());
	}
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
	// leer los datos de la entrada
	bintree <int> tree;
	tree = leerArbol(-1);
	std::vector<int> frontera;
	calculaFrontera(tree, frontera);
	// escribir sol
	for (int i = 0; i < frontera.size(); ++i) {
		std::cout << frontera[i] << " ";
	}
	std::cout << "\n";
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