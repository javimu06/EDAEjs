
#include <iostream>
#include <iomanip>
#include <fstream>
#include "bintree_eda.h"

int esZurdo(const bintree<char>& tree) {
	if (!tree.empty()) {
		int nodosIzq = esZurdo(tree.left());
		int nodosDer = esZurdo(tree.right());


		if ((nodosDer == 0 && nodosIzq == 0))
			return 1;
		if (nodosDer >= nodosIzq)
			return -1;

		return nodosDer + nodosIzq + 1;
	}
	else return 0;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
	// leer los datos de la entrada
	bintree<char> tree;
	tree = leerArbol('.');
	int a = esZurdo(tree);
	if (a < 0)
		std::cout << "NO\n";
	else
		std::cout << "SI\n";
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
