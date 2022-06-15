// Javier Muñoz Martin de la Sierra
// VJ39


#include <iostream>
#include <iomanip>
#include <fstream>
#include "bintree_eda.h"


//Devuelve el valor de los de debajo
int resolver(const bintree<int>& tree, int antecesores, int& singulares) {
	if (!tree.empty()) {
		//Cuando bajo voy sumando antecesores
		antecesores += tree.root();

		int nodosIzq = resolver(tree.left(), antecesores, singulares);
		int nodosDer = resolver(tree.right(), antecesores, singulares);

		//Cuando subo compruebo si se cumple la condicion para subir singulares y devuelvo todos los valores
		if (antecesores - tree.root() == nodosDer + nodosIzq) {
			singulares++;
		}
		return nodosIzq + nodosDer + tree.root();

	}
	else return 0;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
	// leer los datos de la entrada
	bintree<int> tree;
	tree = leerArbol(-1);

	int singulares = 0;
	resolver(tree, 0, singulares);

	// escribir sol
	std::cout << singulares << "\n";

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