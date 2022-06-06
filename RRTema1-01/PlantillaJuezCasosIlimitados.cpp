// Javier Muñoz Martín de la Sierra
// VJ39


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>



// función que resuelve el problema
bool resolver(int nHermanos, const std::vector<int>& alturas) {
	bool direccion = false;				//orden creciente ->false;	orden decreciente ->true
	if (nHermanos < 2) return false;
	else if (alturas[0] > alturas[1]) direccion = true;


	//Si estamos en orden creciente y encontramos que uno anterior es mayor al siguiente, NO ES DALTON
	for (int i = 1; i < nHermanos; ++i) {
		if (!direccion) {
			if (alturas[i - 1] >= alturas[i]) return false;
		}
		else {
			if (alturas[i - 1] <= alturas[i]) return false;

		}
	}

	return true;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	int nHermanos;
	std::cin >> nHermanos;
	if (nHermanos == 0)
		return false;

	std::vector<int> alturas;
	for (int i = 0; i < nHermanos; ++i)
	{
		int altura;
		std::cin >> altura;
		alturas.push_back(altura);
	}

	if (resolver(nHermanos, alturas))
		std::cout << "DALTON\n";
	else
		std::cout << "DESCONOCIDOS\n";


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