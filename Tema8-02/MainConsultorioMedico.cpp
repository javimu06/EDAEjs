// Plantilla para el ejercicio del Consultorio Médico

#include <iomanip>
#include <iostream>
#include <string>
#include <stdexcept>
#include <cassert>

#include <unordered_map>
#include <map>


using namespace std;
using medico = string;
using paciente = string;



class fecha {
public:
	fecha(int d, int m, int h) { dia = d; minuto = m; hora = h; };

	int dia;
	int minuto;
	int hora;

	friend ostream& operator<<(std::ostream& output, const fecha& s);
};

ostream& operator<<(std::ostream& output, const fecha& s)
{
	output << s.dia << " " << s.hora << ":" << s.hora << '\n';
	return output;
}

bool operator<(const fecha& f1, const fecha& f2)
{
	return (f1.dia < f2.dia ||
		f1.hora < f2.hora ||
		f1.minuto < f2.minuto);
}

class Consultorio {
	using ListaPacientes = map<fecha, paciente>;
	unordered_map<medico, ListaPacientes> ListaMedicos;

public:
	void nuevoMedico(medico m) {
		if (ListaMedicos.count(m) == 0) {
			ListaMedicos[m];
		}
	}

	void pideConsulta(paciente p, medico m, fecha f) {
		//Si no existe el medico
		if (ListaMedicos.count(m) == 0)
			throw domain_error("Medico no existente");
		//Si la fecha esta ocupada
		auto itf = ListaMedicos[m].find(f);
		if (itf != ListaMedicos[m].cend())
			//if (ListaMedicos[m].count(f) != 0)
			throw domain_error("Fecha ocupada");

		ListaMedicos[m][f] = p;
	}

	paciente siguientePaciente(medico m) {
		if (ListaMedicos.count(m) == 0) throw domain_error("Medico no existente");
		//!Cuidao
		if (ListaMedicos.at(m).empty()) throw domain_error("No hay pacientes");
		return ListaMedicos[m].begin()->second;
	}

	void atiendeConsulta(medico m) {
		//Si no existe el medico
		if (ListaMedicos.count(m) == 0) throw domain_error("Medico no existente");
		//!Cuidao
		if (ListaMedicos.at(m).empty()) throw domain_error("No hay pacientes");

		//Elimina la primera fecha del medico
		ListaMedicos[m].erase(ListaMedicos[m].begin());
	}

	vector<pair<paciente, fecha>>listaPacientes(medico m, fecha dia) {
		if (ListaMedicos.count(m) == 0)
			throw domain_error("Medico no existente");
		vector<pair<paciente, fecha>> aux;

		for (auto it : ListaMedicos[m]) {
			aux.push_back(pair<paciente, fecha>(it.second, dia));
		}

		return aux;
	}
};

int casos = 0;
bool resuelve() {

	int N;
	cin >> N;
	if (!cin) return false;

	string inst; medico med; paciente pac; int d, h, m; char c;
	Consultorio con;

	for (int i = 0; i < N; ++i) {
		try {
			cin >> inst;
			if (inst == "nuevoMedico") {
				cin >> med;
				con.nuevoMedico(med);
			}
			else if (inst == "pideConsulta") {
				cin >> pac >> med >> d >> h >> c >> m;
				con.pideConsulta(pac, med, fecha(d, h, m));
			}
			else if (inst == "siguientePaciente") {
				cin >> med;
				pac = con.siguientePaciente(med);
				cout << "Siguiente paciente doctor " << med << '\n';
				cout << pac << '\n';
			}
			else if (inst == "atiendeConsulta") {
				cin >> med;
				con.atiendeConsulta(med);
			}
			else if (inst == "listaPacientes") {
				cin >> med >> d;
				auto vec = con.listaPacientes(med, fecha(d, 0, 0));
				cout << "Doctor " << med << " dia " << d << '\n';
				for (auto p : vec) {
					cout << p.second << ' ' << p.first << '\n';
				}
			}
			else
				assert(false);
		}
		catch (invalid_argument e) { cout << e.what() << '\n'; }
	}
	cout << "---\n";

	return true;
}

int main() {
	while (resuelve());

	return 0;
}
