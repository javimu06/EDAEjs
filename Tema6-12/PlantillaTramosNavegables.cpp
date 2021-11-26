#include <iostream>
#include <fstream>
#include "bintree_eda.h"
using namespace std;

int recorreNavegable(const bintree<int>& arb, int& nCaminos) {
	if (!arb.empty()) {
		int aguaIzq = recorreNavegable(arb.left(), nCaminos);
		int aguaDer = recorreNavegable(arb.right(), nCaminos);

		//MANANTIAL
		//Si los dos nodos son nulos
		if (aguaIzq == -1 && aguaDer == -1) {
			return 1;
		}
		//PRESAS O AFLUENTES
		//Si alguno de los dos es negativo, tiene que ser una presa
		//Si ninguno es negativo, tambien podria ser una presa, al igual que una conjuncion
		//en las conjunciones que no hay barrera se calcula igual
		else {
			int nAgua = 0;
			//Separamos el calculo por si llegan 1 o 2 afluentes no restar el otro, que vale -1 si no existe

			if (aguaIzq == -1)
				nAgua = aguaDer - arb.root();
			else if (aguaDer == -1)
				nAgua = aguaIzq - arb.root();
			else
				nAgua = aguaIzq + aguaDer - arb.root();

			//Calculo si el tramo es navegable
			if (nAgua >= 3)
				nCaminos++;
			return nAgua;
		}

	}
	//Si el nodo es vacio devuelvo -1, asi cuento el numero de nodos que confluyen
	else return -1;
}

int calculaNavegable(const bintree<int>& arb) {
	int nCaminosNavegables = 0;
	int ultimoCamnAgua = recorreNavegable(arb, nCaminosNavegables);
	//Quitamos el camino que se calcula despues de la raiz, que era despues del final
	if (ultimoCamnAgua >= 3)
		return nCaminosNavegables - 1;
	return nCaminosNavegables;

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
	bintree<int> arb;
	arb = leerArbol(-1); // -1 es la repr. de arbol vacio
	int tramosNavegables = calculaNavegable(arb);
	std::cout << tramosNavegables << "\n";
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

