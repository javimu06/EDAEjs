
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;

bool esValida(vector<int>& sol) {
	for (int i = 1; i < sol.size(); ++i) {
		if (sol[i] < sol[i - 1]) return false;
	}
	return true;
}

void resolver(vector<int>& nums, int valor, int pos, vector<int>& sol, vector<bool>& usadas, int& formas) {
	for (int i = 0; i < nums.size(); ++i) {
		sol[pos] = nums[i];
		if ( !usadas[i]) {
			usadas[i] = true;
			if (pos == sol.size() - 1) {
				if (esValida(sol)) {
					int suma = 0;
					for (int w = 0; w < sol.size(); ++w) {
						suma += sol[w];
						if (suma == valor) formas++;
					}
				}
				usadas[i] = false;
			}
			else {
				resolver(nums, valor, pos + 1, sol, usadas, formas);
				usadas[i] = false;
			}
		}
	}
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	int nNumeros, valor;
	cin >> nNumeros >> valor;
	if (!cin) return false;

	vector<int> nums(nNumeros );
	vector<int> sol(nNumeros);
	vector<bool> usadas(nNumeros);

	for (int i = 0; i < nNumeros; ++i)
		cin >> nums[i];
	int formas = 0;
	resolver(nums, valor, 0, sol, usadas, formas);
	std::cout << formas << "\n";
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

