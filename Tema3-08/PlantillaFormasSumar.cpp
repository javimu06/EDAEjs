
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;

bool esValida(const vector<string>& tiposJuguetes, vector<int>& solucion, int posicion) {
	bool auxiliar = true;

	if (posicion > 0 && posicion % 2 != 0) {
		//Comprobar que el primer juguete es menor y Comprobar que son tipos de juguetes diferenes
		if (solucion[posicion - 1] > solucion[posicion] || tiposJuguetes[solucion[posicion - 1]] == tiposJuguetes[solucion[posicion]])
			auxiliar = false;
	}
	return auxiliar;
}

void resolver(const vector<string>& tiposJuguetes, vector<bool>& usadas, vector<int>& solucion, bool& findSol, long unsigned int posicion) {
	for (long unsigned int i = 0; i < tiposJuguetes.size(); i++) {
		
		//Reiniciamos los juguetes usados para cada nino
		if (i == tiposJuguetes.size()-1)
		{
			for (long unsigned int j = 0; j < usadas.size(); j++)
			{
				usadas[j] = false;
			}
		}
		
		if (!usadas[i]) {
			solucion[posicion] = i;
			if (esValida(tiposJuguetes, solucion, posicion)) {
				if (posicion == solucion.size() - 1) {
					findSol = true;
					for (long unsigned int i = 0; i < solucion.size(); i++)
						std::cout << solucion[i] << " ";
					std::cout << "\n";
				}
				else
				{
					usadas[i] = true;
					resolver(tiposJuguetes, usadas, solucion, findSol, posicion + 1);
					usadas[i] = false;
				}
			}
		}
		
	}

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	int nJuguetes, nNinos;
	cin >> nJuguetes >> nNinos;
	if (!cin) return false;

	vector<string> tiposJuguetes(nJuguetes);
	for (int i = 0; i < nJuguetes; ++i)
		cin >> tiposJuguetes[i];

	vector<bool> validas(nJuguetes, false);
	vector<int> solucion(nNinos * 2);
	bool findSol = false;
	resolver(tiposJuguetes, validas, solucion, findSol, 0);
	if (!findSol)
		std::cout << "SIN SOLUCION\n";

	std::cout << "\n";
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

