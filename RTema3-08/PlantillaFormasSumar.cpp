
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;

bool esValida(vector<int>& sol, const vector<string>& tipos, int posicion) {
	//Devuelve si el tipo actual y el anterior son iguales
	//Y si el primer juguete < segundo juguete
	return (tipos[sol[posicion]] != tipos[sol[posicion - 1]] &&
		sol[posicion - 1] < sol[posicion]);
}

void resolver(int juguetes, int nNinos, const vector<string>& tipos, int posicion, vector<int>& sol, bool& encontroSolucion) {
	for (int i = 0; i < juguetes; ++i) {
		sol[posicion] = i;
		//Si es el caso par (0,2,4), es decir el primer juguete del nino, o el segundo juguete es valido
		if (posicion % 2 == 0 || esValida(sol, tipos, posicion)) {
			if (posicion == (nNinos * 2) - 1) {
				encontroSolucion = true;
				for (int i = 0; i < sol.size(); ++i) {
					std::cout << sol[i] << " ";
				}
				std::cout << "\n";
			}
			else resolver(juguetes, nNinos, tipos, posicion + 1, sol, encontroSolucion);
		}
	}
}


// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	int n, valor;
	cin >> n;                   //Numero de juguetes
	if (!cin) return false;
	cin >> valor;               //Numero de ninos

	vector<string> nums(n);		//Tipos de juguetes
	vector<int> sol(valor * 2);			//Solucion, de longitud ninos*2 

	for (int i = 0; i < n; ++i)
		cin >> nums[i];

	int posicion = 0;
	bool encontroSolucion = false;
	resolver(n, valor, nums, posicion, sol, encontroSolucion);

	if (!encontroSolucion)
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

