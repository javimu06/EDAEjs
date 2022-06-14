// Javier Muñoz Martin de la Sierra
// VJ39


#include <iostream>
#include <iomanip>
#include <fstream>
#include "bintree_eda.h"

bool esAccesible(const int& elemento) {
	bool esPrimo = true;
	for (int i = 2; i < (elemento / 2) + 1; ++i) {
		//Si
		if (elemento % i == 0)
			esPrimo = false;
	}

	return !esPrimo;
}

void resolver(const bintree<int>& tree, int& elemento, int altura, int& minAltura, bool& finded) {
	if (!tree.empty()) {
		altura++;

		//Si es accesible y es divisible entre 7
		if (esAccesible(tree.root()) && tree.root() % 7 == 0) {

			if (minAltura > altura) {
				minAltura = altura;
				elemento = tree.root();
				finded = true;
			}
		}

		//Si es accesible pasamos a los hijos 
		if (esAccesible(tree.root())) {
			resolver(tree.left(), elemento, altura, minAltura, finded);
			resolver(tree.right(), elemento, altura, minAltura, finded);
		}
	}

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
	// leer los datos de la entrada
	bintree<int> tree;
	tree = leerArbol(-1);
	if (!tree.empty()) {
		int elemento = tree.root(), altura = 0, minAltura = 100000;
		bool finded = false;
		resolver(tree, elemento, altura, minAltura, finded);
		if (finded)
			std::cout << elemento << " " << minAltura << "\n";
		else
			std::cout << "NO HAY\n";
	}
	else
		std::cout << "NO HAY\n";
	// escribir sol


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