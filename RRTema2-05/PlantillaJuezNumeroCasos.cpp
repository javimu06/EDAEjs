// Javier Muñoz Martin de la Sierra
// VJ39


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>


// función que resuelve el problema
bool resolver(const std::vector<int>& elementos, const int& initPos, const int& endPos) {
	if (initPos == endPos - 1) return elementos[initPos] == initPos;
	else return(resolver(elementos, initPos, (initPos + endPos) / 2) || resolver(elementos, (initPos + endPos) / 2, endPos));
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
	// leer los datos de la entrada
	int nElementos;

	std::cin >> nElementos;
	std::vector<int> elementos(nElementos);
	for (int i = 0; i < nElementos; i++) {
		std::cin >> elementos[i];
	}

	if (nElementos != 0 && resolver(elementos, 0, elementos.size()))
		std::cout << "SI\n";
	else
		std::cout << "NO\n";
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