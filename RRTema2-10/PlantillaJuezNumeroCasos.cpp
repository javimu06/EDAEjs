// Javier Muñoz Martin de la Sierra
// VJ39


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>


// función que resuelve el problema
int resolver(const std::vector<int>& elementos0, const std::vector<int>& elementos1, int initPos, int endPos) {

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
	// leer los datos de la entrada
	int nElementos;
	std::cin >> nElementos;
	std::vector<int> elementos0(nElementos);
	std::vector<int> elementos1(nElementos - 1);

	for (int i = 0; i < nElementos; ++i) {
		std::cin >> elementos0[i];
	}

	for (int i = 0; i < nElementos - 1; ++i) {
		std::cin >> elementos1[i];
	}

	int sol; if (elementos1.size() > 0)
		sol = resolver(elementos0, elementos1, 0, nElementos);
	else sol = elementos0[0];
	// escribir sol
	std::cout << sol << "\n";

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