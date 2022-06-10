// Javier Muñoz Martín de la Sierra
// VJ39


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <math.h>

//Asignara a cada nino 2 juguetes
//unidades por juguete ilimitadas
// no entregar´an a un ni˜no dos juguetes del mismo tipo, 
//

//Tipo tiene marcage

bool esValida(std::vector<int>& sol, const std::vector<std::string>& tipos, const int& pos, const int& satisfaccionMinima, std::vector<int>& unidadesJuguetes, const std::vector< std::vector<int>>& satisfaccionNinos, int i) {

	if (unidadesJuguetes[i] <= 0) return false;

	//Si es impar
	if (pos % 2 != 0) {
		if (sol[pos] < sol[pos - 1]) return false;
		if (tipos[sol[pos]] == tipos[sol[pos - 1]]) return false;
		if (satisfaccionNinos[pos / 2][sol[pos]] + satisfaccionNinos[pos / 2][sol[pos - 1]] < satisfaccionMinima) return false;
	}

	unidadesJuguetes[i]--;
	return true;
}

// función que resuelve el problema
void resolver(std::vector<int>& sol, const std::vector<std::string>& tipos, const int& pos, bool& solucion, const int& satisfaccionMinima, std::vector<int>& unidadesJuguetes, const std::vector< std::vector<int>>& satisfaccionNinos) {

	for (int i = 0; i < unidadesJuguetes.size(); ++i) {
		sol[pos] = i;
		if (esValida(sol, tipos, pos, satisfaccionMinima, unidadesJuguetes, satisfaccionNinos, i)) {
			//Si es solucion
			if (pos == sol.size() - 1) {
				for (int i = 0; i < sol.size(); ++i) {
					std::cout << sol[i] << " ";
				}
				std::cout << "\n";
				solucion = true;
			}
			else {
				resolver(sol, tipos, pos + 1, solucion, satisfaccionMinima, unidadesJuguetes, satisfaccionNinos);
			}
			unidadesJuguetes[i]++;
		}
	}
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	int nJuguetes, nNinos, satisfaccionMinima;
	std::cin >> nJuguetes >> nNinos >> satisfaccionMinima;
	if (!std::cin)
		return false;

	std::vector<int> unidadesJuguetes(nJuguetes);
	for (int i = 0; i < nJuguetes; ++i) {
		std::cin >> unidadesJuguetes[i];
	}

	std::vector<std::string> tipos(nJuguetes);
	for (int i = 0; i < nJuguetes; ++i) {
		std::cin >> tipos[i];
	}

	std::vector< std::vector<int>> satisfaccionNinos(nNinos);
	for (int j = 0; j < nNinos; ++j) {
		satisfaccionNinos[j] = std::vector<int>(nJuguetes);
		for (int i = 0; i < nJuguetes; ++i) {
			std::cin >> satisfaccionNinos[j][i];
		}
	}


	std::vector<int> sol(nNinos * 2);
	bool solucion = false;
	resolver(sol, tipos, 0, solucion, satisfaccionMinima, unidadesJuguetes, satisfaccionNinos);

	// escribir sol
	if (!solucion)
		std::cout << "SIN SOLUCION\n";
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