// Javier Muñoz Martin de la Sierra
// VJ39


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>


// función que resuelve el problema
std::vector<int> resolver(const std::vector<int>& temperaturas) {
	int valles = 0;
	int picos = 0;
	for (int i = 1; i < temperaturas.size() - 1; ++i) {
		if (temperaturas[i - 1] < temperaturas[i] && temperaturas[i] > temperaturas[i + 1])
			picos++;
		if (temperaturas[i - 1] > temperaturas[i] && temperaturas[i] < temperaturas[i + 1])
			valles++;
	}
	std::vector<int> sol;
	sol.push_back(picos);
	sol.push_back(valles);
	return sol;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
	// leer los datos de la entrada
	int nTemperaturas;
	std::cin >> nTemperaturas;
	std::vector<int>temperaturas;
	for (int i = 0; i < nTemperaturas; ++i) {
		int temperatura;
		std::cin >> temperatura;
		temperaturas.push_back(temperatura);

	}

	std::vector<int> sol = resolver(temperaturas);
	// escribir sol
	for (int i = 0; i < sol.size(); ++i) {
		std::cout << sol[i] << " ";
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