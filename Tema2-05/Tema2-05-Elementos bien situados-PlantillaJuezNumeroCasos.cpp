// Javier Muñoz Martin de la Sierra
// VJ39


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>


// función que resuelve el problema
bool resolver(const std::vector<int>& datos, const int& init, const int& fin) {
	if (fin - init == 1) return datos[init] == init;
	else return resolver(datos, init, (init + fin) / 2) || resolver(datos, (init + fin) / 2, fin);
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
	// leer los datos de la entrada
	int numElems;
	std::cin >> numElems;
	std::vector<int> elementos(numElems);
	for (int i = 0; i < numElems; i++) {
		std::cin >> elementos[i];
	}
	bool sol = false;
	if (numElems != 0)
		sol = resolver(elementos, 0, elementos.size());
	// escribir sol
	if (sol)std::cout << "SI\n";
	else std::cout << "NO\n";
}

int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
#ifndef DOMJUDGE
	std::ifstream in("datos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 

	int numArrays;
	std::cin >> numArrays;
	for (int i = 0; i < numArrays; ++i)
		resuelveCaso();

	// Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}