// Javier Muñoz Martín de la Sierra
// VJ39


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>



// función recursiva que resuelve el problema
bool resolver(const std::vector<int>& datos, int Initsize, int Endsize) {
	//Si initSize == endSize es porque el vector de datos tiene tamaño 1
	if (Initsize == Endsize - 1)
		return true;

	int minimo = datos[Initsize];
	int maximoIzq = datos[Initsize];

	//Recorremos la primera mitad del vector para encontrar el numero más pequeño
	for (int i = Initsize; i < (Initsize + Endsize) / 2; i++) {
		//Actualizas valores maximos y minimos de la izquierda
		if (minimo > datos[i])minimo = datos[i];
		if (maximoIzq < datos[i])maximoIzq = datos[i];
	}

	//Buscamos en la segunda mitad del vector el número más alto
	int i = (Initsize + Endsize) / 2;
	bool searching = true;
	int maximoDer = datos[Endsize - 1];
	while (i < Endsize && searching) {
		if (maximoDer < datos[i]) maximoDer = datos[i];
		if (minimo > datos[i]) searching = false;	//Hay un numero en la parte derecha que es menor al minimo de la izquierda, no hay orden
		i++;
	}

	if (searching && maximoDer >= maximoIzq)
		return (resolver(datos, Initsize, (Initsize + Endsize) / 2) && resolver(datos, (Initsize + Endsize) / 2, Endsize));
	else
		return false;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	int num = 1;
	std::vector<int> inputVector;
	while (num != 0) {
		std::cin >> num;
		if (num != 0)
			inputVector.push_back(num);
	}

	//Si el vector está vacío(se intentó introducir un 0 al principio) salimos
	if (inputVector.size() == 0)
		return false;

	// escribir sol, el metodo resolver se llamara recursivamente hasta que devuelva una solucion que se devuelve aqui
	// Al principio quiero que resolver me cubra el size del vector
	bool sol = resolver(inputVector, 0, inputVector.size());
	if (sol)
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