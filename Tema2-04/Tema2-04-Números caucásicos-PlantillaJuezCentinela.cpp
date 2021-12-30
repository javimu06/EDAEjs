// Javier Muñoz Martín de la Sierra
// VJ39


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>


// función que resuelve el problema
bool resolver(const std::vector<int>& elementos, const int& init, const int& fin) {
	if (fin - init == 1)
		return true;
	int pares0 = 0;
	int pares1 = 0;

	for (int i = init; i < (init + fin) / 2; i++) {
		if (elementos[i] % 2 == 0)
			pares0++;
	}
	for (int i = (init + fin) / 2; i < fin; i++) {
		if (elementos[i] % 2 == 0) 
			pares1++;
	}
	if (abs(pares0 - pares1) > 2)
		return false;
	else
		return resolver(elementos, init, (init + fin) / 2) && resolver(elementos, (init + fin) / 2, fin);
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	int numElems;
	std::cin >> numElems;
	if (numElems == 0)
		return false;
	std::vector<int> elementos(numElems);
	for (int i = 0; i < numElems; i++) {
		std::cin >> elementos[i];
	}
	bool sol = resolver(elementos, 0, elementos.size());

	// escribir sol
	if (sol)std::cout << "SI\n";
	else std::cout << "NO\n";
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
