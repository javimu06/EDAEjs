
#include <iostream>
#include <iomanip>
#include <fstream>
#include "bintree_eda.h"

void calculaGenealogico(const bintree<int>& tree, int generaciones, int& maxGeneraciones, bool& esGenealogico) {
	if (!tree.empty()) {
		//Si tiene primer hijo
		if (!tree.left().empty()) {
			//Si la edad del padre es menor a la del hijo + 18, no se cumple la primera premisa
			if (tree.root() < tree.left().root() + 18) {
				esGenealogico = false;
				return;
			}
			if (!tree.right().empty()) {
				//Si la edad del segundo hijo es mayor que la del primero +2 anyos, no se cumple la segunda premisa
				if (tree.right().root() + 2 > tree.left().root()) {
					esGenealogico = false;
					return;
				}
			}
		}
		else if (!tree.right().empty()) {
			esGenealogico = false;
			return;
		}

		if (esGenealogico) {
			calculaGenealogico(tree.left(), generaciones + 1, maxGeneraciones, esGenealogico);
			calculaGenealogico(tree.right(), generaciones + 1, maxGeneraciones, esGenealogico);
		}
	}
	else {
		if (maxGeneraciones < generaciones)
			maxGeneraciones = generaciones;
	}
}

void genealogico(const bintree<int>& tree) {
	int generaciones = 0;
	int maxGeneraciones = 0;
	bool esGenealogico = true;
	calculaGenealogico(tree, generaciones, maxGeneraciones, esGenealogico);
	if (esGenealogico)
		std::cout << "SI " << maxGeneraciones << "\n";
	else
		std::cout << "NO\n";

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
	// leer los datos de la entrada
	bintree<int> tree;
	tree = leerArbol(-1);
	genealogico(tree);
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
