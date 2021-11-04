// Javier Muñoz Martin de la Sierra
// VJ39


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>


// función que resuelve el problema
/*
Vamos contando numeros de 2 en 2, sumamos las dos primeras posiciones y las dividimos entre 2, comprobamos si este resultado coincide con el
primer operando, que debería si los numeros sumados son iguales.
En el caso recursivo pasamos la i cuando buscamos hacia la derecha, ya que si pasasemos la mitad no estariamos contando bien en determinados
casos y perderiamos la propiedad de contar numeros de 2 en 2.
Pasar la i es muy importante, si no saldrian mal todos los casos que tienen el numero a encontrar en la ultima posicion
3 3 5 5 9 9 11
si pasasemos la mitad, se acabaria haciendo (9+11)/2, dando como solucion la posicion de ese 9, en vez de comprobar que solo nos quedaba
1 numero por sumar, y al ser solo 1 se llega al caso base y se devuelve la solucion
*/
int resolver(const std::vector<int>& arr, int init, int fin) {
	if (fin - init == 1)
		return init;

	bool searching = true;
	int i = init;
	while (i < (init + fin) / 2 && searching) {
		// Si encontramos que en algun momento, el primer numero mas el siguiente entre 2 es diferente del primer numero, significa que 
		// los dos numeros no son iguales, y por logica el primero es el que falla
		if ((float)(arr[i] + arr[i + 1]) / 2 != arr[i]) searching = false;
		i += 2;
	}

	if (searching)
		return resolver(arr, i, fin);
	else
		return resolver(arr, init, (init + fin) / 2);

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
	// leer los datos de la entrada
	int nElems;
	std::cin >> nElems;

	std::vector<int> arrayElems(nElems);
	for (int i = 0; i < nElems; i++)
		std::cin >> arrayElems[i];

	int sol = resolver(arrayElems, 0, arrayElems.size());
	// escribir sol
	std::cout << sol << "\n";

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