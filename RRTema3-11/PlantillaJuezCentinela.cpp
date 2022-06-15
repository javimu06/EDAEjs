// Javier Muñoz Martin de la Sierra
// VJ39


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

bool esValida(std::vector<int>& sol, const int& nConsumoMax, std::vector<int>& consumoColores, int pos, int& combinaciones, std::vector<int>& lucesPuestas, int k) {

	//Comprobamos que el consumo de luces no excede el maximo
	int consumoTotal = 0;
	for (int i = 0; i < lucesPuestas.size(); ++i) {
		consumoTotal += lucesPuestas[i];
		if (consumoTotal > nConsumoMax)
			return false;
	}


	//Minimo hay 3 luces
	if (pos >= 2) {
		//Comprobamos que no son del mismo color
		if (sol[pos] == sol[pos - 1] && sol[pos - 1] == sol[pos - 2])
			return false;
	}


	int nLucesA = lucesPuestas[sol[k]] / consumoColores[sol[k]];
	int nLucesTODO = 0;

	for (int j = 0; j < lucesPuestas.size(); ++j) {
		if (sol[k] != j)
			nLucesTODO += lucesPuestas[j] / consumoColores[j];
	}
	if (nLucesA > nLucesTODO + 1)
		return false;


	return true;
}
// función que resuelve el problema
void resolver(std::vector<int>& sol, const int& longitud, const int& nColores, const int& nConsumoMax, std::vector<int>& consumoColores, int pos, int& combinaciones, std::vector<int>& lucesPuestas) {
	for (int i = 0; i < nColores; ++i) {

		sol[pos] = i;

		lucesPuestas[i] += consumoColores[i];
		if (esValida(sol, nConsumoMax, consumoColores, pos, combinaciones, lucesPuestas, pos)) {
			if (pos == sol.size() - 1) {

				/*for (int i = 0; i < sol.size(); ++i)
					std::cout << sol[i] << " ";
				std::cout << "\n";*/

				combinaciones++;
				lucesPuestas[i] -= consumoColores[i];
			}
			else {

				resolver(sol, longitud, nColores, nConsumoMax, consumoColores, pos + 1, combinaciones, lucesPuestas);
				lucesPuestas[i] -= consumoColores[i];
			}
		}
		else {
			lucesPuestas[i] -= consumoColores[i];
		}
	}
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	int longitud, nColores, nConsumo;
	std::cin >> longitud >> nColores >> nConsumo;
	if (longitud == 0)
		return false;

	std::vector<int> consumoColores(nColores);
	for (int i = 0; i < nColores; ++i)
		std::cin >> consumoColores[i];

	std::vector<int>sol(longitud);
	std::vector<int> lucesPuestas(nColores, 0);
	int combinaciones = 0;
	resolver(sol, longitud, nColores, nConsumo, consumoColores, 0, combinaciones, lucesPuestas);
	std::cout << combinaciones << "\n";
	// escribir sol

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
