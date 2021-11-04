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

void quitaPieza(int& nRojas, int& nVerdes, int& nAzules, std::vector<int>& piezasColocadas, int pieza) {
	switch (pieza)
	{
	case 0:
		nAzules++;
		piezasColocadas[0]--;
		break;
	case 1:

		nRojas++;
		piezasColocadas[1]--;

		break;
	case 2:

		nVerdes++;
		piezasColocadas[2]--;
		break;
	default:
		break;
	}
}
bool colocaPieza(int& nRojas, int& nVerdes, int& nAzules, std::vector<int>& piezasColocadas, int pieza) {
	//Actualizo las piezasColocadas
	switch (pieza)
	{
	case 0:
		if (nAzules > 0) {
			nAzules--;
			piezasColocadas[0]++;
		}
		else return false;
		break;
	case 1:
		if (nRojas > 0) {
			nRojas--;
			piezasColocadas[1]++;
		}
		else return false;

		break;
	case 2:
		if (nVerdes > 0) {
			nVerdes--;
			piezasColocadas[2]++;
		}
		else return false;
		break;
	default:
		break;
	}
}

bool esValidaFinal(std::vector<int>& piezasColocadas) {
	//El numero de piezas verdes mas las azules no pueden superar al nº de piezas rojo
	if (piezasColocadas[2] + piezasColocadas[0] >= piezasColocadas[1])
		return false;
	return true;
}

bool esValida(int posicion, std::vector<int>& solucion, int& nRojas, int& nVerdes, int& nAzules, std::vector<int>& piezasColocadas, int pieza) {
	bool aux = true;
	//Si podemos colocar la pieza, comprobamos
	if (!colocaPieza(nRojas, nVerdes, nAzules, piezasColocadas, pieza))
		aux = false;
	//No puede haber dos piezas verdes juntas
	if (posicion > 1 && solucion[posicion] == 2)
		aux = (solucion[posicion - 1] != solucion[posicion]);
	//El numero de piezas verdes no puede superar al nº de piezas azules
	if (piezasColocadas[2] > piezasColocadas[0])
		aux = false;
	//Todas las torres deben de empezar por rojo
	if (solucion[0] != 1)
		aux = false;

	//Si no se cumplen las condiciones, tenemos que quitar la pieza que acabamos de colocar
	if (!aux)
		quitaPieza(nRojas, nVerdes, nAzules, piezasColocadas, pieza);

	return aux;
}


// función que resuelve el problema
void resolver(int nPiezas, int mTamano, int& nRojas, int& nVerdes, int& nAzules, std::vector<int>& piezasColocadas, std::vector<int>& solucion, int posicion) {
	for (int i = 0; i < nPiezas; i++) {
		solucion[posicion] = i;
		//restricciones
			//Si el color en la posicion 0 es diferente de 1 (ROJO), no es solucion
			//Si la posicion actual es verde y la anterior tambien, no es solucion
		if (esValida(posicion, solucion, nRojas, nVerdes, nAzules, piezasColocadas, i)) {
			if (posicion == mTamano - 1) {
				if (esValidaFinal(piezasColocadas)) {
					printSolucion(solucion);
					std::cout << "\n";
				}
				else {
					std::cout << "SIN SOLUCION\n";
					quitaPieza(nRojas, nVerdes, nAzules, piezasColocadas, i);
				}
			}
			else {
				resolver(nPiezas, mTamano, nRojas, nVerdes, nAzules, piezasColocadas, solucion, posicion + 1);
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
	int nRojas, nVerdes, nAzules;	//Nº de piezas de cada color a usar
	std::cin >> nAzules >> nRojas >> nVerdes;	//Orden correcto

	const int nPiezas = 3;
	int posicion = 0;
	std::vector<int> solucion(mTamano);
	std::vector<int> piezasColocadas(3, 0);	//Guarda cuantas piezas se han puesto de cada color

	// escribir sol
	resolver(nPiezas, mTamano, nRojas, nVerdes, nAzules, piezasColocadas, solucion, posicion);
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
/*
4 4 4 4
5 2 2 2
5 3 3 1
*/