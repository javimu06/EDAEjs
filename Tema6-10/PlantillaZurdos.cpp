
#include <iostream>
#include <iomanip>
#include <fstream>
#include "bintree_eda.h"
using namespace std;



template <class T>
bool esZurdo(const bintree<T>& tree, int& nNodes) {
	if (tree.empty())
		return true;
	if (tree.left().empty() && tree.right().empty()) {
		nNodes++;
		return true;
	}
	

	int nodosIzq = 0;
	int nodosDr = 0;
	bool izquierdo = esZurdo(tree.left(), nodosIzq);
	bool derecho = esZurdo(tree.right(), nodosDr);

	nNodes = nodosIzq + nodosDr + 1;

	return(izquierdo && derecho && nodosIzq > nodosDr);
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
	// leer los datos de la entrada
	bintree<char> tree;
	tree = leerArbol('.');
	int aux = 0;
	if (esZurdo(tree, aux))
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
	//system("PAUSE");
#endif

	return 0;
}
