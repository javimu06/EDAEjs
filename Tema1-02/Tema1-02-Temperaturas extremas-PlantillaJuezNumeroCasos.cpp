// Javier Muñoz Martin de la Sierra
// VJ39


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>


// función que resuelve el problema
std::vector<int> resolver(const std::vector<int>& datos) {
	int direccion = 0;
	std::vector<int> sol(2, 0);
	for (int i = 0; i < datos.size() - 1; i++) {
		int AntDireccion = direccion;	//Guardamos la anterior direccion

		//Comprobamos la siguiente subida
		if (datos[i] < datos[i + 1])
			direccion = 1;
		else if (datos[i] > datos[i + 1])
			direccion = -1;
		else direccion = 0;

		//La comprobamos con la anterior y actualizamos el vector solucion
		if (AntDireccion == -1 && direccion == 1)	//Valle
			sol[0]++;
		else if (AntDireccion == 1 && direccion == -1)	//Pico
			sol[1]++;
	}
	return sol;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
	// leer los datos de la entrada
	unsigned int nTemps; //Guarda el numero de temperaturas
	std::cin >> nTemps;

	//Guardamos las temperaturas
	std::vector<int> temps(nTemps, 0);
	for (int i = 0; i < nTemps; i++) {
		std::cin >> temps[i];
	}

	std::vector<int> sol = resolver(temps);
	// escribir sol, sol[1] son picos y sol[0] son valles
	std::cout << sol[1] << " " << sol[0] << "\n";

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