
/*
CLASES DE COMPLEJIDAD
O(1):		constante
	x = 4;
O(log n):	logaritmico
	Divide y venceras con un vector ordenado donde se hacia que lado tirar, se reducen los casos un poco mas que la mitad
O(n):		lineal
	Un for se recorre 1 vez para cada valor hasta n
	Divide y venceras en el peor de los casos, donde recorremos todos los casos hasta encontrar la solucion
	at -> listas, recorre toda la lista
	fact
O(n.log n)	cuasi-lineal
	sort
O(N^2)		cuadrático
	backtracking porque ves todas las posibilidades n*n
O(n^k)		exponencial
	No hemos visto ningun caso porque da timeLimit
O(n!)		factorial
	No hemos visto ningun caso porque da timeLimit









TEMA 1 DIVIDE Y VENCERAS
	Los algoritmos son busquedas binarias
-Pasar la recursion
	-Primer caso se pasa como init = 0; y end = .size()-1
	-Los casos recursuvos se pasan como
		-Izquierda: (init, (init + end) / 2)
		-Derecha:	((init + end) / 2 + 1, end)
-El caso base comprueba que (end - init < 1)
	Aunque puede haber casos base de 3 elementos, no solo de 1, o de más

TEMA 3 BACKTRACKING
-A la hora de hacer backtracking actualizar la pos con pos + 1, no pos++ ni ++pos
	ASI SI
	resolver(m, n, sol, usadas, pos + 1);
	ASI NO
	resolver(m, n, sol, usadas, pobbs++);
	resolver(m, n, sol, usadas, ++pos);

-A la hora de hacer marcaje tenemos que desmarcar despues de imprimir la solucion
	if (esValida(No  esta usada)) {
		if (casoFinal) {

			std::cout << solucion;
		}
		else {
			usada[i] = true;
			resolver(juguetes, nNinos, tipos, posicion + 1, sol, encontroSolucion, cantidad, satisfaccionJuguetes, satisf);
			usada[i] = false;
		}
	}

TEMA 5 TADS LINEALES
Para recoger una frase en un string hay que hacer:
	std::getline(std::cin, frase);		//Siendo frase un string

No se puede crear ni destruir memoria dinamica -> TRABAJAR CON NODOS


Pilas - STACK
	last in, first out. Es decir que se van apilando elementos y el ultimo que meto es el primero que saco.
Colas - QUEUE
	Se insertan elementos al final y se sacan los de alante
	Colas dobles: Se pueden insertar y sacar elementos por ambos extremos
Listas - LIST
	Heredan de las colas dobles y pueden definir puntos intermedios
	Comando at permite manejar iteradores creo



- !No hacer un for de dimension .size de algo que hago pop porque se va reduciendo el .size y no imprimo todo
-ITERADORES
	Borrar un iterador
	Es MUY IMPORTANTE acordarse de hacer it--; porque al borrar te devuelve el siguiente
		it = sol.erase(it);
		it--;


-EJERCICIOS DE NODOS
	Utilizar un nodo auxiliar para no modificar prim
		Nodo* ant = prim

	Borrar una cola
		colegas.nelems = 0;
		colegas.prim = nullptr;
		colegas.ult = nullptr;


TEMA 6 - ARBOLES
	Para comprobar que la raiz o el nodo no es nulo
		if (!nodo.empty())
	Para contar alturas, tenemos las alturas de cada camino, que NO PASO POR & para que cuando llegue al final de cada arbol se ponga a 0 despues
	Sin embargo maxAlturas si lo paso con & para guardarme el valor en todo el recorrido y sacar el resultante
		Tengo un max alturas
		int nAlturas = 0;
		int maxnAlturas = 0;
		cuentaAlturas(nAlturas,& maxnAlturas, tree);
		return maxnAlturas;

	Un numero es PRIMO si no es divisible entre ningun numero comprendido entre 1 y n/2

	Cuando la solucion se da en la raiz hay que hacerlo POR COJONES por debajo
	O mejor dicho cuando necesitas acceder a valores de sig->sig porque obviamente no puedes



TEMA 8 - APLICACIONES TADS
	nombreMap.count()		//para saber si ya existia el primer valor
	nombreMap[x]			//para acceder al segundo dato del map
	nombreMap.at(x)			//NO SIRVE PARA UNA PUTA MIERDA ADEMAS ES CARO DE COJONES SUS MUERTO
	-Excepciones
		throw domain_error("Fecha ocupada");

-COSTES
Operación			Lista desordenada			Lista ordenada basada en vectores
Constructora		O(1)						O(1)
insert				O(n)						O(n)
erase				O(n)						O(n)
contains			O(n)						O(log n)
at					O(n)						O(log n)
empty				O(1)						O(1)


Operación			Backtrackingc
Constructora		O(1)
insert				O(log n)
count				O(log n)
at					O(log n)
erase				O(log n)
empty				O(1)



ARBOLES
Operación					Complejidad
Constructor sin argumentos	O(1)
Constructor con argumentos	O(n)
left						O(n)
right						O(n)
root						O(1)
empty						O(1)
operator==					O(n)

*/