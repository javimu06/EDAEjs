// Javier Muñoz Martin de la Sierra
// VJ39


#include <iostream>
#include <iomanip>
#include <fstream>
#include "bintree_eda.h"

// función que resuelve el problema
bool resolver(const bintree<int>& tree, int& nRescates, int nExcursionistas, int& maximosExcursionistas) {
	if (!tree.empty()) {
		if (tree.root() > 0) {
			nExcursionistas += tree.root();
			if (maximosExcursionistas < nExcursionistas)
				maximosExcursionistas = nExcursionistas;
		}
		
		bool rescateIzq = resolver(tree.left(), nRescates, nExcursionistas, maximosExcursionistas);
		bool rescateDer = resolver(tree.right(), nRescates, nExcursionistas, maximosExcursionistas);


		

		if (!rescateIzq && !rescateDer && tree.root() > 0) {
			nRescates++;
			return true;
		}
		else if (rescateDer || rescateIzq) return true;
		return false;
	}
	else return false;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
	// leer los datos de la entrada
	bintree<int> tree;
	tree = leerArbol(-1);
	int nRescates = 0, nExcursionistas = 0, maximosExcursionistas = 0;

	resolver(tree, nRescates, nExcursionistas, maximosExcursionistas);
	// escribir sol

	std::cout << nRescates << " " << maximosExcursionistas << "\n";

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