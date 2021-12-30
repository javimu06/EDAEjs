// Javier Muñoz Martin de la Sierra
// VJ39


#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstdint>

// función que resuelve el problema
int64_t complementario(int64_t& datos) {
	int64_t aux = datos;
	int64_t comp = 0;
	int64_t unidad = 1;
	if (aux == 0)
		return 9;
	while (aux > 0) {
		comp += (9 - (aux % 10)) * unidad;	//Se resta 9 menos el resto de auxiliar/10 para que así salga el complementario
		unidad = unidad * 10;
		aux = aux / 10;
	}

	return comp;
}

int64_t inversoComplementario(int64_t& datos) {
	int64_t aux = datos;
	int64_t comp = 0;
	int64_t unidad = 10;

	if (aux == 0)
		return 9;

	while (aux > 0) {
		comp = (9 - (aux % 10)) + comp * unidad;	//Se resta 9 menos el resto de auxiliar/10 para que así salga el complementario
		aux = aux / 10;
	}

	return comp;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
	// leer los datos de la entrada
	int64_t numero = 0;
	std::cin >> numero;

	// escribir sol
	int64_t comp = complementario(numero);
	int64_t Invcomp = inversoComplementario(numero);
	std::cout << comp << " " << Invcomp << "\n";

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