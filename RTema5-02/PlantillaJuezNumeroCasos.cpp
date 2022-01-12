// Javier Muñoz Martin de la Sierra
// VJ39


#include <iostream>
#include <iomanip>
#include <fstream>

#include <stack>

//ESTA LITERALMENTE IGUAL QUE EL TEMA5-02 AUNQUE NO DA CORRECT PORQUE NO LE SALE DE LA POLLA

struct Fecha {
	int dia;
	int mes;
	int anyo;
};
using Muertes = int;
using Accidente = std::pair<Muertes, Fecha>;

//función que resuelve el problema
void resolver(std::stack<Accidente>& accidentes_) {
	if (accidentes_.empty())
		std::cout << "NO HAY\n";
	else {
		Accidente accidente = accidentes_.top();

		while (!accidentes_.empty() && accidente.first >= accidentes_.top().first)
			accidentes_.pop();

		//Si encontramos un accidente con mas muertes
		if (!accidentes_.empty())
			std::cout << accidentes_.top().second.dia << "/" << accidentes_.top().second.mes << "/" << accidentes_.top().second.anyo << "\n";
		else
			std::cout << "NO HAY\n";
		
		accidentes_.push(accidente);
	}
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	int numCasos;
	std::cin >> numCasos;
	if (!std::cin)
		return false;

	std::stack<Accidente> accidentes;

	for (int i = 0; i < numCasos; ++i) {
		Accidente accidente;
		char a;
		// leer los datos de la entrada
		std::cin >> accidente.second.dia >> a >> accidente.second.mes >> a >> accidente.second.anyo >> accidente.first;
		accidentes.push(accidente);

		// escribir sol
		resolver(accidentes);
	}
	std::cout << "---\n";
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