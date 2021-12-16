#include <iostream>
#include <stdexcept>
#include <fstream>
#include <vector>
#include <unordered_map>
#include <map>
#include <algorithm>

using namespace std;

using Estado = string;
using Partido = string;
using Votos = int;

struct infoEstado {
	int comisarios;
	unordered_map<Partido, Votos> ListaPartidos;
	Partido ganador;
};

class ConteoVotos {

private:
	unordered_map<Estado, infoEstado> ListaEstados;

public:

	void nuevo_estado(const Estado& nombre, int num_compromisarios) {
		if (ListaEstados.count(nombre) == 1)//Si ya existe el estado que queremos crear
			throw std::domain_error("Estado ya existente");
		else
			ListaEstados[nombre].comisarios = num_compromisarios;
	}

	void sumar_votos(const Estado& estado, const Partido& partido, int num_votos) {
		if (ListaEstados.count(estado) != 0)	//Ya existe el estado
		{
			//Sumamos los votos
			ListaEstados[estado].ListaPartidos[partido] += num_votos;
			//Actualizamos el partido con mas votos dentro del estado
			//Si no habia ningun partido ganador, lo adjudicamos
			if (ListaEstados[estado].ganador.empty())
				ListaEstados[estado].ganador = partido;
			//En caso de que el numero de votos del partido ganador vigente sea menor que el numero de votos del partido al que acabamos de sumar,
			//Se reemplaa el ganador vigente
			else if (ListaEstados[estado].ListaPartidos[ListaEstados[estado].ganador] < ListaEstados[estado].ListaPartidos[partido]) {
				ListaEstados[estado].ganador = partido;
			}
		}
		else
			throw std::domain_error("Estado no encontrado");
	}

	Partido ganador_en(const Estado& estado) const {
		if (ListaEstados.count(estado) != 0)	//Ya existe el estado
		{
			return ListaEstados.at(estado).ganador;
		}
		else
			throw std::domain_error("Estado no encontrado");
	}

	vector<pair<Partido, int>> resultados() const {
		vector<pair<Partido, int>> aux;
		map<Partido, int> totalComisarios;
		//map<Partido, int, less<string>> totalComisarios;

		for (auto es : ListaEstados) {
			totalComisarios[es.second.ganador] += es.second.comisarios;
		}

		//sort(totalComisarios.begin(), totalComisarios.end(), greater<string>);

		for (auto e : totalComisarios)
			aux.push_back({ e.first, e.second });

		return aux;
	}
};


bool resuelveCaso() {
	string comando;
	cin >> comando;
	if (!cin) return false;

	ConteoVotos elecciones;

	while (comando != "FIN") {
		try {
			if (comando == "nuevo_estado") {
				Estado estado;
				int num_compromisarios;
				cin >> estado >> num_compromisarios;
				elecciones.nuevo_estado(estado, num_compromisarios);
			}
			else if (comando == "sumar_votos") {
				Estado estado;
				Partido partido;
				int num_votos;
				cin >> estado >> partido >> num_votos;
				elecciones.sumar_votos(estado, partido, num_votos);
			}
			else if (comando == "ganador_en") {
				Estado estado;
				cin >> estado;
				Partido ganador = elecciones.ganador_en(estado);
				cout << "Ganador en " << estado << ": " << ganador << "\n";
			}
			else if (comando == "resultados") {
				for (const auto& par : elecciones.resultados()) {
					cout << par.first << " " << par.second << "\n";
				}
			}
		}
		catch (std::exception& e) {
			cout << e.what() << "\n";
		}
		cin >> comando;
	}

	cout << "---\n";
	return true;
}

int main() {
#ifndef DOMJUDGE
	ifstream in("datos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

	while (resuelveCaso()) {}

#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif
	return 0;
}
