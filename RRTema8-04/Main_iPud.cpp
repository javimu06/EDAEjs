
#include <iostream>
#include <fstream>
#include <string>
#include <cassert>
#include <stdexcept>
#include <list>
#include <vector>

#include <unordered_map>
#include <map>
using namespace std;

using cancion = std::string;
using artista = std::string;
using duracion = int;

struct infoCancion {
	artista Artista_;
	duracion Duracion_;

};

class iPud {
public:
	unordered_map<cancion, infoCancion> biblioteca;
	list<cancion> colaReproduccion;
	list<cancion> recientes;

	void addSong(cancion c, artista a, duracion d) {
		if (!biblioteca.count(c)) {
			biblioteca[c] = infoCancion{ a, d };
		}
		else throw domain_error("da error dice el enunciao");
	}

	void addToPlaylist(cancion s) {
		if (biblioteca.count(s)) {
			auto it = colaReproduccion.begin();
			bool anade = true;
			while (it != colaReproduccion.end() && anade) {
				if (*it == s) anade = false;
				++it;
			}
			if (anade)
				colaReproduccion.push_back(s);
		}
		else throw domain_error("da error dice el enunciao");
	}

	cancion current() {
		if (!colaReproduccion.size())throw domain_error("da error dice el enunciao");
		else return colaReproduccion.front();
	}

	void play() {
		if (colaReproduccion.size()) {
			auto it = recientes.begin();

			while (it != recientes.end()) {
				if (*it == colaReproduccion.front())
					recientes.erase(it);
				++it;
			}

			recientes.push_front(colaReproduccion.front());
			colaReproduccion.pop_front();
		}
	}

	int totalTime() {
		auto it = colaReproduccion.begin();
		int time = 0;
		while (it != colaReproduccion.end()) {
			time += biblioteca[*it].Duracion_;
			++it;
		}
		return time;
	}

	std::vector<cancion> recent(int n) {
		std::vector<cancion> rec;
		auto it = recientes.begin();
		for (int i = 0; i < n; ++i) {
			if (it != recientes.end())
				rec.push_back(*it);

			if (it != recientes.end())
				++it;
		}
		return rec;
	}

	void deleteSong(cancion s) {
		biblioteca.erase(s);

		auto it = recientes.begin();
		while (it != recientes.end()) {
			if (*it == s)
				it = recientes.erase(it);
			else
				++it;
		}

		auto it2 = colaReproduccion.begin();
		while (it2 != colaReproduccion.end()) {
			if (*it2 == s)
				it2 = colaReproduccion.erase(it2);
			else
				++it2;
		}
	}

};

using pelicula = std::string;
using actor = std::string;
using tiempo = int;
using listaactores = map<actor, tiempo>;

class cadena {
	map<actor, tiempo>ListaActores;
	unordered_map<pelicula, listaactores>ListaPeliculas;
};

bool resuelve() {
	string operacion;
	cin >> operacion;
	if (!cin)
		return false;
	cancion tit; artista aut; int dur;
	iPud ipud;
	while (operacion != "FIN") {
		try {
			if (operacion == "addSong") {
				cin >> tit >> aut >> dur;
				ipud.addSong(tit, aut, dur);
			}
			else if (operacion == "addToPlaylist") {
				cin >> tit;
				ipud.addToPlaylist(tit);
			}
			else if (operacion == "current") {
				tit = ipud.current(); // aunque no se hace nada, puede producir error
			}
			else if (operacion == "play") {
				try {
					string tocando = ipud.current(); // para saber si la lista es vacía
					ipud.play();
					cout << "Sonando " << tocando << '\n';
				}
				catch (domain_error e) {
					cout << "No hay canciones en la lista\n";
				}
			}
			else if (operacion == "totalTime") {
				cout << "Tiempo total " << ipud.totalTime() << '\n';
			}
			else if (operacion == "recent") {
				int N;
				cin >> N;
				auto lista = ipud.recent(N);
				if (lista.empty())
					cout << "No hay canciones recientes\n";
				else {
					cout << "Las " << lista.size() << " mas recientes\n";
					for (auto const& s : lista)
						cout << "    " << s << '\n';
				}
			}
			else if (operacion == "deleteSong") {
				cin >> tit;
				ipud.deleteSong(tit);
			}
			else { // operacion desconocida
				assert(false);
			}
		}
		catch (std::domain_error e) {
			std::cout << "ERROR\n";
		}
		cin >> operacion;
	}
	cout << "---\n";
	return true;
}

int main() {

	// ajuste para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
   // _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	std::ifstream in("datos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

	while (resuelve());

	// restablecimiento de cin
#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	//system("pause");
#endif
	return 0;
}
