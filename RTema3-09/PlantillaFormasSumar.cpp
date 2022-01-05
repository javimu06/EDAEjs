
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;

bool calculaSatisfaccion(const vector<int>& sol, const vector<vector< int>>& satisfaccionJuguetes, const int satisf, int posicion) {
	int satisCalculada = 0;
	int contadorNinos = (posicion - 1) / 2;
	for (int i = posicion - 1; i < posicion + 1; ++i) {
		satisCalculada += satisfaccionJuguetes[contadorNinos][sol[i]];
		if (i % 2 != 0)//En impares, los segundos juguetes
		{
			//Si la satisfaccion calculada por nino es menor a la esperada directamente devolvemos false
			if (satisCalculada < satisf) return false;
		}
	}
	//Si no se ha devuelto false antes es porque todos los ninos cumplen la satisfaccion minima
	return true;
}

bool esValida(vector<int>& sol, const vector<string>& tipos, int posicion, const vector<vector< int>>& satisfaccionJuguetes, const int satisf) {
	//Devuelve si el tipo actual y el anterior son iguales
	//Y si el primer juguete < segundo juguete
	return (tipos[sol[posicion]] != tipos[sol[posicion - 1]] &&
		sol[posicion - 1] < sol[posicion] &&
		calculaSatisfaccion(sol, satisfaccionJuguetes, satisf, posicion));
}



void resolver(const int juguetes, const int nNinos, const vector<string>& tipos, int posicion, vector<int>& sol, bool& encontroSolucion, vector<int>& cantidad, vector<vector< int>>& satisfaccionJuguetes, const int satisf) {
	for (int i = 0; i < juguetes; ++i) {
		sol[posicion] = i;

		if (cantidad[i] > 0) {
			//Si es el caso par (0,2,4), es decir el primer juguete del nino, o el segundo juguete es valido
			if (posicion % 2 == 0 || esValida(sol, tipos, posicion, satisfaccionJuguetes, satisf)) {
				cantidad[i]--;
				if (posicion == (nNinos * 2) - 1) {
					encontroSolucion = true;
					for (int i = 0; i < sol.size(); ++i) {
						std::cout << sol[i] << " ";
					}
					std::cout << "\n";
					cantidad[i]++;
				}
				else {
					resolver(juguetes, nNinos, tipos, posicion + 1, sol, encontroSolucion, cantidad, satisfaccionJuguetes, satisf);
					cantidad[i]++;
				}
			}
		}
	}
}


// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	int n, valor, satisf;
	cin >> n;                   //Numero de juguetes
	if (!cin) return false;
	cin >> valor;               //Numero de ninos
	cin >> satisf;              //Satisfaccion minima

	vector<string> nums(n);		//Tipos de juguetes
	vector<int> sol(valor * 2);	//Solucion, de longitud ninos*2 
	vector<vector< int>> satisfaccionJuguetes(valor);
	vector<int> cantidad(n);	//cantidad de juguetes

	//Guardamos unidades de juguetes
	for (int z = 0; z < cantidad.size(); ++z)
		std::cin >> cantidad[z];

	//Guardamos tipos de juguetes
	for (int i = 0; i < n; ++i)
		cin >> nums[i];

	//Guardamos satisfaccion de ninos por juguetes
	//recorremos ninos
	for (int j = 0; j < valor; ++j) {
		//Por cada nino recorremos juguetes
		satisfaccionJuguetes[j] = vector<int>(n);
		for (int w = 0; w < n; ++w) {
			std::cin >> satisfaccionJuguetes[j][w];
		}
	}

	int posicion = 0;
	bool encontroSolucion = false;
	resolver(n, valor, nums, posicion, sol, encontroSolucion, cantidad, satisfaccionJuguetes, satisf);

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

