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
bool creciente(const std::vector<unsigned int>& hermanos) {
	int anterior = hermanos[0];

	//True -> Decreciente
	//False -> Creciente
	bool sentido = anterior > hermanos[1];

	for (int i = 1; i < hermanos.size(); i++) {
		if (sentido) {
			if (anterior > hermanos[i])
				anterior = hermanos[i];
			else
				return false;
		}
		else {
			if (anterior < hermanos[i])
				anterior = hermanos[i];
			else
				return false;
		}
	}
	return true;
}

// función que resuelve el problema
bool resolver(const int& datos) {
	std::vector<unsigned int> hermanos(datos, 0);
	for (int i = 0; i < datos; i++) {
		std::cin >> hermanos[i];
	}

	return (creciente(hermanos));
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
	//std::ifstream in("datos.txt");
	//auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 


	while (resuelveCaso());


	// Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	//std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}
