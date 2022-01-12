// Javier Muñoz Martín de la Sierra
// VJ39


#include <iostream>
#include <iomanip>
#include <fstream>

#include <stack>
#include <string>


// función que resuelve el problema
bool resolver(std::stack<char>& caracteresAbre, char cierre) {
	if (caracteresAbre.empty()) return false;
	else if (caracteresAbre.top() == '(' && cierre != ')') {
		return false;
	}
	else if (caracteresAbre.top() == '{' && cierre != '}') {
		return false;
	}
	else if (caracteresAbre.top() == '[' && cierre != ']') {
		return false;
	}
	caracteresAbre.pop();
	return true;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	std::stack<char> caracteresAbre;
	std::string frase;
	std::getline(std::cin, frase);
	if (!std::cin) return false;
	bool aux = true;
	int i = 0;
	while (i < frase.size() && aux) {
		if (frase[i] == '{' || frase[i] == '(' || frase[i] == '[')
			caracteresAbre.push(frase[i]);
		if (frase[i] == '}' || frase[i] == ')' || frase[i] == ']')
			aux = resolver(caracteresAbre, frase[i]);
		++i;
	}
	if (aux && caracteresAbre.empty())
		std::cout << "SI\n";
	else
		std::cout << "NO\n";
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