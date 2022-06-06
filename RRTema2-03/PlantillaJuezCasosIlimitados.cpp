// Javier Muñoz Martín de la Sierra
// VJ39


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <climits>



// función que resuelve el problema
bool resolver(const std::vector<int>& digitos, int initPos, int endPos) {
	if (initPos == endPos) return true;
	if (initPos == endPos - 1) return digitos[initPos] <= digitos[endPos];

	int minimoIzq = digitos[initPos], maximoIzq = digitos[initPos], minimoDer = digitos[endPos], maximoDer = digitos[endPos];
	//Recorro la primera mitad y actualizo valores
	for (int i = initPos; i < (initPos + endPos) / 2; ++i) {
		if (minimoIzq > digitos[i]) minimoIzq = digitos[i];
		if (maximoIzq < digitos[i]) maximoIzq = digitos[i];
	}

	for (int i = (initPos + endPos) / 2; i < endPos; ++i) {
		if (minimoDer > digitos[i]) minimoDer = digitos[i];
		if (maximoDer < digitos[i]) maximoDer = digitos[i];
	}
	//Comparo valores para la recursion
	if (minimoIzq > minimoDer || maximoIzq > maximoDer) return false;
	else return (resolver(digitos, initPos, (initPos + endPos) / 2) && resolver(digitos, (initPos + endPos) / 2 + 1, endPos));

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	std::vector<int> digitos;
	int x;
	std::cin >> x;
	if (x == 0) return false;

	while (x != 0) {
		digitos.push_back(x);
		std::cin >> x;
	}
	if (resolver(digitos, 0, digitos.size() - 1))
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