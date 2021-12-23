
#include <iostream>
#include <string>
#include <vector>
#include <fstream>

#include <map>

using namespace std;

class carnet_puntos {
private:
	using DNI = string;
	using PUNTOS = int;
	using ListaCarnets = map<DNI, PUNTOS>;
	ListaCarnets listaCarnets_;
	vector<int> conPuntos;

public:
	carnet_puntos() : conPuntos(15 + 1, 0) {}

	void nuevo(string dni) {
		if (listaCarnets_.count(dni) == 0)
		{
			listaCarnets_[dni] = 15;
			conPuntos[15]++;
		}
		else throw domain_error("Conductor duplicado");
	}

	void quitar(string dni, int puntos) {
		if (listaCarnets_.count(dni) != 0) {
			conPuntos[listaCarnets_[dni]]--;
			listaCarnets_[dni] -= puntos;
			if (listaCarnets_[dni] < 0) listaCarnets_[dni] = 0;
			conPuntos[listaCarnets_[dni]]++;
		}
		else throw domain_error("Conductor inexistente");
	}

	int consultar(string dni) {
		if (listaCarnets_.count(dni) != 0) return listaCarnets_[dni];
		else throw domain_error("Conductor inexistente");
	}

	int cuantos_con_puntos(int puntos) {
		if (puntos >= 0 && puntos <= 15)
			return conPuntos[puntos];
		else throw domain_error("Puntos no validos");
	}
};


bool resuelveCaso() {
	carnet_puntos carnet;
	std::string operacion, dni;
	int puntos;

	std::cin >> operacion;
	if (!std::cin) return false;

	while (operacion != "FIN") {
		try {
			if (operacion == "nuevo") {
				std::cin >> dni;
				carnet.nuevo(dni);
			}
			else if (operacion == "cuantos_con_puntos") {
				std::cin >> puntos;
				int sol = carnet.cuantos_con_puntos(puntos);
				std::cout << "Con " << puntos << " puntos hay " << sol << "\n";
			}
			else if (operacion == "quitar") {
				std::cin >> dni >> puntos;
				carnet.quitar(dni, puntos);
			}
			else if (operacion == "consultar") {
				std::cin >> dni;
				int sol = carnet.consultar(dni);
				std::cout << "Puntos de " << dni << ": " << sol << "\n";
			}
		}
		catch (std::domain_error e) {
			std::cout << "ERROR: " << e.what() << "\n";
		}
		std::cin >> operacion;
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
