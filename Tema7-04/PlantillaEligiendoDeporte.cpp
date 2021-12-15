#include <iostream>
#include <fstream>
#include <cctype>
#include <map>
#include <algorithm>

using namespace std;

//map<string, int>ListaDeportes
using Deporte = string;
using Apuntados = int;

//map<string, string>ListaAlumnos
using Alumnos = string;
//using Deporte = string;


void resolver(string const& primerDeporte, map<Deporte, Apuntados>& listaDeportes) {
	Deporte deporte;
	Alumnos alumno;

	map<Alumnos, Deporte> listaAlumnos;

	deporte = primerDeporte;
	while (deporte != "_FIN_") {

		listaDeportes[deporte] = 0;	//Seteamos los apuntados de ese deporte a 0
		cin >> alumno;
		while (!isupper(alumno[0]) && alumno != "_FIN_") {
			//Si es la primera vez que un alumno tiene deporte
			if (listaAlumnos.count(alumno) == 0) {
				listaAlumnos[alumno] = deporte;	//Apuntamos el deporte del alumno
				listaDeportes[deporte]++;
			}
			//Si un alumno ya tenia deporte
			else
			{
				//Y es un deporte que no es el actual, le restamos al que tenia adjudicado
				if (listaAlumnos[alumno] != deporte && listaAlumnos[alumno] != "Eliminado") {
					listaDeportes[listaAlumnos[alumno]]--;
					listaAlumnos[alumno] = "Eliminado";
				}

			}

			cin >> alumno;
		}
		deporte = alumno;
	}
}

//bool operator> (const map<Deporte, Apuntados>& a, const map<Deporte, Apuntados>& b) {
//	if (a.at(0) > b.at(0)) return true;
//	else return false;
//}

//bool operator> (tSol a, tSol b) {
//	if (a.valor > b.valor) return true;
//	else return false;
//}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	string primerDeporte;
	cin >> primerDeporte;
	if (!cin) return false;

	map<Deporte, Apuntados> ListaDeportes;
	resolver(primerDeporte, ListaDeportes);
	/*if (ListaDeportes.size() != 0)
		std::sort(ListaDeportes.begin(), ListaDeportes.end(), std::greater<Deporte>());*/

	for (auto& a : ListaDeportes) {
		std::cout << a.first << " " << a.second << "\n";
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