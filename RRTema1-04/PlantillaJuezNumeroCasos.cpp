// Javier Muñoz Martin de la Sierra
// VJ39


#include <iostream>
#include <iomanip>
#include <fstream>

#include <string>
#include <vector>

// función que resuelve el problema
bool resolver(std::vector<std::string> palabras) {
	std::vector<bool> usadas(palabras[1].size() + 1, false);

	for (int i = 0; i < palabras[0].size(); ++i) {
		bool finded = false;
		for (int j = 0; j < palabras[1].size() && !finded; ++j) {
			if (palabras[0][i] == palabras[1][j] && !usadas[j]) {
				usadas[j] = true;
				finded = true;
				break;
			}
		}
		if (!finded)
			return false;
	}
	return true;

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
	// leer los datos de la entrada

	std::vector<std::string> palabras;
	std::string aux;

	std::cin >> aux;
	palabras.push_back(aux);
	std::cin >> aux;
	palabras.push_back(aux);

	if (resolver(palabras))
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