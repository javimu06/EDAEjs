// Javier Muñoz Martin de la Sierra
// VJ39


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

void printSolucion(std::vector<int>& solucion) {
	for (int w = 0; w < solucion.size(); w++) {
		switch (solucion[w])
		{
		case 0:
			std::cout << "azul ";
			break;
		case 1:
			std::cout << "rojo ";
			break;
		case 2:
			std::cout << "verde ";
			break;
		}
	}
}

bool esValida(int posicion, std::vector<int>& solucion) {
	if (posicion > 1 && solucion[posicion] == 2)
		return(solucion[posicion - 1] != solucion[posicion]);
	if (solucion[0] == 1)
		return true;
	return false;
}

// función que resuelve el problema
void resolver(int nPiezas, int mTamano, int posicion, std::vector<int>& solucion) {
	for (int i = 0; i < nPiezas; i++) {
		solucion[posicion] = i;
		//restricciones
			//Si el color en la posicion 0 es diferente de 1 (ROJO), no es solucion
			//Si la posicion actual es verde y la anterior tambien, no es solucion
		if (esValida(posicion, solucion)) {
			if (posicion == mTamano - 1) {
				printSolucion(solucion);
				std::cout << "\n";
			}
			else {
				resolver(nPiezas, mTamano, posicion + 1, solucion);
			}
		}
	}
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	int mTamano;
	std::cin >> mTamano;
	if (mTamano == 0)
		return false;

	int nPiezas = 3;
	int posicion = 0;
	std::vector<int> solucion(mTamano);
	// escribir sol
	resolver(nPiezas, mTamano, posicion, solucion);
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


	while (resuelveCaso())
		;


	// Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}
