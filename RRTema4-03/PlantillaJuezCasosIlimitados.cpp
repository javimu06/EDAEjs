// Javier Muñoz Martín de la Sierra
// VJ39


#include <iostream>
#include <iomanip>
#include <fstream>
#include "Set1.h"
#include <math.h>



// función que resuelve el problema
void resolver(int numero, Set1<int>& set, bool& feliz) {
	int aux = numero;
	int newNumero = 0;
	while (aux > 0) {
		newNumero += pow(aux % 10, 2);
		aux = aux / 10;
	}

	if (!set.contains(newNumero)) {
		set.add(newNumero);
		if (newNumero == 1) return;
		resolver(newNumero, set, feliz);
	}
	else {
		if (newNumero != 1) {
			set.add(newNumero);
			feliz = false;
		}
	}
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	int numero;
	std::cin >> numero;
	if (!std::cin)
		return false;

	Set1<int> set;
	bool feliz = true;
	set.add(numero);
	resolver(numero, set, feliz);

	// escribir sol
	for (int i = 0; i < set.size(); ++i) {
		std::cout << set.toArray()[i] << " ";
	}

	if (feliz)
		std::cout << "1";
	else
		std::cout << "0";

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


	while (resuelveCaso());


	// Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}