// Javier Muñoz Martin de la Sierra
// VJ39


#include <iostream>
#include <iomanip>
#include <fstream>
#include "bintree_eda.h"

bool esValida(const bintree<int>& tree) {
	if (!tree.left().empty()) {
		if (tree.root() < tree.left().root() + 18)
			return false;
	}
	if (tree.left().empty() && !tree.right().empty()) return false;
	if (!tree.right().empty()) {
		if (tree.root() < tree.right().root() + 18)
			return false;
	}
	if (!tree.left().empty() && !tree.right().empty()) {
		if (tree.left().root() < tree.right().root() + 2)
			return false;
	}
	return true;
}


// función que resuelve el problema
bool resolver(const bintree<int>& tree, int altura, int& generaciones) {
	if (!tree.empty()) {
		altura++;
		if (esValida(tree)) {
			if (generaciones < altura) generaciones = altura;
			return resolver(tree.left(), altura, generaciones) && resolver(tree.right(), altura, generaciones);
		}
		else return false;
	}
	else return true;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
	// leer los datos de la entrada
	bintree<int> tree;
	tree = leerArbol(-1);
	if (tree.empty())
		std::cout << "SI 0\n";
	else {
		int generaciones = 0;

		if (resolver(tree, 0, generaciones))
			std::cout << "SI " << generaciones << "\n";
		else
			std::cout << "NO\n";
	}
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