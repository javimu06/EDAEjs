#include <iostream>
#include <iomanip>
#include <fstream>
#include "queue_eda.h"
using namespace std;


template <class T>
class queue_plus : public queue<T> {
	using Nodo = typename queue<T>::Nodo;

public:
	void cuela(const T& a, const T& b) {
		// Ojo que para acceder a prim o ult hay que escribir this->prim o this->ult
		Nodo* aPrim = this->busca(this->prim, a);
		Nodo* bPrim = nullptr;
		Nodo* cPrim = nullptr;
		if (aPrim != nullptr)
			bPrim = this->busca(aPrim->sig, b);
		if (bPrim != nullptr) {
			cPrim = this->buscaAnt(bPrim);

			if (bPrim->sig == nullptr)
				this->ult = cPrim;

			cPrim->sig = bPrim->sig;
			bPrim->sig = aPrim->sig;
			aPrim->sig = bPrim;	
		}
		/*	std::cout << aPrim->elem<<" ";
			std::cout << bPrim->elem << " ";
			std::cout << cPrim->elem << " ";
			std::cout <<  "\n";*/

	}
protected:
	Nodo* busca(Nodo* init, const T& a) {
		Nodo* aux = init;
		bool searching = true;
		while (searching && aux != nullptr) {
			if (aux->elem == a)
				searching = false;
			else
				aux = aux->sig;
		}
		if (searching)
			return nullptr;
		else
			return aux;
	}

	Nodo* buscaAnt(Nodo* b) {
		Nodo* aux = this->prim;
		bool searching = true;
		while (searching && aux != nullptr) {
			if (aux->sig == b)
				searching = false;
			else
				aux = aux->sig;
		}
		return aux;
	}
};


// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	int n, a, b;
	queue_plus<int> q;
	cin >> n;
	if (n == -1) return false;
	while (n != -1) {
		q.push(n);
		cin >> n;
	}
	cin >> a >> b;

	// llamada a metodo
	q.cuela(a, b);

	// escribir sol (pero antes dar una vuelta para comprobar que la cola está bien formada)
	for (int i = 0; i < q.size(); ++i) {
		n = q.front();
		q.pop();
		q.push(n);
	}
	// Ahora imprimimos la cola y de paso la dejamos vacía
	while (!q.empty()) {
		cout << q.front() << " ";
		q.pop();
	}
	cout << endl;
	return true;
}

//#define DOMJUDGE
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
	//system("PAUSE");
#endif

	return 0;
}
