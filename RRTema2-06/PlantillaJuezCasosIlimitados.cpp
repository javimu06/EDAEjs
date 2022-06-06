// Javier Muñoz Martín de la Sierra
// VJ39


#include <iostream>
#include <iomanip>
#include <fstream>

#include <vector>


// función que resuelve el problema
int resolver(const std::vector<int>& datos, const int& initPos, const int& endPos) {
	if (initPos == endPos - 1) return datos[initPos];
	else if (initPos == endPos - 2) {
		if (datos[initPos] < datos[endPos - 1]) return datos[initPos];
		else return datos[endPos - 1];
	}

	int medio = (initPos + endPos) / 2;
	if (datos[medio - 1] < datos[medio] && datos[medio] < datos[medio + 1])
		return resolver(datos, initPos, (initPos + endPos) / 2);
	else if (datos[medio - 1] > datos[medio] && datos[medio] > datos[medio + 1])
		return resolver(datos, (initPos + endPos) / 2, endPos);
	else return datos[medio];

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	int nElems;
	std::cin >> nElems;
	if (!std::cin)
		return false;

	std::vector<int> elementos;
	int x;
	for (int i = 0; i < nElems; ++i) {
		std::cin >> x;
		elementos.push_back(x);
	}

	int minimo = resolver(elementos, 0, elementos.size());

	// escribir sol
	std::cout << minimo << "\n";

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