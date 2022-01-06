// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>


// 7 5 3 1
// 1 3 5 7
// Método auxiliar
// Comprueba si el vector es creciente o decreciente al calcular el sentido.
// Dependiendo del sentido conprueba recursivamente si "anterior" es mayor o menor respecto al siguiente
bool creciente(const std::vector<unsigned int>& hermanos, int posicion, bool direccion) {
	if (posicion == hermanos.size()) return true;

	//Si el primero es menor que el segundo
	if (direccion) {
		//Si encontramos que el siguiente es menor que el actual algo falla
		if (hermanos[posicion - 1] >= hermanos[posicion])
			return false;
		else return creciente(hermanos, posicion + 1, direccion);
	}
	else {
		if (hermanos[posicion - 1] <= hermanos[posicion])
			return false;
		else return creciente(hermanos, posicion + 1, direccion);
	}
}

// función que resuelve el problema
bool resolver(const int& datos) {
	std::vector<unsigned int> hermanos(datos);
	for (int i = 0; i < datos; i++) {
		std::cin >> hermanos[i];
	}
	if (!hermanos.empty())
		return (creciente(hermanos, 1, hermanos[0] < hermanos[1]));
	else
		return true;
}




// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	unsigned int numHermanos;
	std::cin >> numHermanos;

	if (numHermanos == 0)
		return false;

	bool sol = resolver(numHermanos);

	if (sol)
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
