// Javier Muñoz Martin de la Sierra
// VJ39


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <climits>


// función que resuelve el problema
bool resolver(int npos, const std::vector<int>& miArray) {
	if (npos < 0)return false;
	if (npos == miArray.size() - 1) return true;

	int maximoMinimos = -INT_MAX;
	for (int i = 0; i < npos + 1; ++i) {
		if (maximoMinimos < miArray[i])
			maximoMinimos = miArray[i];
	}

	for (int i = npos + 1; i < miArray.size(); ++i) {
		if (miArray[i] <= maximoMinimos) return false;
	}

	return true;

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
	// leer los datos de la entrada
	int nValores, nposicion;
	std::cin >> nValores;
	std::cin >> nposicion;

	std::vector<int> miArray;
	for (int i = 0; i < nValores; ++i) {
		int aux;
		std::cin >> aux;
		miArray.push_back(aux);
	}


	if (resolver(nposicion, miArray))
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