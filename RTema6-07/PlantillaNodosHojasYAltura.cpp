
#include <iostream>
#include <iomanip>
#include <fstream>
#include "bintree_eda.h"

bool compruebaSimetria(const bintree<char>& left, const bintree<char>& right)
{
	if (left.empty() && right.empty()) return true;
	else if (left.empty() && !right.empty() || !left.empty() && right.empty()) return false;
	else
		return compruebaSimetria(left.left(), right.right()) && compruebaSimetria(left.right(), right.left());
}
bool esSimetrico(const bintree<char>& tree) {
	if (tree.empty())
		return true;
	else
		return compruebaSimetria(tree.left(), tree.right());
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
	// leer los datos de la entrada
	int n;
	bintree<char> tree;
	tree = leerArbol('.');

	if (esSimetrico(tree))
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
