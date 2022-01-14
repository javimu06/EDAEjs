// Javier Muñoz Martin de la Sierra
// VJ39


#include <iostream>
#include <iomanip>
#include <fstream>

#include <deque>



// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	int numCasos;
	std::cin >> numCasos;
	if (!numCasos) return false;
	std::deque<int> sol;
	int x = 0;
	for (int i = 0; i < numCasos; ++i) {
		std::cin >> x;
		if (x < 0)
			sol.push_front(x);
		else
			sol.push_back(x);
	}
	// escribir sol
	for (int j = 0; j < numCasos; ++j) {
		std::cout << sol.front() << " ";
		sol.pop_front();
	}
	std::cout << "\n";
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