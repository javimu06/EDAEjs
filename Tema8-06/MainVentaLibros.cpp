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
		if (catalogo.count(x) == 0)
			throw out_of_range("Libro no existente");

		if (catalogo[x].ejemplares_ == 0)
			throw out_of_range("No hay ejemplares");

		//Actualizamos el mapa de ventas top
		if (catalogo[x].ventas_ > 0)
			listaTop[catalogo[x].ventas_].erase(catalogo[x].it);

		catalogo[x].ejemplares_--;
		catalogo[x].ventas_++;

		//Actualizamos el mapa de ventas top
		listaTop[catalogo[x].ventas_].push_front(x);
		catalogo[x].it = listaTop[catalogo[x].ventas_].begin();
	}

	bool estaLibro(libro x) {
		return catalogo.count(x);
	}

	void elimLibro(libro x) {
		//!No pongo las cosas a 0?
		if (catalogo.count(x)) {

			if (catalogo[x].ventas_ > 0)
				listaTop[catalogo[x].ventas_].erase(catalogo[x].it);

			catalogo.erase(x);
		}
	}
	int numEjemplares(libro x) {
		if (catalogo.count(x)) {
			return catalogo[x].ejemplares_;
		}
		else throw invalid_argument("Libro no existente");
	}

	list<libro> top10() {
		list<libro> aux;

		for (auto a : listaTop) {
			for (auto b = a.second.begin(); b != a.second.end(); b++) {
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
