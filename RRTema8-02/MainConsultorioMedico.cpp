// Plantilla para el ejercicio del Consultorio Médico

#include <iomanip>
#include <iostream>
#include <string>
#include <stdexcept>
#include <cassert>

#include <fstream>

#include <unordered_map>
#include <map>
using namespace std;
using medico = std::string;
using paciente = std::string;

class fecha {
public:
	fecha(int d, int h, int m) {
		dia = d;
		hora = h;
		minuto = m;
	}

	int getDia()const { return dia; }
	int getHora()const { return hora; }
	int getMinuto()const { return minuto; }

	friend ostream& operator<< (ostream& output, fecha f) {
		int hora = f.getHora();
		string h;
		int minuto = f.getMinuto();
		string m;
		if (hora < 10)
			h = "0" + to_string(hora);
		else
			h = to_string(hora);

		if (minuto < 10)
			m = "0" + to_string(minuto);
		else
			m = to_string(minuto);

		output << h << ":" << m;
		return output;
	};
private:
	int dia;
	int hora;
	int minuto;

};


bool operator == (const fecha& A, const fecha& B) {
	return A.getDia() == B.getDia() && A.getHora() == B.getHora() && A.getMinuto() == B.getMinuto();
}

bool operator<(const fecha& A, const fecha& B) {
	if (A.getDia() < B.getDia()) return true;
	else if ((A.getDia() == B.getDia()) && A.getHora() < B.getHora()) return true;
	else if (A.getDia() == B.getDia() && A.getHora() == B.getHora() && A.getMinuto() < B.getMinuto()) return true;
	return false;
}

class Consultorio {
private:
	unordered_map<medico, map<fecha, paciente>> ListaMedicos_;

public:
	void nuevoMedico(medico m) {
		if (!ListaMedicos_.count(m)) {
			ListaMedicos_[m];
		}
	}

	void pideConsulta(paciente p, medico m, fecha f) {
		if (!ListaMedicos_.count(m))throw domain_error("Medico no existente");
		else {
			auto it = ListaMedicos_[m].find(f);
			if (it != ListaMedicos_[m].cend()) throw domain_error("Fecha ocupada");
			else {
				ListaMedicos_[m][f] = p;
			}
		}
	}

	paciente siguientePaciente(medico m) {
		if (!ListaMedicos_.count(m)) throw domain_error("Medico no existente");
		else if (!ListaMedicos_[m].size()) throw domain_error("No hay pacientes");
		else {
			auto it = ListaMedicos_[m].begin();
			return ListaMedicos_[m][it->first];
		}
		return nullptr;
	}

	void atiendeConsulta(medico m) {
		if (!ListaMedicos_.count(m)) throw domain_error("Medico no existente");
		else if (!ListaMedicos_[m].size())throw domain_error("No hay pacientes");
		else {
			auto it = ListaMedicos_[m].begin();
			ListaMedicos_[m].erase(it);
		}
	}

	map<fecha, paciente> listaPacientes(medico m, fecha f) {
		map<fecha, paciente> lista;
		if (!ListaMedicos_.count(m)) throw domain_error("Medico no existente");
		else {
			auto it = ListaMedicos_[m].begin();
			while (it != ListaMedicos_[m].end()) {
				if (it->first.getDia() == f.getDia())
					lista.insert(*it);
				++it;
			}
		}
		return lista;
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
		catch (std::domain_error e) {
			std::cout << e.what() << '\n';
		}
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
