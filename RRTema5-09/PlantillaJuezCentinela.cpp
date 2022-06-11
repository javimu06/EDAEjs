// Javier Muñoz Martin de la Sierra
// VJ39


#include <iostream>
#include <iomanip>
#include <fstream>
#include <list>

void resuelve(std::list<int>& elementos, const int& espaciado)
{
	auto it = elementos.begin();

	while (elementos.size() > 1) {

		for (int i = 0; i < espaciado; ++i) {
			++it;
			if (it == elementos.end())
				it = elementos.begin();
		}

		it = elementos.erase(it);

		if (it == elementos.end())
			it = elementos.begin();

	}

	std::cout << *it << "\n";
}
// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	int nElementos, espaciado;
	std::cin >> nElementos >> espaciado;
	if (nElementos == 0 && espaciado == 0)
		return false;

	std::list<int> elementos;
	for (int i = 0; i < nElementos; ++i) {
		elementos.push_back(i + 1);
	}
	// escribir sol
	resuelve(elementos, espaciado);

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
