// Javier Muñoz Martín de la Sierra
// VJ39


#include <iostream>
#include <iomanip>
#include <fstream>

#include <vector>



// función que resuelve el problema
void resolver(std::vector<int>& sol, const int& pos, std::vector<int>& elementos, const int& cantidad, int& formas) {
	for (int i = 0; i < 2; ++i) {
		sol[pos] = i;
		if (pos == sol.size() - 1) {
			int suma = 0;
			for (int j = 0; j < sol.size(); ++j)
			{
				//std::cout << sol[j] << " ";
				if (sol[j])
					suma += elementos[j];
			}
			//std::cout << "\n";

			if (suma == cantidad)
				++formas;
		}
		else {
			resolver(sol, pos + 1, elementos, cantidad, formas);
		}
	}
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	int nElementos, cantidad;
	std::cin >> nElementos >> cantidad;
	if (!std::cin)
		return false;

	std::vector<int>elementos(nElementos);
	for (int i = 0; i < nElementos; ++i)
		std::cin >> elementos[i];

	std::vector<int>  sol(nElementos);
	int formas = 0;
	resolver(sol, 0, elementos, cantidad, formas);

	// escribir sol
	std::cout << formas << "\n";

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