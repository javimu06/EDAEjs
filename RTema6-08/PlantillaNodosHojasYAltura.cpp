
#include <iostream>
#include <iomanip>
#include <fstream>
#include "bintree_eda.h"


bool esBinario(const bintree<int>& tree, int max, int min) {
	if (!tree.empty()) {
		//Si alguno de sus hijos no es binario returnea false
		if (!esBinario(tree.left(), max, min) || !esBinario(tree.right(), max, min))
			return false;

		//Raiz estrictamente mayor al hijo izquierdo para que sea binario
		if (!tree.left().empty() && tree.root() > tree.left().root())
			return true;
		//Raiz estrictamente menor al hijo derecho para que sea binario
		if (!tree.right().empty() && tree.root() < tree.right().root())
		return true;


	}
	else return true;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
	// leer los datos de la entrada
	bintree<int> tree;
	tree = leerArbol(-1);

	if (!tree.empty() && esBinario(tree, tree.root(), tree.root()))
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
	//system("PAUSE");
#endif

	return 0;
}