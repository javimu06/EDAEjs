// Javier Muñoz Martín de la Sierra
// VJ39


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <math.h>


bool suficienteDisperso(int nDisperso, const std::vector<int>& datos, int initPos, int endPos) {
	if (initPos == endPos) return true;

	if (abs(datos[initPos] - datos[endPos]) < nDisperso) return false;
	else return suficienteDisperso(nDisperso, datos, initPos, (initPos + endPos) / 2) && suficienteDisperso(nDisperso, datos, (initPos + endPos) / 2 + 1, endPos);
}


//// función que resuelve el problema
//bool resolver(int nNumeros, int nDisperso, const std::vector<int>& datos) {
//
//
//}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	int nNumeros, nDisperso;
	std::cin >> nNumeros;

	if (!std::cin)
		return false;

	std::cin >> nDisperso;

	std::vector<int> digitos;
	for (int i = 0; i < nNumeros; ++i) {
		int aux;
		std::cin >> aux;
		digitos.push_back(aux);
	}

	if (suficienteDisperso(nDisperso, digitos, 0, nNumeros - 1))
		std::cout << "SI\n";
	else
		std::cout << "NO\n";

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