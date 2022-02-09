
#include <iostream>
#include <string>
#include <vector>
#include <fstream>

#include <map>
#include <unordered_map>

#include <set>

using namespace std;

using Profesor = string;
using Alumno = string;
using Puntos = int;

struct infoAlumno {
	Alumno nombre;
	Profesor profesor;
	Puntos puntos;
};

using ListaAlumnos = unordered_map<Alumno, infoAlumno>;
using ListaProfesores = unordered_map<Profesor, set<Alumno>>;

class AutoEscuela {
private:
	ListaProfesores listaProfesores;
	ListaAlumnos listaAlumnos;
	//vector<infoAlumno, greater<Alumno>> alumnos;
	vector<infoAlumno> alumnos;
public:
	AutoEscuela() {};
	void alta(Alumno a, Profesor p) {
		//Si el alumno no estaba matriculado
		if (listaAlumnos.count(a) == 0) {
			//Adjudicamos al alumno el profesor y los puntos
			listaAlumnos[a].nombre = a;
			listaAlumnos[a].profesor = p;
			listaAlumnos[a].puntos = 0;
			//Adjudicamos al profesor el alumno con sus datos
			listaProfesores[p].insert(a);
			//!listaAlumnos[a].elIteradorSandokanico = listaProfesores[p].end() - 1;
		}
		//Si el alumno ya estaba matriculado
		else {
			listaProfesores[listaAlumnos[a].profesor].erase(a);
			listaAlumnos[a].profesor = p;
			listaProfesores[p].insert(a);
		}
	}

	bool es_alumno(Alumno a, Profesor p) {
		return(listaAlumnos[a].profesor == p);
	}

	int puntuacion(Alumno a) {
		if (listaAlumnos.count(a) == 0) throw domain_error("El alumno " + a + " no esta matriculado");
		return listaAlumnos[a].puntos;
	}

	void actualizar(Alumno a, Puntos n) {
		if (listaAlumnos.count(a) == 0) throw domain_error("El alumno " + a + " no esta matriculado");
		listaAlumnos[a].puntos += n;
		if (listaAlumnos[a].puntos < 0)listaAlumnos[a].puntos = 0;
	}

	vector<Alumno> examen(Profesor p, Puntos n) {
		vector<Alumno> presentados;
		for (auto a : listaProfesores[p]) {
			if (listaAlumnos[a].puntos >= n)
				presentados.push_back(listaAlumnos[a].nombre);
		}
		return presentados;
	}

	void aprobar(Alumno a) {
		if (listaAlumnos.count(a) == 0) throw domain_error("El alumno " + a + " no esta matriculado");
		//listaProfesores[listaAlumnos[a].profesor].erase(listaAlumnos[a].elIteradorSandokanico);
		listaProfesores[listaAlumnos[a].profesor].erase(a);
		listaAlumnos.erase(a);
	}

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
