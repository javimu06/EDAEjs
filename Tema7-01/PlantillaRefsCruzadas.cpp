#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <list>
#include <vector>

using namespace std;

using Palabra = string;
using lineaAparicion = vector<int>;

using TablaRefs = map<Palabra, lineaAparicion>;

void referencias(int numLineas, TablaRefs& refs) {
	Palabra palabra;
	char c;
	for (int numLinea = 1; numLinea <= numLineas; numLinea++) {	//Recorremos las lineas
		cin.get(c);
		while (c != '\n') {
			cin.unget(); // Se vuelve a dejar c en cin (por si era la 1ª letra de la linea)
			cin >> palabra;	//Cogemos la palabra
			//Si la palabra mide minimo 3 letras
			if (palabra.size() > 2) {
				//La pasamos a minusculas
				for (int i = 0; i < palabra.size(); i++)palabra[i] = tolower(palabra[i]);	//Pasamos todo a minusculas
				//Si no se ha encontrado antes la palabra, insertamos la linea en la que la encontramos
				//Si m[clave].size() (la dimension del vector<int>) es mayor que 0 (ya se ha encontrado en alguna linea)
				//&& m[clave][m[clave].size() - 1] (el ultimo valor de vector<int> no coincide con la linea, es decir estamos comprobando que no sale la misma palabra en la misma linea varias veces)
				// Anadimos a vector<int> la linea en la que hemos encontrado la palabra
				if (refs[palabra].size() == 0)
					refs[palabra].push_back(numLinea);
				//Si se ha encontrado previamente y no coincide con la linea en la que estamosl la anadimos
				else if (refs[palabra].at(refs[palabra].size() - 1) != numLinea)
					refs[palabra].push_back(numLinea);
			}
			cin.get(c);
		}
	}
}


// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	int n;
	char c;
	cin >> n;
	cin.get(c); // Me salto el \n de detrás del N
	if (n == 0)
		return false;

	TablaRefs refs;
	referencias(n, refs);

	// escribir sol
	for (auto a : refs) {
		std::cout << a.first;
		for (int i = 0; i < a.second.size(); i++)
			std::cout << " " << a.second.at(i);
		std::cout<<"\n";
	}
	cout << "---\n";
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
#endif

	return 0;
}