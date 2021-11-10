// Javier Muñoz Martin de la Sierra
// VJ39


#include <iostream>
#include <iomanip>
#include <fstream>
#include <list>


// función que resuelve el problema
void resolver(std::list<unsigned int>& clase, const int salvados) {
	auto it = clase.begin();
	while (clase.size() > 1) {
		for (int i = 0; i < salvados; ++i) {
			//Tengo que comprobar que it == end() porque end no es el ultimo, es el siguiente
			if (it == --clase.end())
				it = clase.begin();
			else
				++it;
		}
		it = clase.erase(it);
		//Si elimno el ultimo elemento el iterador me va a devolver el siguiente al que borro
		// que seria MUERTE
		// Por eso tengo que comprobar que si elimino el ultimo me devuelva el primero para continuar el conteo
		if (it == clase.end())
			it = clase.begin();
	}
	std::cout << *clase.begin() << "\n";
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	int nAlumnos, nSalvados;
	std::cin >> nAlumnos >> nSalvados;
	if (nAlumnos == 0 && nSalvados == 0)
		return false;

	std::list<unsigned int>clase;
	for (int i = 0; i < nAlumnos; ++i)
		clase.push_back(i + 1);
	// escribir sol
	if (clase.size() > 0)
		resolver(clase, nSalvados);
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
