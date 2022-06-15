
#include <iostream>
#include <string>
#include <vector>
#include <fstream>

#include <unordered_map>
#include <map>


using namespace std;

using profesor = std::string;
using alumno = std::string;
using puntos = int;

struct infoAlumno {
	profesor Nombre_;
	puntos Puntos_;

};

class AutoEscuela {
public:
	unordered_map<profesor, map<alumno, puntos>> ListaProfesores;
	unordered_map<alumno, infoAlumno> ListaAlumnos;


	void alta(alumno a, profesor p) {
		if (ListaAlumnos.count(a)) {
			//Si ya estaba matriculado
			int puntosAux = ListaProfesores[ListaAlumnos[a].Nombre_][a];
			ListaProfesores[ListaAlumnos[a].Nombre_].erase(a);
			ListaProfesores[p][a] = puntosAux;
			ListaAlumnos[a].Nombre_ = p;
		}
		else {
			//Si no estaba matriculado
			ListaProfesores[p][a] = 0;
			ListaAlumnos[a] = infoAlumno{ p,0 };
		}
	}

	bool es_alumno(alumno a, profesor p) {
		auto it = ListaProfesores[p].find(a);
		return it != ListaProfesores[p].cend();
	}

	int puntuacion(alumno a) {
		if (!ListaAlumnos.count(a)) throw domain_error("El alumno " + a + " no esta matriculado");
		else {
			auto it = ListaAlumnos[a];
			return it.Puntos_;
		}
	}

	void actualizar(alumno a, puntos n) {
		if (!ListaAlumnos.count(a)) throw domain_error("El alumno " + a + " no esta matriculado");
		else {
			ListaAlumnos[a].Puntos_ += n;
			ListaProfesores[ListaAlumnos[a].Nombre_][a] += n;
		}
	}

	std::vector<alumno> examen(profesor p, puntos n) {
		std::vector<alumno> alumnos;
		auto it = ListaProfesores[p].begin();
		while (it != ListaProfesores[p].cend()) {
			if (it->second >= n)
				alumnos.push_back(it->first);
			++it;
		}
		return alumnos;
	}

	void aprobar(alumno a) {
		if (!ListaAlumnos.count(a)) throw domain_error("El alumno " + a + " no esta matriculado");
		else {
			ListaProfesores[ListaAlumnos[a].Nombre_].erase(a);
			ListaAlumnos.erase(a);
		}
	}

private:

};

bool resuelveCaso() {
	std::string orden, alum, prof;
	int punt;
	std::cin >> orden;
	if (!std::cin)
		return false;

	AutoEscuela escuela;

	while (orden != "FIN") {
		try {
			if (orden == "alta") {
				cin >> alum >> prof;
				escuela.alta(alum, prof);
			}
			else if (orden == "es_alumno") {
				cin >> alum >> prof;
				if (escuela.es_alumno(alum, prof))
					cout << alum << " es alumno de " << prof << '\n';
				else
					cout << alum << " no es alumno de " << prof << '\n';
			}
			else if (orden == "puntuacion") {
				cin >> alum;
				int puntos = escuela.puntuacion(alum);
				cout << "Puntuacion de " << alum << ": " << puntos << '\n';
			}
			else if (orden == "actualizar") {
				cin >> alum >> punt;
				escuela.actualizar(alum, punt);
			}
			else if (orden == "examen") {
				cin >> prof >> punt;
				cout << "Alumnos de " << prof << " a examen:\n";
				for (auto const& a : escuela.examen(prof, punt)) {
					cout << a << '\n';
				}
			}
			else if (orden == "aprobar") {
				cin >> alum;
				escuela.aprobar(alum);
			}
		}
		catch (std::domain_error e) {
			std::cout << "ERROR\n";
		}
		std::cin >> orden;
	}
	std::cout << "---\n";
	return true;
}

int main() {

	// ajuste para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
   // _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	std::ifstream in("datos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

	while (resuelveCaso());

	// restablecimiento de cin
#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	//system("pause");
#endif
	return 0;
}
