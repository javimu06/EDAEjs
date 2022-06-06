// Javier Muñoz Martin de la Sierra
// VJ39


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>


// función que resuelve el problema
int resolver(const std::vector<int>& elementos, int initPos, int endPos) {
	if (initPos == endPos - 1) return initPos;

	int medio = (initPos + endPos) / 2;
	if (medio % 2 != 0) {
		//Grupos de vectores de tamano 3, 7, 11...
		if (elementos[medio] == elementos[medio - 1])return resolver(elementos, medio, endPos);
		else return resolver(elementos, initPos, medio);
	}
	else {
		//Grupos de vectores de tamano 5, 9, 13...
		if (elementos[medio] == elementos[medio - 1])return resolver(elementos, initPos, medio);
		else return resolver(elementos, medio, endPos);
	}


}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
	// leer los datos de la entrada
	int nElementos;
	std::cin >> nElementos;
	std::vector<int> elementos(nElementos);
	for (int i = 0; i < elementos.size(); ++i)
		std::cin >> elementos[i];

	int sol = resolver(elementos, 0, elementos.size());
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