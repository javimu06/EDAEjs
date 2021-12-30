// Javier Muñoz Martin de la Sierra
// VJ39


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>


// función que resuelve el problema
bool resolver(const std::vector<int>& datos, const int& pos) {
	if (pos == datos.size() - 1)
		return true;

	int highest = datos[0];	//Guarda el valor más alto de 0->p dentro de datos
	for (int i = 0; i <= pos; i++) {
		if (highest < datos[i])
			highest = datos[i];
	}

	int lowest = datos[pos + 1];	//Guarda el valor más bajo de p->n-1 dentro de datos
	for (long unsigned int j = pos + 1; j < datos.size(); j++) {
		if (lowest > datos[j])
			lowest = datos[j];
	}
	return (highest < lowest);	//Devolvemos true si el numero más alto de la primera busqueda es menor que el menor de la segunda
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
	// leer los datos de la entrada
	int elemn, pos;
	std::cin >> elemn >> pos;
	std::vector<int> values(elemn, 0);
	//Llenamos el vector de valores
	for (int i = 0; i < elemn; i++) {
		std::cin >> values[i];
	}

	bool sol = resolver(values, pos);
	// escribir sol
	if (sol) std::cout << "SI\n";
	else std::cout << "NO\n";

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