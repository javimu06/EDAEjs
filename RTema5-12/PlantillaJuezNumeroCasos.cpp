// Javier Muñoz Martin de la Sierra
// VJ39


#include <iostream>
#include <iomanip>
#include <fstream>

#include <list>

void print(std::list<int>& secuencia) {
	for (auto it = secuencia.begin(); it != secuencia.end(); ++it) {
		std::cout << (*it) << " ";
	}
	std::cout << "\n";
}

void eliminaApariciones(std::list<int>& secuencia, int elim) {
	for (auto it = secuencia.begin(); it != secuencia.end(); ++it) {
		if ((*it) == elim) {
			it = secuencia.erase(it);
			//it--;
		}
	}
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
	int x;
	int eliminado;
	std::list<int> secuencia;
	// leer los datos de la entrada
	std::cin >> x;
	while (x != -1) {
		secuencia.push_back(x);
		std::cin >> x;
	}
	std::cin >> eliminado;
	print(secuencia);
	eliminaApariciones(secuencia, eliminado);
	print(secuencia);
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