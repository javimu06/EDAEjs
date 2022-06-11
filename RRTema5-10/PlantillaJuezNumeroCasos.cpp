// Javier Muñoz Martin de la Sierra
// VJ39


#include <iostream>
#include <iomanip>
#include <fstream>
#include <list>


// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
	// leer los datos de la entrada
	int x;
	std::list<int> lista;
	std::cin >> x;

	while (x != -1) {
		lista.push_back(x);
		std::cin >> x;
	}
	//Resolucion
	int listaSize = lista.size();
	auto it = lista.begin();
	int valorAnterior = -1;

	for (int i = 0; i < listaSize; ++i) {
		if (*it < valorAnterior) {
			it = lista.erase(it);
			--it;
		}
		else
			valorAnterior = *it;
		++it;
	}
	// escribir sol
	it = lista.begin();
	for (int i = 0; i < lista.size(); ++i) {
		std::cout << *it << " ";
		++it;
	}
	std::cout << "\n";
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