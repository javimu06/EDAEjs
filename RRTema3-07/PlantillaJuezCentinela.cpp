// Javier Muñoz Martin de la Sierra
// VJ39


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

bool esValidaFinal(std::vector<int>& nPiezas, std::vector<int>& sol, std::vector<int>& piezasColocadas, const int& pos) {
	// El numero de piezas rojas debe ser mayor que la suma de las piezas azules y verdes
	if (piezasColocadas[1] <= piezasColocadas[0] + piezasColocadas[2]) return false;
	else return true;
}

bool esValida(std::vector<int>& nPiezas, std::vector<int>& sol, std::vector<int>& piezasColocadas, const int& pos) {

	if (pos == 0) {
		//  siempre tienen en la parte inferior una pieza roja
		if (sol[pos] != 1) return false;
	}
	if (pos >= 1) {
		// nunca coloca dos piezas verdes juntas
		if (sol[pos] == sol[pos- 1] && sol[pos] == 2) return false;
		//el numero de piezas verdes supere al de piezas azules en ningun momento
		if (piezasColocadas[2] > piezasColocadas[0]) return false;
	}

	if (nPiezas[sol[pos]] < 0) return false;

	return true;
}

// función que resuelve el problema
void resolver(const int& nAltura, const int& piezasNum, std::vector<int>& nPiezas, std::vector<int>& sol, std::vector<int>& piezasColocadas, const int& pos, bool& resuelto) {

	for (int i = 0; i < piezasNum; ++i) {
		sol[pos] = i;
		piezasColocadas[sol[pos]]++;
		nPiezas[sol[pos]]--;
		if (esValida(nPiezas, sol, piezasColocadas, pos)) {
			if (pos == sol.size() - 1) {
				if (esValidaFinal(nPiezas, sol, piezasColocadas, pos)) {
					for (int i = 0; i < sol.size(); ++i) {
						std::string auxSol;
						switch (sol[i])
						{
						case 0:
							auxSol = "azul";
							break;
						case 1:
							auxSol = "rojo";
							break;
						case 2:
							auxSol = "verde";
							break;
						}
						std::cout << auxSol << " ";
						resuelto = true;
					}
					std::cout << "\n";
					piezasColocadas[sol[pos]]--;
					nPiezas[sol[pos]]++;
				}
				else {
					piezasColocadas[sol[pos]]--;
					nPiezas[sol[pos]]++;
				}
			}
			else {
				resolver(nAltura, piezasNum, nPiezas, sol, piezasColocadas, pos + 1, resuelto);
				piezasColocadas[sol[pos]]--;
				nPiezas[sol[pos]]++;
			}
		}
		else {
			piezasColocadas[sol[pos]]--;
			nPiezas[sol[pos]]++;
		}
	}
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	int nAltura = 0, nRojo = 0, nAzul = 0, nVerde = 0, piezasNum = 3;
	std::cin >> nAltura >> nRojo >> nAzul >> nVerde;
	if (nAltura == 0)
		return false;

	std::vector<int> nPiezas{ nRojo, nAzul,nVerde };
	std::vector<int> nPiezasColocadas(3);

	std::vector<int> sol(nAltura);
	std::vector<int> piezasColocadas(piezasNum);

	bool resuelto = false;
	resolver(nAltura, piezasNum, nPiezas, sol, piezasColocadas, 0, resuelto);
	if (!resuelto)
		std::cout << "SIN SOLUCION\n";
	std::cout << "\n";


	// escribir sol

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
	system("PAUSE");
#endif

	return 0;
}
