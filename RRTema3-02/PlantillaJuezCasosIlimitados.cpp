// Javier Muñoz Martín de la Sierra
// VJ39


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

bool esValida(std::vector<bool> usadas, int i) {
	return !usadas[i];
}

// función que resuelve el problema
void resolver(const int& mElementos, const int& nGrupos, std::vector<char>& sol, std::vector<bool>& usadas, const int& pos) {

	for (int i = 0; i < mElementos; ++i) {
		sol[pos] = char(i) + 'a';
		if (esValida(usadas, i)) {
			if (pos == sol.size() - 1) {
				for (int i = 0; i < nGrupos; ++i)
					std::cout << sol[i];
				std::cout << "\n";
			}
			else {
				usadas[i] = true;
				resolver(mElementos, nGrupos, sol, usadas, pos + 1);
				usadas[i] = false;
			}
		}	
	}
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	int mElementos, nGrupos;
	std::cin >> mElementos >> nGrupos;
	if (!std::cin)
		return false;
	std::vector<char> sol(nGrupos);
	std::vector<bool> usadas(mElementos, false);
	resolver(mElementos, nGrupos, sol, usadas, 0);

	// escribir sol
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


	while (resuelveCaso())
		;


	// Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}