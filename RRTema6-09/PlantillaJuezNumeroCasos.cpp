// Javier Muñoz Martin de la Sierra
// VJ39


#include <iostream>
#include <iomanip>
#include <fstream>
#include "bintree_eda.h"

// función que resuelve el problema
int resolver(const bintree<char>& tree, int& diametro) {
	if (!tree.empty()) {
		int longitudIzq = resolver(tree.left(), diametro);
		int longitudDer = resolver(tree.right(), diametro);
		//0 , 0
		if (longitudIzq + longitudDer > diametro) diametro = longitudIzq + longitudDer;

		if (longitudIzq < longitudDer) return longitudDer + 1;
		else return longitudIzq + 1;

	}
	else return 0;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
	// leer los datos de la entrada
	bintree<char> tree;
	tree = leerArbol('.');
	int diametro = 0;
	resolver(tree, diametro);
	if (!tree.empty())
		std::cout << diametro + 1 << "\n";
	else
		std::cout << 0 << "\n";
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