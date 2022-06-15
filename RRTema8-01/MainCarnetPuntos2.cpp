
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <unordered_map>

using namespace std;

class carnet_puntos {
private:
	using dni = std::string;
	using puntos = int;
	unordered_map<dni, puntos> Carnets_;
	vector<int> vectorPuntos;

public:
	carnet_puntos() :vectorPuntos(15 + 1, 0) {};

	void nuevo(std::string dni) {
		if (Carnets_.count(dni)) throw domain_error("Conductor duplicado");
		else {
			//Creo carnet con 15 puntos
			Carnets_[dni] = 15;
			vectorPuntos[15]++;
		}
	}

	void quitar(std::string dni, int puntos) {
		if (!Carnets_.count(dni)) throw domain_error("Conductor inexistente");
		else {
			//Actualizo vector puntos
			vectorPuntos[Carnets_[dni]]--;

			//Quito los puntos indicados, nunca son menores que 0
			Carnets_[dni] -= puntos;
			if (Carnets_[dni] < 0) Carnets_[dni] = 0;

			//Actualizo vector puntos
			vectorPuntos[Carnets_[dni]]++;
		}
	}

	int consultar(std::string dni) {
		if (!Carnets_.count(dni))throw domain_error("Conductor inexistente");
		else {
			//Devuelvo los puntos de ese dni
			return Carnets_[dni];
		}
	}

	int cuantos_con_puntos(int puntos) {
		if (puntos < 0 || puntos > 15) throw domain_error("Puntos no validos");
		else return vectorPuntos[puntos];
	}
};

bool resuelveCaso() {
	std::string orden, dni;
	int punt;
	std::cin >> orden;
	if (!std::cin)
		return false;

	carnet_puntos dgt;

	while (orden != "FIN") {
		try {
			if (orden == "nuevo") {
				cin >> dni;
				dgt.nuevo(dni);
			}
			else if (orden == "quitar") {
				cin >> dni >> punt;
				dgt.quitar(dni, punt);
			}
			/*else if (orden == "recuperar") {
				cin >> dni >> punt;
				dgt.recuperar(dni, punt);
			}*/
			else if (orden == "consultar") {
				cin >> dni;
				punt = dgt.consultar(dni);
				cout << "Puntos de " << dni << ": " << punt << '\n';
			}
			else if (orden == "cuantos_con_puntos") {
				cin >> punt;
				int cuantos = dgt.cuantos_con_puntos(punt);
				cout << "Con " << punt << " puntos hay " << cuantos << '\n';
			}
			/*else if (orden == "lista_por_puntos") {
				cin >> punt;
				auto const& lista = dgt.lista_por_puntos(punt);
				cout << "Tienen " << punt << " puntos:";
				for (auto const& dni : lista)
					cout << ' ' << dni;
				cout << '\n';
			}*/
			else
				cout << "OPERACION DESCONOCIDA\n";
		}
		catch (std::domain_error e) {
			std::cout << "ERROR: " << e.what() << '\n';
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
