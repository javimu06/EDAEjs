// Javier Muñoz Martin de la Sierra
// VJ39


#include <iostream>
#include <iomanip>
#include <fstream>

#include <list>



// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
	int x;
	std::list<int> sol;

	// leer los datos de la entrada
	std::cin >> x;
	while (x != -1) {
		sol.push_back(x);
		std::cin >> x;
	}
	if (!sol.empty()) {
		int max = sol.front();
		for (auto it = sol.begin(); it != sol.end(); ++it) {
			//Si el valor maximo supera al valor del iterador lo borramos
			if (max > (*it)) {
				it = sol.erase(it);
				it--;
			}
			else {
				max = (*it);
				std::cout << max << " ";
			}
		}
	}
	std::cout << "\n";
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