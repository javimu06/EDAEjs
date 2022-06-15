//VJ39 El Moncho
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm> 
#include <math.h> 

#include <unordered_map>
#include <map>

using pelicula = std::string;
using actor = std::string;
using tiempo = int;
using emisiones = int;

struct InfoActor {
	actor nombre_;
	tiempo tiempo_;
};

std::unordered_map<pelicula, std::vector< InfoActor> >ListaPeliculas;

std::unordered_map<pelicula, emisiones> PeliculasEmitidasNOORDEN;
std::unordered_map<actor, tiempo> ActoresEmitidosNOORDEN;

std::map<emisiones, pelicula> PeliculasEmitidas;
std::map<tiempo, std::vector<actor>> ActoresEmitidos;


// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	int numPelis;
	std::cin >> numPelis;
	if (numPelis == 0)
		return false;

	pelicula pelicula_;
	int nActores;

	std::vector<std::pair<actor, tiempo>> actores_;
	tiempo tiempo_;
	for (int i = 0; i < numPelis; ++i) {
		std::cin >> pelicula_ >> nActores;
		for (int j = 0; j < nActores; ++j) {
			actor actor_;
			std::cin >> actor_ >> tiempo_;
			ListaPeliculas[pelicula_].push_back({ actor_,tiempo_ });
		}
	}

	int nEmisiones;
	std::cin >> nEmisiones;

	for (int i = 0; i < nEmisiones; ++i) {
		std::cin >> pelicula_;
		PeliculasEmitidasNOORDEN[pelicula_] += 1;
		for (int j = 0; j < ListaPeliculas[pelicula_].size(); ++j) {
			ActoresEmitidosNOORDEN[ListaPeliculas[pelicula_][j].nombre_] += ListaPeliculas[pelicula_][j].tiempo_;
		}
	}

	auto it = PeliculasEmitidasNOORDEN.begin();
	while (it != PeliculasEmitidasNOORDEN.cend()) {
		PeliculasEmitidas[it->second] = it->first;
		++it;
	}

	it = ActoresEmitidosNOORDEN.begin();
	while (it != ActoresEmitidosNOORDEN.cend()) {
		ActoresEmitidos[it->second].push_back(it->first);
		++it;
	}

	if (PeliculasEmitidas.size() > 0) {
		auto auxIt = PeliculasEmitidas.cend();
		--auxIt;
		std::cout << auxIt->first << " ";
		std::cout << PeliculasEmitidas[auxIt->first] << " ";

		std::cout << "\n";
	}

	if (ActoresEmitidos.size() > 0) {
		auto auxIt = ActoresEmitidos.cend();
		--auxIt;
		std::cout << auxIt->first << " ";
		for (int i = 0; i < auxIt->second.size(); ++i) {
			std::cout << ActoresEmitidos[auxIt->first][i] << " ";
		}
		std::cout << "\n";
	}


	ListaPeliculas.clear();

	PeliculasEmitidasNOORDEN.clear();
	ActoresEmitidosNOORDEN.clear();

	PeliculasEmitidas.clear();
	ActoresEmitidos.clear();

	return true;
}


//#define DOMJUDGE
int main() {

#ifndef DOMJUDGE
	std::ifstream in("datos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

	while (resuelveCaso());

#ifndef DOMJUDGE 
	std::cin.rdbuf(cinbuf);
#endif

	return 0;
}
