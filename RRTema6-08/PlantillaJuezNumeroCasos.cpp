// Javier Muñoz Martin de la Sierra
// VJ39


#include <iostream>
#include <iomanip>
#include <fstream>
#include "bintree_eda.h"
#include <climits>

// función que resuelve el problema
bool esBinario(const bintree<int>& tree, int minimo, int maximo) {
	if (!tree.empty()) {
		if (tree.root() <= minimo || tree.root() >= maximo) 
			return false;
		return esBinario(tree.left(), minimo, tree.root()) && esBinario(tree.right(), tree.root(), maximo);
	}
	else return true;

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
	// leer los datos de la entrada
	bintree<int> tree;
	tree = leerArbol(-1);

	if (esBinario(tree, INT_MIN, INT_MAX))
		std::cout << "SI\n";
	else
		std::cout << "NO\n";

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