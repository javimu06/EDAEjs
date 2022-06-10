// Javier Muñoz Martin de la Sierra
// VJ39


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>

#include "Pelicula.h"
#include "Date.h"

// función que resuelve el problema
void resolver(std::vector<Pelicula>& peliculas) {

	std::sort(peliculas.begin(), peliculas.end());

	for (int i = 0; i < peliculas.size(); ++i) {
		std::cout << peliculas[i];
	}

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	int nPelis;
	std::cin >> nPelis;
	if (nPelis == 0)
		return false;

	std::vector<Pelicula> peliculas(nPelis);
	for (int i = 0; i < peliculas.size(); ++i) {
		std::cin >> peliculas[i];
	}

	resolver(peliculas);

	// escribir sol
	std::cout << "---\n";

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
