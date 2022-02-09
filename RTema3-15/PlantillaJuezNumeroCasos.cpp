// Javier Muñoz Martin de la Sierra
// VJ39


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <climits>

bool esValida() {


	return true;
}

// función que resuelve el problema
void resolver(const std::vector<std::vector<int>>& supermercados, int productosMaximos, long long int& mejorPrecio, const int& nProductos, std::vector<int>& sol, std::vector<bool>& comprados, int pos) {
	//Recorro todos los supermercados y todos los productos de cada supermercado
	for (int j = 0; j < nProductos; ++j) {
		//Guardo todas las soluciones posibles, es decir el precio de cada producto de cada supermercado
		sol[pos] = j;
		if (!comprados[j]) {
			if (pos == sol.size() - 1) {
				//Actualizo el mejor precio cuando encuentro una solucion
				//Me quedo con el mas barato
				int presio = 0;
				//Recorro todos los productos y cada 3 cambio de supermercado
				for (int w = 0; w < sol.size() - 1; ++w) {
					presio += supermercados[w / 3][sol[w]];
				}
				if (mejorPrecio > presio)
					mejorPrecio = presio;
			}
			else {
				//Marco los productos comprados para no volver a comprarlos
				comprados[pos] = true;
				resolver(supermercados, productosMaximos, mejorPrecio, nProductos, sol, comprados, pos + 1);
				comprados[pos] = false;
			}
		}
	}
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
	int mMercados, nProductos;
	// leer los datos de la entrada
	std::cin >> mMercados;
	std::cin >> nProductos;
	//std::vector<int> precios(nProductos);					//Precios de 1 supermercado
	std::vector<std::vector<int>>Supermercados(mMercados, std::vector<int>(nProductos));	//Vector de supermercados y sus precios

	for (int i = 0; i < mMercados; ++i) {
		for (int j = 0; j < nProductos; ++j) {
			int x;
			std::cin >> Supermercados[i][j];
		}
	}

	int productosMaximos = 0;								//Como mucho puede comprar 3 productos
	long long int mejorPrecio = INT_MAX;
	std::vector<int> sol(10, 0);
	std::vector<bool> comprados(nProductos, false);
	resolver(Supermercados, productosMaximos, mejorPrecio, nProductos, sol, comprados, 0);
	// escribir sol
	std::cout << mejorPrecio << "\n";

}

int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
#ifndef DOMJUDGE
	std::ifstream in("datos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 


	int numCasos;
	std::cin >> numCasos;
	for (int i = 0; i < numCasos; ++i)
		resuelveCaso();


	// Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}