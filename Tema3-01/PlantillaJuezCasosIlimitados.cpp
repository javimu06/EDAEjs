// Javier Muñoz Martín de la Sierra
// VJ39


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>




// función que resuelve el problema
// Como parametros paso las letras, el tamaño de la palabra, el vector para ir contando que letras he usado y la solucion que se va completando
/*
La posicion es super importante, puede que ya tengamos el vector con tamaño completo, pero si la posicion no es la ultima no queremos imprimir la solucion
Tambien hay que tener en cuenta el remplazamiento de letras en el array, la posicion tiene esta funcion tambien, comienza siendo 0 cuando marcamos la primera a
y pasa a ser 1 cuando marcamos la segunda a, b y c, luego salimos del caso recurrente donde seguia valiendo 1 y repetimos el proceso por recursion


*/
void resolver(int mLetras, int nTamano, std::vector<bool>& usadas, std::vector<char>& solucion, int posicion) {
	for (char c = 'a'; c < 'a' + mLetras; ++c) {
		solucion[posicion] = c;
		if (posicion == nTamano - 1) {
			for (int w = 0; w < nTamano; w++)
				std::cout << solucion[w];
			std::cout << "\n";
		}
		else
			resolver(mLetras, nTamano, usadas, solucion, posicion + 1);
	}
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	//numero de letras y tamaño de la palabra
	int mLetras;
	int nTamano;

	std::cin >> mLetras >> nTamano;
	if (!std::cin)
		return false;
	std::vector<bool> usadas(mLetras, false);	//Controla las letras que se han usado en cada camino
	std::vector<char> solucion(nTamano);
	int posicion = 0;
	// escribir sol
	resolver(mLetras, nTamano, usadas, solucion, posicion);
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