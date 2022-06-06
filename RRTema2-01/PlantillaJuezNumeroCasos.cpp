// Javier Muñoz Martin de la Sierra
// VJ39


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <math.h> 

int numero0void(int& numero, const int& aux, const int& contador) {
	if (aux <= 0) return numero;

	numero += (9 - aux % 10) * pow(10, contador);
	return numero0void(numero, aux / 10, contador + 1);
}

int numero1void(int& numero, const int& aux, const int& contador) {
	if (aux <= 0) return numero;

	numero = (9 - aux % 10) + numero*10;
	return numero1void(numero, aux / 10, contador + 1);
}

// función que resuelve el problema
std::vector<int> resolver(int numero) {
	std::vector<int> sol;

	if (numero == 0) {
		sol.push_back(9);
		sol.push_back(9);
		return sol;
	}

	int numero0 = 0, numero1 = 0;
	int contador = 0;

	numero0 = numero0void(numero0, numero, contador);
	numero1= numero1void(numero1, numero, contador);

	sol.push_back(numero0);
	sol.push_back(numero1);

	return sol;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
	// leer los datos de la entrada
	int numero;
	std::cin >> numero;

	std::vector<int> sol = resolver(numero);
	// escribir sol
	for (int i = 0; i < sol.size(); ++i) {
		std::cout << sol[i] << " ";
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