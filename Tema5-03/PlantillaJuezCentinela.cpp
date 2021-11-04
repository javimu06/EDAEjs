// Javier Muñoz Martin de la Sierra
// VJ39


#include <iostream>
#include <iomanip>
#include <fstream>
#include <queue>
#include <stack>


// función que resuelve el problema
void resolver(std::queue<int>& cola) {
	std::stack<int> negativos;
	std::queue<int> positivos;
	int dimension = cola.size();
	for (int i = 0; i < dimension; ++i) {
		if (cola.front() < 0) {
			negativos.push(cola.front());
		}
		else if (cola.front() >= 0) {
			positivos.push(cola.front());
		}
		cola.pop();
	}
	std::queue<int> sol;
	while (!negativos.empty()) {
		sol.push(negativos.top());
		std::cout << negativos.top() << " ";
		negativos.pop();
	}
	while (!positivos.empty()) {
		sol.push(positivos.front());
		std::cout << positivos.front() << " ";
		positivos.pop();
	}
	std::cout << "\n";
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	unsigned int nElems;
	std::cin >> nElems;
	if (nElems == 0)
		return false;

	std::queue<int> cola;
	for (unsigned int i = 0; i < nElems; ++i) {
		int aux;
		std::cin >> aux;
		cola.push(aux);
	}

	// escribir sol
	if (!cola.empty())
		resolver(cola);

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
