
#include <iostream>
#include <iomanip>
#include <fstream>
#include "bintree_eda.h"
using namespace std;

//Comprueba recursivamente si los nodos izquierdos y derechos son simetricos
// En caso de que sean iguales y no vacios, pasa el caso recursivo a los siguientes
bool compruebaSimetria(bintree<char> const& izq, bintree<char> const& dr) {
	//Si los dos son vacios, devuelvo true porque son simetricos
	if (izq.empty() && dr.empty())
		return true;
	//Si uno es vacio y el otro no, no son simetricos
	else if (!izq.empty() && dr.empty() || izq.empty() && !dr.empty())
		return false;
	//Si ninguno es vacio, pasamos el caso recursivo para comprobar si sus hijos son o no simetricos
	else //if(!izq.empty() && !dr.empty())
	{
		return compruebaSimetria(izq.left(), dr.right()) && compruebaSimetria(izq.right(), dr.left());
	}
}

//Determina si desde la raiz, ambos lados del arbol son simetricos
bool simetrico(bintree<char> const& nodo) {
	if (nodo.empty())
		return true;
	else
		return compruebaSimetria(nodo.left(), nodo.right());
}


// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
	// leer los datos de la entrada
	int n;
	bintree<char> tree;
	tree = leerArbol('.');
	if (simetrico(tree))
		std::cout << "SI\n";
	else
		std::cout << "NO\n";

}


int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
#ifndef DOMJUDGE
	std::ifstream in("datos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif

	int numCasos;
	std::cin >> numCasos;
	for (int i = 0; i < numCasos; ++i)
		resuelveCaso();

	// Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	//system("PAUSE");
#endif

	return 0;
}
