// Javier Muñoz Martín de la Sierra
// VJ39


#include <iostream>
#include <iomanip>
#include <fstream>

#include <vector>


// función que resuelve el problema
void resolver(int m, int n, std::vector<char>& sol, std::vector<bool>& usadas, int pos) {
	for (char c = 'a'; c < 'a' + m; ++c) {
		if (!usadas[c - 'a']) {
			sol[pos] = c;
			if (pos == n - 1) {
				for (int j = 0; j < n; j++)
					std::cout << sol[j];
				std::cout << "\n";
			}
			else {
				usadas[c - 'a'] = true;
				resolver(m, n, sol, usadas, pos+1);
				usadas[c - 'a'] = false;
			}
		}
	}
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	int m, n;
	std::cin >> m >> n;
	if (!std::cin)
		return false;

	std::vector<char> solucion(n);
	std::vector<bool> usadas(m, false);
	int pos = 0;
	// escribir sol
	resolver(m, n, solucion, usadas, pos);
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