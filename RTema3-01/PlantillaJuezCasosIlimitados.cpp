// Javier Muñoz Martín de la Sierra
// VJ39


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>


void recurre(const int& m, const int& n, std::vector<char>& aux, int pos) {
	for (char i = 'a'; i < 'a' + m; ++i) {
		aux[pos] = i;
		if (pos == n - 1) {
			for (int j = 0; j < n; j++) {
				std::cout << aux[j];
			}
			std::cout << "\n";
		}
		else recurre(m, n, aux, pos + 1);
	}
}


// función que resuelve el problema
void resolver(const int& m, const int& n) {
	std::vector<char> aux(2);
	int pos = 0;
	recurre(m, n, aux, pos);
}


// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	int m;  //m elementos
	int n;  //de n en n
	std::cin >> m;
	std::cin >> n;

	if (!std::cin)
		return false;
	

	resolver(m, n);

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