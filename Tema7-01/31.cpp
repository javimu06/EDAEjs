//Ejercicio 31
//Mauricio Abbati Loureiro - EDA 2ºE 2018/2019
//E01
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <map>
#include <vector>

bool resuelveCaso() {

	int n;
	std::cin >> n;
	std::cin.get(); //Cojo la g donde la almaceno? pa que sirve?

	if (n == 0)
		return false;

	std::string linea;
	std::string clave;
	std::map<std::string, std::vector<int>> m;

	for (int i = 1; i <= n; ++i) {       //Recorremos las lineas
		getline(std::cin, linea);
		std::stringstream v(linea);     //Nos permite movernos por una linea de strings y cogerlos de 1 en 1
		while (v >> clave) {            //Damos valor a la clave con el primer string de v
			for (int t = 0; t < clave.size(); t++) clave[t] = tolower(clave[t]);    //Lo paso a minusculas
			if (clave.size() > 2) {
				//Si m[clave].size() (la dimension del vector<int>) es mayor que 0 (ya se ha encontrado en alguna linea)
				//&& m[clave][m[clave].size() - 1] (el ultimo valor de vector<int> no coincide con la linea, es decir estamos comprobando que no sale la misma palabra en la misma linea varias veces)
				// Anadimos a vector<int> la linea en la que hemos encontrado la palabra
				if (m[clave].size() > 0) {
					if (m[clave][m[clave].size() - 1] != i)
						m[clave].push_back(i);
				}
				//Si no hemos encontrado la palabra en ninguna linea, anadimos la linea en la que hemos encontrado la primera aparicion
				else if (m[clave].size() == 0)
					m[clave].push_back(i);
			}
		}
	}

	//SALIDA
	for (auto& it : m) {
		std::cout << it.first;	//Accedemos al string del  iterador
		for (int i = 0; i < it.second.size(); ++i)	//Recorremos vector<int> y vamos imprimiendo las lineas donde aparecio
			std::cout << " " << it.second[i];
		std::cout << "\n";
	}

	std::cout << "----\n";
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
	//system("PAUSE");
#endif

}
