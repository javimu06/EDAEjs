
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;

int getSatisfaccion(const vector<vector<int>>& satisfaccionNinoRegalos, const vector<int>& sol) {
	int aux = 0;
	//Recorremos ninos y vemos cuanto puntua el regalo asignado
	for (int i = 0; i < sol.size(); ++i) {
		aux += satisfaccionNinoRegalos[i][sol[i]];
	}
	return aux;
}

void resolver(vector<vector<int>>& satisfaccionNinoRegalos, int& satisfaccion, vector<bool>& juguetesAsignados, int posicion, int& satisfaccionEnd, vector<int>& sol) {

	//Recorremos todos los juguetes y los asignamos todas las posibilidades
	for (int i = 0; i < juguetesAsignados.size(); ++i) {
		sol[posicion] = i;
		//Si el juguete no estaba asignado
		if (!juguetesAsignados[i]) {
			//Lo asigno
			//Si hemos encontrado una posible solucion
			if (posicion == sol.size() - 1) {
				//Calculamos la satisfaccion obtenida con la solucion
				satisfaccionEnd = getSatisfaccion(satisfaccionNinoRegalos, sol);
				//Si es mayor que la anterior la actualizamos
				if (satisfaccionEnd > satisfaccion)
					satisfaccion = satisfaccionEnd;
				//Desasignamos el ultimo juguete
			}
			else {
				juguetesAsignados[i] = true;
				resolver(satisfaccionNinoRegalos, satisfaccion, juguetesAsignados, posicion + 1, satisfaccionEnd, sol);
				juguetesAsignados[i] = false;
			}
		}
	}
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	int nRegalos, nNinos;
	cin >> nRegalos >> nNinos;
	if (!cin) return false;

	vector<vector<int>> satisfaccionNinoRegalos(nNinos);
	vector<bool> juguetesAsignados(nRegalos, false);
	//Un regalo por nino
	vector<int> sol(satisfaccionNinoRegalos.size());

	for (int i = 0; i < nNinos; ++i) {
		satisfaccionNinoRegalos[i] = vector<int>(nRegalos);
		for (int j = 0; j < nRegalos; ++j) {
			cin >> satisfaccionNinoRegalos[i][j];
		}
	}

	int satisfaccion = 0;
	int satisfaccionEnd = 0;
	resolver(satisfaccionNinoRegalos, satisfaccion, juguetesAsignados, satisfaccion, satisfaccionEnd, sol);
	std::cout << satisfaccion << "\n";
	// Salida
	return true;
}

//#define DOMJUDGE
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
	//system("PAUSE");
#endif

	return 0;
}

