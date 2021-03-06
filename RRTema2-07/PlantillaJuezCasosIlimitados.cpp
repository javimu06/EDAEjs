// Javier Muñoz Martín de la Sierra
// VJ39


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>



// función que resuelve el problema
int resolver(const std::vector<int>& datos, int initPos, int endPos) {
	if (initPos == endPos - 1) return datos[initPos];

	if (datos[initPos] < datos[(initPos + endPos) / 2]) return resolver(datos, initPos, (initPos + endPos) / 2);
	else return resolver(datos, (initPos + endPos) / 2, endPos);
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	int nElementos;
	std::cin >> nElementos;
	if (!std::cin)
		return false;

	std::vector<int> elementos(nElementos);

	for (int i = 0; i < nElementos; ++i) {
		std::cin >> elementos[i];
	}

	int sol = resolver(elementos, 0, elementos.size());

	// escribir sol
	std::cout << sol << "\n";

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