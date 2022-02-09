#include <iostream>
#include <fstream>
#include "bintree_eda.h"
using namespace std;

void calculaCaudal(const bintree<int>& tree, int& caudalNodo, int& tramosNavegables) {
	if (!tree.empty()) {
		//Recorremos el arbol entero para empezar por debajo
		calculaCaudal(tree.left(), caudalNodo, tramosNavegables);
		int caudalIzq = caudalNodo;
		caudalNodo = 0;
		calculaCaudal(tree.right(), caudalNodo, tramosNavegables);
		int caudalDer = caudalNodo;
		caudalNodo = 0;

		//Nacimiento
		if (caudalIzq == -1 && caudalDer == -1) {
			//El caudal de ese nodo nacimiento es 1
			caudalNodo = 1;
		}
		//Si es un afluente
		else {

			if (caudalIzq == -1) {
				//Sumo los dos caudales
				caudalNodo = caudalDer - tree.root();
			}
			else if (caudalDer == -1) {
				caudalNodo = caudalIzq - tree.root();
			}
			else
				caudalNodo = caudalIzq + caudalDer - tree.root();

			if (caudalNodo >= 3)
				tramosNavegables++;
			if (caudalNodo < 0)
				caudalNodo = 0;

		}
	}
	else caudalNodo = -1;
}

int caudal(const bintree<int>& arb) {
	int tramosNavegables = 0;
	int caudalN = 0;
	calculaCaudal(arb, caudalN, tramosNavegables);

	if (caudalN >= 3)
		return tramosNavegables - 1;
	return tramosNavegables;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
	bintree<int> arb;
	arb = leerArbol(-1); // -1 es la repr. de arbol vacio
	std::cout << caudal(arb) << "\n";
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

