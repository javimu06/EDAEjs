
#include <iostream>
#include <iomanip>
#include <fstream>
#include "bintree_eda.h"
using namespace std;


template <class T>
bool compruebaGenealogico(const bintree<T>& nodo, int& edad, int generaciones, int& maxGen) {

	if (!nodo.empty()) {
		edad = nodo.root();


		int edadIzq, edadDr;
		generaciones++;
		if (!compruebaGenealogico(nodo.left(), edadIzq, generaciones, maxGen) || !compruebaGenealogico(nodo.right(), edadDr, generaciones, maxGen))
			return false;

		bool compruebaIzq;
		if (edadIzq != -1 && edadDr != -1)
			return(compruebaIzq = edad >= edadIzq + 18 && edadIzq >= edadDr + 2);
		else if (edadIzq != -1)
			return(compruebaIzq = edad >= edadIzq + 18);
		else if (edadDr != -1)
			return(edadIzq >= edadDr + 2);
		else
			return true;
	}
	else {
		edad = -1;
		if (maxGen < generaciones)maxGen = generaciones;
		return true;
	}
}
// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
	// leer los datos de la entrada
	int n;
	bintree<int> tree;
	tree = leerArbol(-1);
	int edad = 0;
	int generaciones = 0;
	int maxGen = 0;
	if (compruebaGenealogico(tree, edad, generaciones, maxGen))
		std::cout << "SI " << maxGen << "\n";
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
