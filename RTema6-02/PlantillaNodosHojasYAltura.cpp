
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>


#include "bintree_eda.h"

template <class T>
void cuentaFrontera(bintree<T> const& tree, std::vector<int>& fronteraSol) {
	if (!tree.empty()) {
		if (tree.right().empty() && tree.left().empty())
			fronteraSol.push_back(tree.root());
		else {
			cuentaFrontera(tree.right(), fronteraSol);
			cuentaFrontera(tree.left(), fronteraSol);
		}
	}
}

template <class T>
std::vector<int> frontera(bintree<T> const& tree) {
	std::vector<int> fronteraSol;
	cuentaFrontera(tree, fronteraSol);
	return fronteraSol;
}



// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
	// leer los datos de la entrada
	int n;
	bintree<int> tree;
	tree = leerArbol(-1);
	std::vector<int> sol;
	sol = frontera(tree);

	while (!sol.empty()) {
		std::cout << sol.back() << " ";
		sol.pop_back();
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
	//system("PAUSE");
#endif

	return 0;
}
