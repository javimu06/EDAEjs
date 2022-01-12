// Javier Muñoz Martín de la Sierra
// VJ39


#include <iostream>
#include <iomanip>
#include <fstream>

#include <vector>


// función que resuelve el problema
int resolver(const std::vector<int>& curva, int init, int end, int minimo) {
	//Caso base
	if (end - init < 1)
		return minimo;
	else {
		//Actualizar caso minimo
		if (curva[end] < minimo)
			minimo = curva[end];
		if (curva[init] < minimo)
			minimo = curva[init];
		//Caso recursivo
		if (curva[(init + end) / 2] < curva[(init + end) / 2 + 1])
			//Si el de la derecha del centro es mayor, vamos a la izquierda
			return resolver(curva, init, (init + end) / 2, minimo);
		//Si el de la derecha del centro es menor, vamos a la derecha
		else
			return resolver(curva, (init + end) / 2 + 1, end, minimo);
	}
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	int x, n;
	std::cin >> n;

	if (!std::cin)
		return false;

	std::vector<int> curva(n);
	for (int i = 0; i < n; ++i) {
		std::cin >> x;
		curva[i] = x;
	}

	std::cout << resolver(curva, 0, curva.size() - 1, curva[0]) << "\n";
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