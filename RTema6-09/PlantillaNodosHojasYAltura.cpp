
#include <iostream>
#include <iomanip>
#include <fstream>
#include "bintree_eda.h"

void calculaDiametro(const bintree<char>& tree, int diametroActual, int& diametroMax, int& caminoIzq, int& caminoDer, int& caminoMax, int& caminoDesechado) {
	if (!tree.empty()) {
		if (!tree.left().empty()) {
			calculaDiametro(tree.left(), diametroActual, diametroMax, caminoIzq, caminoDer, caminoMax, caminoDesechado);
			caminoIzq++;
		}
		if (!tree.right().empty()) {
			calculaDiametro(tree.right(), diametroActual, diametroMax, caminoIzq, caminoDer, caminoMax, caminoDesechado);
			caminoDer++;
		}

		diametroActual = caminoIzq + caminoDer - caminoDesechado;
		if (diametroMax < diametroActual) diametroMax = diametroActual;

		if (caminoDer > caminoIzq) caminoDesechado += caminoIzq;
		else caminoDesechado += caminoDer;

	}
}
int diametro(const bintree<char>& tree) {
	int diametroActual = 0;
	int diametroMax = 0;
	int caminoIzq = 0;
	int caminoDer = 0;
	int caminoMax = 0;
	int caminoDesechado = 0;
	calculaDiametro(tree, diametroActual, diametroMax, caminoIzq, caminoDer, caminoMax, caminoDesechado);
	return diametroMax + 1;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
	// leer los datos de la entrada
	bintree<char> tree;
	tree = leerArbol('.');
	if (!tree.empty())
		std::cout << diametro(tree) << "\n";
	else
		std::cout << "0\n";
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
