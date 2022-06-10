// Javier Muñoz Martin de la Sierra
// VJ39


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>


// función que resuelve el problema
void resolver(const int& nAltura, std::vector<int>& sol, const int& pos) {
	int nPiezas = 3;
	for (int i = 0; i < nPiezas; ++i) {
		sol[pos] = i;
		if (pos == sol.size() - 1) {
			for (int i = 0; i < sol.size(); ++i) {
				std::string auxSol;
				switch (sol[i])
				{
				case 0:
					auxSol = "azul";
					break;
				case 1:
					auxSol = "rojo";
					break;
				case 2:
					auxSol = "verde";
					break;
				}
				std::cout << auxSol << " ";
			}
			std::cout << "\n";
		}
		else {
			resolver(nAltura, sol, pos + 1);
		}
	}

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	int nAltura;
	std::cin >> nAltura;
	if (nAltura == 0)
		return false;

	std::vector<int> sol(nAltura);
	resolver(nAltura, sol, 0);

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
