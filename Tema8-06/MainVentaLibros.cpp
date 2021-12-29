// Plantilla para el ejercicio de Venta de libros

#include <iostream>
#include <stdexcept>
#include <string>
#include <fstream>
#include <map>
#include <unordered_map>
#include <utility>
#include <list>

using namespace std;
using libro = string;
using ejemplares = int;
using ventas = int;

struct infoLibro {
	ejemplares ejemplares_;
	ventas ventas_;
	list<libro>::iterator it;
};

class VentaLibros {
private:
	unordered_map<libro, infoLibro> catalogo;
	map<ventas, list<libro>, greater<ventas>> listaTop;
public:
	void nuevoLibro(libro x, ejemplares n) {
		catalogo[x].ejemplares_ += n;
	}
	void comprar(libro x) {
		unordered_map<libro, infoLibro>::iterator it = catalogo.find(x);

		if (it == catalogo.cend())
			throw out_of_range("Libro no existente");

		if (it->second.ejemplares_ == 0)
			throw out_of_range("No hay ejemplares");

		//Actualizamos el mapa de ventas top
		if (it->second.ventas_ > 0)
			listaTop[it->second.ventas_].erase(it->second.it);

		it->second.ejemplares_--;
		it->second.ventas_++;

		//Actualizamos el mapa de ventas top
		listaTop[it->second.ventas_].push_front(x);
		it->second.it = listaTop[it->second.ventas_].begin();
	}

	bool estaLibro(libro x) {
		return catalogo.count(x);
	}

	void elimLibro(libro x) {
		//!No pongo las cosas a 0?
		auto it = catalogo.find(x);
		if (it != catalogo.cend()) {

			if (it->second.ventas_ > 0)
				listaTop[it->second.ventas_].erase(it->second.it);

			catalogo.erase(x);
		}
	}
	int numEjemplares(libro x) {
		auto it = catalogo.find(x);
		if (it != catalogo.cend()) {
			return it->second.ejemplares_;
		}
		else throw invalid_argument("Libro no existente");
	}

	list<libro> top10() {
		list<libro> aux;

		for (auto it = listaTop.begin(); it != listaTop.cend(); it++) {
			for (auto b = it->second.begin(); b != it->second.end(); b++) {
				if (aux.size() == 10)
					return aux;
				aux.push_back(*b);
			}
		}
		return aux;
	}
};

// Muestra el contenido de una lista
template <class T>
void mostrar(list<T> const& l) {
	for (auto const& e : l) {
		cout << "    " << e << '\n';
	}
}

bool resuelveCaso() {
	int numOp;

	cin >> numOp;
	if (!cin) return false;

	VentaLibros amazon;

	string operacion, titulo;

	for (int i = 0; i < numOp; ++i) {
		cin >> operacion;
		cin.ignore(1); // saltar blanco
		if (operacion == "nuevoLibro") {
			int unidades;
			cin >> unidades;
			cin.ignore(1);
			getline(cin, titulo);
			amazon.nuevoLibro(titulo, unidades);
		}
		else if (operacion == "comprar") {
			getline(cin, titulo);
			try {
				amazon.comprar(titulo);
			}
			catch (out_of_range const& e) {
				cout << e.what() << '\n';
			}
			catch (invalid_argument const& e) {
				cout << e.what() << '\n';
			}
		}
		else if (operacion == "estaLibro") {
			getline(cin, titulo);
			if (amazon.estaLibro(titulo)) {
				cout << "El libro " << titulo << " esta en el sistema\n";
			}
			else {
				cout << "No existe el libro " << titulo << " en el sistema\n";
			}
		}
		else if (operacion == "elimLibro") {
			getline(cin, titulo);
			amazon.elimLibro(titulo);
		}
		else if (operacion == "numEjemplares") {
			getline(cin, titulo);
			if (amazon.estaLibro(titulo)) {
				cout << "Existen " << amazon.numEjemplares(titulo) << " ejemplares del libro " << titulo << '\n';
			}
			else {
				cout << "No existe el libro " << titulo << " en el sistema\n";
			}
		}
		else if (operacion == "top10") {
			cout << "TOP10\n";
			mostrar(amazon.top10());
		}
	}
	// fin del caso
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
