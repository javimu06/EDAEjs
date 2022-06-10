// Javier Muñoz Martín de la Sierra
// VJ39


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>



// función que resuelve el problema
void resolver(int mElementos, int nGrupos, std::vector<char>& sol, int pos) {
	for (int i = 0; i < mElementos; ++i) {
		sol[pos] = char(i) + 'a';
		if (pos == sol.size() - 1) {
			for (int i = 0; i < sol.size(); ++i)
				std::cout << sol[i];
			std::cout << "\n";
		}
		else resolver(mElementos, nGrupos, sol, pos + 1);
	}

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	int mElementos;
	int nGrupos;
	std::cin >> mElementos;
	if (!std::cin)
		return false;

	std::cin >> nGrupos;
	std::vector<char> sol(nGrupos);
	resolver(mElementos, nGrupos, sol, 0);

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