
#include <iostream>
#include <string>
#include <cassert>
#include <stdexcept>

#include <list>
#include <unordered_map>


#include <fstream>
#include <utility>

using namespace std;

using cancion = std::string;
using artista = std::string;
using duracion = int;

struct infoCancion {
	cancion nombre_;
	duracion duracion_;
	artista artista_;

	//list<infoCancion>::const_iterator itReproducidas;
	//list<infoCancion>::const_iterator itCola;
};

class iPud {
public:
	unordered_map<cancion, infoCancion> catalogoCanciones;
	list<cancion> cancionesReproducidas;
	list<cancion> cancionesCola;

	int totalTime_;

	void addSong(cancion s, artista a, duracion d) {
		auto c = catalogoCanciones.find(s);

		//Si la cancion no esta en el iPud anado su informacion
		if (c == catalogoCanciones.cend()) {
			catalogoCanciones[s] = { s, d, a };
		}
		else throw domain_error("addSong");
	}

	void addToPlaylist(cancion s) {
		auto c = catalogoCanciones.find(s);

		//Si la cancion no esta en el iPud
		if (c != catalogoCanciones.cend()) {
			//!Tengo que comprobar que la cancion no este a la cola
			cancionesCola.push_back({ c->second.nombre_ });
			totalTime_ += c->second.duracion_;
		}
		else throw domain_error("addToPlaylist");
	}

	cancion current() {
		//Si la cancion no esta a la cola devuelve error
		if (cancionesCola.empty()) throw invalid_argument("current");
		return cancionesCola.front();
	}

	void play() {
		auto it = catalogoCanciones.find(cancionesCola.front());
		if (!cancionesCola.empty()) {
			cancionesReproducidas.push_front(cancionesCola.front());

			totalTime_ -= (*it).second.duracion_;

			cancionesCola.pop_front();
		}
	}

	int totalTime() { return totalTime_; }

	list<cancion> recent(int N) {
		list<cancion> reciente;
		for (auto it = cancionesReproducidas.begin(); it != cancionesReproducidas.cend(); it++) {
			if (reciente.size() == N) return reciente;
			reciente.push_back(*it);
		}
		return reciente;
	}

	void deleteSong(cancion s) {
		auto it = catalogoCanciones.find(s);
		if (it != catalogoCanciones.cend()) {
			/*if (it->second.itListaReproduccion != cancionesCola.cend()) {
				totalTime_ -= it->second.duracion;
				cancionesCola.erase(it->second.itListaReproduccion);
			}
			if (it->second.itListaReproducidas != cancionesReproducidas.cend())
				cancionesReproducidas.erase(it->second.itListaReproducidas);*/

			catalogoCanciones.erase(it);
		}
	}
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
				catch (invalid_argument e) {
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
		catch (invalid_argument e) {
			cout << "ERROR " << e.what() << '\n';
		}
		cin >> operacion;
	}
	cout << "---\n";
	return true;
}

int main() {
#ifndef DOMJUDGE
	ifstream in("datos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

	while (resuelve()) {}

#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif
	return 0;
}
