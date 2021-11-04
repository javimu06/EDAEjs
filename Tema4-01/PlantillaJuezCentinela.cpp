// Javier Muñoz Martin de la Sierra
// VJ39


#include <iostream>
#include <fstream>
#include <vector>

#include "Date.h"

// función que resuelve el problema
void resolver(const std::vector<Date>& Horario, const std::vector<Date>& consulta, Date& sol, bool findSol) {
	for (long unsigned int j = 0; j < consulta.size(); j++) {
		if (consulta[j].esValida()) {
			bool searching = true;
			long unsigned int i = 0;
			while (i < Horario.size() && searching) {
				if (consulta[j] < Horario[i]) {
					searching = false;
					std::cout << Horario[i];
				}
				i++;
			}
			if (searching)
				std::cout << "NO\n";
		}
		else
			std::cout << "ERROR\n";
	}
	std::cout << "---\n";
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	int nTrenes, nHoras;
	std::cin >> nTrenes >> nHoras;
	if (nTrenes == 0 && nHoras == 0)
		return false;
	std::vector<Date> Horario(nTrenes);
	for (int i = 0; i < nTrenes; i++) {
		std::cin >> Horario[i];
		//Manera EZ
		/*char c = ':';
		std::cin >> Horario[i].Hora >> c >> Horario[i].min >> c >> Horario[i].seg;*/
	}

	std::vector<Date> consulta(nHoras);
	for (int j = 0; j < nHoras; j++)
		std::cin >> consulta[j];

	Date sol;

	bool findSol = false;
	resolver(Horario, consulta, sol, findSol);

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
