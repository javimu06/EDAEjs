// Javier Muñoz Martin de la Sierra
// VJ39


#include <iostream>
#include <iomanip>
#include <fstream>
#include <list>


// función que resuelve el problema
void resolver(std::list<char>& elementos, const int& pos, const int& lon, const int& k) {
	if (k == 0 || lon == 0) return;
	if (pos - k < 0) return;


	int pos2 = pos - k;
	auto itPringao = elementos.begin();
	auto itCuela = elementos.begin();

	//Avanzamos el iterador a la posicion donde vamos a empezar a colar
	for (int i = 0; i < pos2; ++i) {
		if (itPringao == elementos.cend()) return;	//Si la posicion del pringao se sale de la lista la operacion no tiene efecto
		++itPringao;
		++itCuela;
	}

	for (int i = 0; i < k; ++i) {
		if (itCuela == elementos.cend()) return;
		++itCuela;
	}

	for (int i = 0; i < lon; ++i) {
		if (itCuela != elementos.cend())
			elementos.insert(itPringao, *itCuela);
		if (itCuela != elementos.cend())
			itCuela = elementos.erase(itCuela);
	}


}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
	// leer los datos de la entrada
	int n, pos, lon, k;
	std::cin >> n >> pos >> lon >> k;

	std::list<char>elementos;
	for (int i = 0; i < n; ++i) {
		char x;
		std::cin >> x;
		elementos.push_back(x);
	}

	resolver(elementos, pos, lon, k);
	// escribir sol

	int sizeOri = elementos.size();
	for (int i = 0; i < sizeOri; ++i) {
		std::cout << elementos.front() << " ";
		elementos.pop_front();
	}
	std::cout << "\n";
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