
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

#include "bintree_eda.h"



template<class T>
void sacaMinimo(T& minimo, bintree<T>const& tree) {
	if (!tree.empty()) {
		if (minimo > tree.root()) minimo = tree.root();
		sacaMinimo(minimo, tree.right());
		sacaMinimo(minimo, tree.left());
	}
}

template<class T>
void Minimo(bintree<T>const& tree) {
	T minimo = tree.root();
	sacaMinimo(minimo, tree);
	std::cout << minimo << "\n";
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	char aux;
	std::cin >> aux;
	if (!std::cin) return false;
	if (aux == 'N') {
		bintree<int> tree;
		tree = leerArbol(-1);
		Minimo(tree);
	}
	else if (aux == 'P') {
		bintree<std::string> tree;
		std::string aux = "#";
		tree = leerArbol(aux);
		Minimo(tree);
	}

	return true;
}

int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
#ifndef DOMJUDGE
	std::ifstream in("datos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif

	while (resuelveCaso());

	// Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	//system("PAUSE");
#endif

	return 0;
}
