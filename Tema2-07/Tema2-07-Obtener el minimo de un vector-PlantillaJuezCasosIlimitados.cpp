// Javier Muñoz Martín de la Sierra
// VJ39


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>



// función que resuelve el problema
int resolver(const std::vector<int>& datos, const int& init, const int& fin) {
	//Caso base
	if (datos[init] == datos[fin])
		return datos[init];
	//Casp directo
	if (datos[init] > datos[fin])
		return datos[fin];
	

	int med = datos[(init + fin) / 2];
	/*
	Si med<ini<fin buscamos en la parte derecha, si ini<fin<med en la izquierda
	*/
	if (med < datos[init])
		return resolver(datos, ((fin + init) / 2), fin);
	else
		return resolver(datos, init, (fin + init) / 2);
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	int nElems;
	std::cin >> nElems;
	if (!std::cin)
		return false;
	std::vector<int> nArray(nElems);
	for (int i = 0; i < nElems; i++) {
		std::cin >> nArray[i];
	}

	int sol = resolver(nArray,0 ,nElems-1);
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