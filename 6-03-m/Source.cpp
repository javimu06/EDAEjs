
#include <iostream>
#include <iomanip>
#include <fstream>
#include "bintree.h"
using namespace std;



// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    string numCasos;
    cin >> numCasos;
    if (!std::cin)
        return false;
    if (numCasos == "P") {
        bintree<string> tree;
        string h = "#";
        tree = leerArbol(h);
        if(!tree.empty())
        cout << tree.menor();
       
    }
    else {
        bintree<int> tree;
        tree = leerArbol(-1);
        if (!tree.empty())
            cout << tree.menor();
        else cout << "0";
    }
    cout << endl;
   
  
   
}


int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("datos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif

  
    while (resuelveCaso())
        ;

    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    //system("PAUSE");
#endif

    return 0;
}
