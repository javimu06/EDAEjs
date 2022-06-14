// Javier Muñoz Martin de la Sierra
// VJ39


#include <iostream>
#include <iomanip>
#include <fstream>
#include "bintree_eda.h"

//Un tramo navegable contiene un caudal <= 3
//Un manantial = 1


//Devuelve el caudal actual
int resolver(const bintree<int>& tree, int& navegable) {
	if (!tree.empty()) {
		int caudalIzq = resolver(tree.left(), navegable);
		int caudalDer = resolver(tree.right(), navegable);

		if (tree.left().empty() && tree.right().empty()) return 1;

		if (caudalIzq + caudalDer - tree.root() >= 3) {
			navegable++;
		}

		if (caudalIzq + caudalDer - tree.root() < 0)
			return 0;
		else {
			return caudalIzq + caudalDer - tree.root();
		}

	}
	else return 0;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
	// leer los datos de la entrada
	bintree<int> tree;
	tree = leerArbol(-1);
	int nNavegable = 0;

	int aux = resolver(tree, nNavegable);
	if (aux >= 3)
		nNavegable--;

		std::cout << nNavegable << "\n";



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