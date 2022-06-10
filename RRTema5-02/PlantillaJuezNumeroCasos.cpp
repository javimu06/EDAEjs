// Javier Muñoz Martin de la Sierra
// VJ39


#include <iostream>
#include <istream>
#include <iomanip>
#include <fstream>
#include <stack>

class Date {
public:
	Date() {};
	~Date() {};

	friend std::istream& operator>>(std::istream& input, Date& date) {
		char aux = '/';
		input >> date.dia >> aux >> date.mes >> aux >> date.anyo;
		return input;
	}

	friend std::ostream& operator<<(std::ostream& output, const Date& date) {
		char aux = '/';

		if (date.dia < 10)
			output << '0' << date.dia<<aux;
		else
			output << date.dia << aux;

		if (date.mes < 10)
			output << '0' << date.mes << aux;
		else
			output << date.mes << aux;


		if (date.anyo < 1000)
			output << '0' << date.anyo;
		else
			output << date.anyo;

		return output;
	}

	int dia;
	int mes;
	int anyo;

};

struct Accidente
{
	Date fecha;
	int muertes;

};

// función que resuelve el problema
void resolver(std::stack<Accidente>& accidentes, const Accidente& ultimoAccidente) {
	if (!accidentes.empty()) {
		bool finded = false;
		while (!finded) {
			if (!accidentes.empty() && accidentes.top().muertes <= ultimoAccidente.muertes) accidentes.pop();
			else {
				if (accidentes.empty())
					std::cout << "NO HAY\n";
				else
					std::cout << accidentes.top().fecha << "\n";
				finded = true;
				accidentes.push(ultimoAccidente);
			}
		}
	}
	else {
		accidentes.push(ultimoAccidente);
		std::cout << "NO HAY\n";
	}
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	int nAccidentes;
	std::cin >> nAccidentes;
	if (!std::cin)
		return false;

	std::stack<Accidente> accidentes;

	for (int i = 0; i < nAccidentes; ++i) {
		Date fechaAux; int muertesAux;
		std::cin >> fechaAux >> muertesAux;
		Accidente ultimoAccidente;
		ultimoAccidente.fecha = fechaAux;
		ultimoAccidente.muertes = muertesAux;

		resolver(accidentes, ultimoAccidente);
	}

	// escribir sol
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