
#include <iostream>
#include <string>
#include <vector>
#include <fstream>

#include <unordered_map>

using namespace std;

class carnet_puntos {
private:
	using Puntos = int;
	using DNI = string;
	unordered_map<DNI, Puntos> carnets;
	vector<int> conPuntos;
public:
	carnet_puntos() : conPuntos(16, 0) {}
	void nuevo(DNI dni) {
		if (carnets.count(dni) > 0) throw std::domain_error("Conductor duplicado");
		else carnets[dni] = 15;
		conPuntos[15]++;
	}

	void quitar(DNI dni, Puntos puntos) {
		if (carnets.count(dni) == 0) throw std::domain_error("Conductor inexistente");
		conPuntos[carnets[dni]]--;
		carnets[dni] -= puntos;
		if (carnets[dni] < 0) carnets[dni] = 0;
		conPuntos[carnets[dni]]++;
	}

	int consultar(DNI dni) {
		if (carnets.count(dni) == 0)throw std::domain_error("Conductor inexistente");
		return carnets[dni];
	}

	int cuantos_con_puntos(Puntos puntos) {
		if (puntos < 0 || puntos > 15) throw domain_error("Puntos no validos");
		return conPuntos[puntos];
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
