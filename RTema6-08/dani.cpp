#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include "bintree_eda.h"
#include <climits>
using namespace std;

template<class T>
bool binarioBusqueda(bintree<T>arbol, int min, int max)
{
    //El arbol puede estar vacio o no tener hojas, en ambos caso el arbol es correcto
    if (arbol.empty())return true;
    else
    {
        //LLamadas recursivas para comprobar hijo izquierdo e hijo derecho 
        //A la izquierda actualizamos el maximo del que no se pude pasar
        //A la derecha actualizamos el minimo el cual debe superar    
            
        //Se utiliza minimo y maximo para la recursividad en cuanto a los casos anteriores
        bool izqCorrecto = binarioBusqueda(arbol.left(), min, arbol.root());
        bool dchaCorrecto = binarioBusqueda(arbol.right(), arbol.root(), max);
        if (izqCorrecto && dchaCorrecto) //Comprobacion recursivade los casos anteriores 
        {
            //Tenemos que valorar que solo tenga el hijo izquierdo , el hijo derecho o ambos hijos
            if (arbol.left().empty() && arbol.right().empty())return true;
            else if (arbol.left().empty() && !arbol.right().empty())
            {
                if (arbol.root() < arbol.right().root() && arbol.right().root() < max)return true;
                else return false;
            }
            else if (arbol.right().empty() && !arbol.left().empty())
            {

                if (arbol.root() > arbol.left().root() && arbol.left().root() > min)return true;
                else return false;
            }
            else
            {
                if ((arbol.root() > arbol.left().root() && 
                    arbol.left().root() > min) && 
                    (arbol.root() < arbol.right().root() && 
                    arbol.right().root() < max))
                    return true;
                else return false;
            }
        }
        else return false;

    }

}
void resuelveCaso() {
    // leer los datos de la entrada
    bintree<int>arbol;
    arbol = leerArbol(-1);
    int min = 0;
    int max = INT_MAX;
    bool esCorrecto = binarioBusqueda(arbol, min, max);
    if (esCorrecto)cout << "SI" << endl;
    else cout << "NO" << endl;

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