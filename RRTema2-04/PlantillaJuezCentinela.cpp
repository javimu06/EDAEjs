// Javier Muñoz Martin de la Sierra
// VJ39


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <math.h>


// función que resuelve el problema
bool resolver(const std::vector<int>& elementos, int initPos, int endPos) {
	if (initPos == endPos - 1)return true;
	int parIzq = 0, parDer = 0;

	for (int i = initPos; i < (initPos + endPos) / 2; ++i) {
		//Si el numero dividido entre 2 da 0
		if (elementos[i] % 2 == 0) parIzq++;
	}

	for (int i = (initPos + endPos) / 2; i < endPos; ++i) {
		//Si el numero dividido entre 2 da 0
		if (elementos[i] % 2 == 0) parDer++;
	}

	if (abs(parIzq - parDer) <= 2) return resolver(elementos, initPos, (initPos + endPos) / 2) && resolver(elementos, (initPos + endPos) / 2, endPos);
	else return false;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	int nElementos;
	std::cin >> nElementos;
	if (nElementos == 0)
		return false;

	int x;
	std::vector<int> elementos;
	for (int i = 0; i < nElementos; ++i) {
		std::cin >> x;
		elementos.push_back(x);
	}

	if (resolver(elementos, 0, elementos.size()))
		std::cout << "SI\n";
	else
		std::cout << "NO\n";

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


	while (resuelveCaso());


	// Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}
