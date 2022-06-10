// Javier Muñoz Martin de la Sierra
// VJ39


#include <iostream>
#include <iomanip>
#include <fstream>
#include <list>



// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	int nElementos;
	std::cin >> nElementos;
	if (nElementos == 0)
		return false;

	std::list<int> elementos;
	for (int i = 0; i < nElementos; ++i) {
		int x;
		std::cin >> x;
		if (x < 0)
			elementos.push_front(x);
		else
			elementos.push_back(x);
	}

	while (!elementos.empty()) {
		std::cout << elementos.front()<<" ";
		elementos.pop_front();
	}


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
