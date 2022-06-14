
#include <iostream>
#include <iomanip>
#include <fstream>
#include "bintree_eda.h"
using namespace std;

template <class T>
void cuentaAlturas(bintree<T> const& tree, int nAlturas, int& maxAltura) {
	if (!tree.empty()) {
		nAlturas++;

		cuentaAlturas(tree.left(), nAlturas, maxAltura);
		cuentaAlturas(tree.right(), nAlturas, maxAltura);

		if (tree.right().empty() && tree.right().empty()) {
			if (maxAltura < nAlturas) maxAltura = nAlturas;
		}
	}
}

template <class T>
int altura(bintree<T> const& tree) {
	int nAlturas = 0, maxAltura = 0;
	cuentaAlturas(tree, nAlturas, maxAltura);
	return maxAltura;
}



template <class T>
void cuentaNodos(bintree<T> const& tree, int& nNodos) {
	if (!tree.empty()) {
		nNodos++;
		cuentaNodos(tree.left(), nNodos);
		cuentaNodos(tree.right(), nNodos);
	}
}

template <class T>
int nodos(bintree<T> const& tree) {
	int nNodos = 0;
	cuentaNodos(tree, nNodos);
	return nNodos;
}

template <class T>
void cuentaHojas(bintree<T> const& tree, int& nHojas) {
	if (!tree.empty()) {
		if (tree.right().empty() && tree.left().empty()) {
			nHojas++;
		}
		cuentaHojas(tree.left(), nHojas);
		cuentaHojas(tree.right(), nHojas);
	}
}

template <class T>
int hojas(bintree<T> const& tree) {
	int nHojas = 0;
	cuentaHojas(tree, nHojas);
	return nHojas;
}




// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
	// leer los datos de la entrada
	int n;
	bintree<char> tree;
	tree = leerArbol('.');
	cout << nodos(tree) << " " << hojas(tree) << " " << altura(tree) << endl;
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
