
#include <iostream>
#include <iomanip>
#include <fstream>
#include "bintree_eda.h"
using namespace std;

template <class T>
void cuentaNodos(int& nNodos, bintree<T> const& tree) {
	if (!tree.empty()) {
		nNodos++;
		cuentaNodos(nNodos, tree.left());
		cuentaNodos(nNodos, tree.right());
	}
}

template <class T>
int nodos(bintree<T> const& tree) {

	int nNodos = 0;
	cuentaNodos(nNodos, tree);
	return nNodos;
}


template<class T>
void cuentaHojas(int& nHojas, bintree<T>const& tree) {
	if (!tree.empty()) {
		if (tree.left().empty() && tree.right().empty())
			nHojas++;
		else {
			cuentaHojas(nHojas, tree.left());
			cuentaHojas(nHojas, tree.right());
		}
	}
}

template<class T>
int hojas(bintree<T> const& tree) {
	int nHojas = 0;
	cuentaHojas(nHojas, tree);
	return nHojas;
}

template<class T>
void cuentaAlturas(int nAlturas, int& maxnAlturas, bintree<T>const& tree) {
	if (!tree.empty()) {
		nAlturas++;
		cuentaAlturas(nAlturas, maxnAlturas, tree.right());
		cuentaAlturas(nAlturas, maxnAlturas, tree.left());
	}
	else
		if (maxnAlturas < nAlturas) maxnAlturas = nAlturas;

}

template<class T>
int altura(bintree<T>const& tree) {
	int nAlturas = 0;
	int maxnAlturas = 0;
	cuentaAlturas(nAlturas, maxnAlturas, tree);
	return maxnAlturas;
}
// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
	// leer los datos de la entrada
	int n;
	bintree<char> tree;
	tree = leerArbol('.');
	cout << nodos(tree) << " " << hojas(tree) << " " << altura(tree) << "\n";
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
