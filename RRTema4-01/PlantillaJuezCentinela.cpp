// Javier Muñoz Martin de la Sierra
// VJ39


#include <ostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include "Date.h"

// función que resuelve el problema
void resolver(const std::vector<Date>& horas, const std::vector<Date>& consulta) {
	bool searching = true;
	for (int j = 0; j < consulta.size(); ++j) {
		for (int i = 0; i < horas.size() && searching; ++i) {
			if (!consulta[j].esValida()) {
				searching = false;
				std::cout << "ERROR\n";
			}
			else if (consulta[j] < horas[i]) {
				std::cout << horas[i];
				searching = false;
			}
		}
		if (searching)
			std::cout << "NO\n";
		searching = true;
	}

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	int nTrenes, nHoras;
	std::cin >> nTrenes >> nHoras;
	if (nTrenes == 0)
		return false;

	std::vector<Date> horas(nTrenes);
	for (int i = 0; i < nTrenes; ++i)
		std::cin >> horas[i];

	std::vector<Date> consulta(nHoras);
	for (int i = 0; i < nHoras; ++i)
		std::cin >> consulta[i];

	resolver(horas, consulta);

	// escribir sol
	std::cout << "---\n";

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
