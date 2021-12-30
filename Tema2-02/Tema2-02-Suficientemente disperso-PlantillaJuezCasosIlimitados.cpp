// Javier Muñoz Martín de la Sierra
// VJ39


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>



// función que resuelve el problema
bool resolver(const std::vector<int>& datos, const int& init, const int& end, const int& disp) {
	//CASO BASE PARA FINALIZAR LA RECURSION
	if (init == end - 1) return true;

	//Calculamos la dispersion
	int auxDisp = std::abs(datos[end - 1] - datos[init]);

	if (auxDisp >= disp)
	{
		//Si la dispersion es suficiente recurrimos el metodo
		return(resolver(datos, init, (init + end) / 2, disp) && resolver(datos, (init + end) / 2, end, disp));
	}
	else
		return false;	//La dispersion no es suficiente
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada

	int nElems, dispersion;
	std::cin >> nElems >> dispersion;

	if (!std::cin)
		return false;

	std::vector<int> serie(nElems, 0);
	for (int i = 0; i < nElems; i++)
		std::cin >> serie[i];

	//Solucion de la serie
	bool sol = resolver(serie, 0, serie.size(), dispersion);

	// escribir sol
	if (sol)std::cout << "SI\n";
	else std::cout << "NO\n";

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