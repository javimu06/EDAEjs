// Javier Muñoz Martín de la Sierra
// VJ39


#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <stack>

// función que resuelve el problema
//Si el caracter de apertura y el de cierre coinciden en el mismo caracter, se estaria cerrando correctamente
//{[({}	-> bien
//{[(}	-> mal
bool resolver(std::stack<char>& pila, const char cierre) {
	if (pila.empty())
		return false;
	char apertura = pila.top();
	if (apertura == '(' && cierre == ')') {
		pila.pop();
	}
	else if (apertura == '[' && cierre == ']') {
		pila.pop();
	}
	else if (apertura == '{' && cierre == '}') {
		pila.pop();
	}
	else
		return false;

	return true;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	std::string linea;
	std::getline(std::cin, linea);
	if (!std::cin)
		return false;
	//Llenamos la pila con los caracteres que nos interesan
	std::stack<char> pila;
	bool solucion = true;
	//!Es importante poner && solucion
	for (long unsigned int i = 0; i < linea.size() && solucion; ++i) {
		//Diferenciamos entre inicio y fin de corchetes para comprobar cuando deberia haber terminado uno
		//En el caso de que haya terminado uno, queremos comprobar que coincide con 
		if (linea[i] == '(' || linea[i] == '{' || linea[i] == '[')
			pila.push(linea[i]);
		else if (linea[i] == ')' || linea[i] == '}' || linea[i] == ']') {
			solucion = resolver(pila, linea[i]);
		}

	}
	// escribir sol
	//Si solucion es true es porque se cerro correctamente la ultima iteracion
	//Si se hubiese resuelto bien todas las iteraciones, la pila deberia de estar vacia
	if (solucion && pila.empty())
		std::cout << "SI\n";
	else 
		std::cout << "NO\n";

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