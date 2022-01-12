// Javier Muñoz Martin de la Sierra
// VJ39


#include <iostream>
#include <iomanip>
#include <fstream>

#include <vector>


// función que resuelve el problema
int resolver(const std::vector<int>& numeros, int init, int end) {
	if (end - init <= 1)
		return init;
	if (end - init <= 2) {
		if (numeros[init] == numeros[init + 1])
			return end;
		else if (numeros[init + 1] == numeros[end])
			return init;
		else return init + 1;
	}
	else {
		//Da 0 si sale par, 1 si sale impar
		if (((init + end) / 2) % 2) {
			//IMPAR (conjuntos de 3, 7...)
			//Si es igual a la siguiente se va a la izquierda
			if (numeros[(init + end) / 2] == numeros[(init + end) / 2 + 1])
				return resolver(numeros, init, (init + end) / 2);
			//Si es igual al de antes se va a la derecha
			else if (numeros[(init + end) / 2] == numeros[(init + end) / 2 - 1])
				return resolver(numeros, (init + end) / 2 + 1, end);
			//Si no es igual a ninguno es el
			else return numeros[(init + end) / 2];
		}
		else {
			//PAR (conjuntos de 5,9...)
			//Si es igual a la siguiente se va a la izquierda
			if (numeros[(init + end) / 2] == numeros[(init + end) / 2 + 1])
				return resolver(numeros, (init + end) / 2, end);
			//Si es igual al de antes se va a la derecha
			else if (numeros[(init + end) / 2] == numeros[(init + end) / 2 - 1])
				return resolver(numeros, init, (init + end) / 2);
			//Si no es igual a ninguno es el
			else return (init + end) / 2;
		}
	}

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
	// leer los datos de la entrada
	int n;
	std::cin >> n;
	std::vector<int> numeros(n);
	for (int i = 0; i < n; ++i) {
		std::cin >> numeros[i];
	}

	std::cout << resolver(numeros, 0, numeros.size() - 1) << "\n";
	// escribir sol


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
	system("PAUSE");
#endif

	return 0;
}

/*
10
1
3
3
1 2 2
5
1 1 2 9 9
5
1 2 2 9 9
5
1 1 2 2 9
7
3 5 5 9 9 11 11
7
3 3 5 9 9 11 11
7
3 3 5 5 9 11 11
7
3 3 5 5 9 9 11
7
1 3 3 5 5 9 9
*/