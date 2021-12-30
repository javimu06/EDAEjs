//Javier Muñoz Martin de la Sierra
//VJ39

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;


bool anagramas(const string& cad1, const string& cad2) {
	//Las palabras tienen que tener la misma cantidad de letras
	if (cad1.size() != cad2.size()) return false;

	//Booleano se encarga de no repetir una letra que ya se ha encontrado
	vector<bool> find(cad1.size(), false);
	//Int se encarga de ver si todas las letras de la segunda palabra estaban contenidas en la primera
	int lettersFounded = 0;

	//Recorremos de una en una las letras de la primera palabra y lo comparamos con todas las de la segunda si no han sido encontradas
	for (int i = 0; i < cad1.size(); i++){
		//Hacemos una busqueda y cuando encontremos la letra coincidente salimos del while para comenzar a buscar otra letra de la primera palabra
		bool searching = true;
		int j = 0;
		while (j < cad2.size() && searching){
			if (!find[j] && cad1[i] == cad2[j]){
				searching = false;
				find[j] = true;
				lettersFounded++;
			}
			j++;
		}
	}

	//Comprobamos si todas las letras se encontraban en la segunda palabra sin repetirse
	if (lettersFounded == cad1.size())
		return true;
	else
		return false;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
	// leer los datos de la entrada
	string word1, word2;
	cin >> word1 >> word2;
	cout << (anagramas(word1, word2) ? "SI" : "NO") << endl;
}

//#define DOMJUDGE
int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
#ifndef DOMJUDGE
	//std::ifstream in("datos.txt");
	//auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif

	int numCasos = 1;
	std::cin >> numCasos;
	for (int i = 0; i < numCasos; ++i)
		resuelveCaso();

	// Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	//std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}