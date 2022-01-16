
#include <iostream>
#include <iomanip>
#include <fstream>
#include "bintree_eda.h"

bool esPrimo(int n) {
	int divisores = n / 2;
	for (int i = 2; i <= divisores; i++) {
		//Si encuentro un divisor NO ES PRIMO
		if (n % i == 0) return false;
	}
	return true;
}

bool divisible(int n) {
	if (n >= 7 && n % 7 == 0) return true;
	return false;
}

void calculaAccesible(const bintree<int>& tree, int& multiplo, int& nCaminoMinimo, int nCamino, bool& finded) {
	if (!tree.empty()) {
		//Si el numero no es primo y es divisible entre 7
		if (!esPrimo(tree.root()) && divisible(tree.root())) {
			//Si el camino es mejor actualizo
			if (nCaminoMinimo > nCamino) {
				nCaminoMinimo = nCamino;
				multiplo = tree.root();
				finded = true;
			}
		}
		//Si el nodo es accesible pasamos a sus hijos
		if (!esPrimo(tree.root())) {
			calculaAccesible(tree.left(), multiplo, nCaminoMinimo, nCamino + 1, finded);
			calculaAccesible(tree.right(), multiplo, nCaminoMinimo, nCamino + 1, finded);
		}
	}
}

//Tenemos que sacar la altura del camino
//El valor del numero
void accesible(const bintree<int>& tree) {
	int multiplo_;
	int nCaminoMinimo_ = 1000000000;
	int nCamino = 0;
	bool finded = false;
	calculaAccesible(tree, multiplo_, nCaminoMinimo_, nCamino, finded);
	if (finded)
		std::cout << multiplo_ << " " << nCaminoMinimo_ + 1 << "\n";
	else
		std::cout << "NO HAY\n";
}


// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
	// leer los datos de la entrada
	int n;
	bintree<int> tree;
	tree = leerArbol(-1);

	accesible(tree);

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
