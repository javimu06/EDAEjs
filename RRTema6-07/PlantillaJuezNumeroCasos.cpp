// Javier Muñoz Martin de la Sierra
// VJ39


#include <iostream>
#include <iomanip>
#include <fstream>
#include "bintree_eda.h"

bool compruebaSimetria(const bintree<char>& treeLeft, const bintree<char>& treeRight) {
	if (treeLeft.empty() && treeRight.empty()) return true;
	else if ((treeLeft.empty() && !treeRight.empty()) || (!treeLeft.empty() && treeRight.empty())) return false;
	else {
		return compruebaSimetria(treeLeft.left(), treeRight.right()) && compruebaSimetria(treeLeft.right(), treeRight.left());
	}
}


bool resuelve(const bintree<char>& tree) {
	if (!tree.empty()) {
		return compruebaSimetria(tree.left(), tree.right());
	}
	else return true;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
	// leer los datos de la entrada
	bintree<char> tree;
	tree = leerArbol('.');

	if (resuelve(tree))
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
	system("PAUSE");
#endif

	return 0;
}