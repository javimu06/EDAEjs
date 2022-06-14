// Javier Muñoz Martín de la Sierra
// VJ39


#include <iostream>
#include <iomanip>
#include <fstream>
#include "bintree_eda.h"


// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	char tipoArbol;
	std::cin >> tipoArbol;
	if (!std::cin)
		return false;

	if (tipoArbol == 'N') {
		bintree<int> raiz;
		int minimo = -1;
		raiz = leerArbol(minimo);
		minimo = raiz.devuelveMinimo();
		std::cout << minimo << "\n";
	}
	else if (tipoArbol == 'P') {
		bintree<std::string> raiz;
		std::string minimo = "#";
		raiz = leerArbol(minimo);
		minimo = raiz.devuelveMinimo();
		std::cout << minimo << "\n";
	}


	// escribir sol


	return true;

}

int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
#ifndef DOMJUDGE
	std::ifstream in("datos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 


	while (resuelveCaso())
		;


	// Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}