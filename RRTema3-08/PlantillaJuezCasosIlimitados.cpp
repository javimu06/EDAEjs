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

bool esValida(std::vector<int>& sol, const std::vector<std::string>& tipos, const int& pos) {
	//Si el tipo actual esta marcado, no es valido


	//Si es impar
	if (pos % 2 != 0) {
		if (sol[pos] < sol[pos - 1]) return false;
		return tipos[sol[pos]] != tipos[sol[pos - 1]];
	}

	return true;
}

// función que resuelve el problema
void resolver(std::vector<int>& sol, const std::vector<std::string>& tipos, const int& pos, bool& solucion) {

	for (int i = 0; i < tipos.size(); ++i) {
		sol[pos] = i;
		if (esValida(sol, tipos, pos)) {
			//Si es solucion
			if (pos == sol.size() - 1) {
				for (int i = 0; i < sol.size(); ++i) {
					std::cout << sol[i] << " ";
				}
				std::cout << "\n";
				solucion = true;
			}
			else {
				resolver(sol, tipos, pos + 1, solucion);
			}
		}
	}
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	int nJuguetes, nNinos;
	std::cin >> nJuguetes >> nNinos;
	if (!std::cin)
		return false;

	std::vector<std::string> tipos(nJuguetes);
	for (int i = 0; i < nJuguetes; ++i) {
		std::cin >> tipos[i];
	}

	std::vector<int> sol(nNinos * 2);
	bool solucion = false;
	resolver(sol, tipos, 0, solucion);

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