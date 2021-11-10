// Javier Muñoz Martin de la Sierra
// VJ39


#include <iostream>
#include <iomanip>
#include <fstream>
#include <list>


// función que resuelve el problema
void resolver(std::list<unsigned long int>& listaDesordenada) {
	unsigned long int max = *listaDesordenada.begin();
	std::cout << max;
	for (auto it = ++listaDesordenada.begin(); it != listaDesordenada.end(); ++it) {
		//Si el valor del nodo de la lista es mayor, se cambia el nMaximo
		//Si el valor del nodo es menor que el anterior, se saca de la lista porque no esta ordenado
		if (max < (*it)) {
			max = (*it);
			std::cout << " " << (*it);
		}
		else {
			it = listaDesordenada.erase(it);
			--it;
		}
	}
	std::cout << "\n";
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
	// leer los datos de la entrada
	std::list<unsigned long int> listaDesordenada;
	int num;
	std::cin >> num;
	while (num != -1) {
		listaDesordenada.push_back(num);
		std::cin >> num;
	}
	// escribir sol
	if (listaDesordenada.size() > 0)
		resolver(listaDesordenada);
	else
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