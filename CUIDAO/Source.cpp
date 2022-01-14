
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
O(N^2)		cuadr�tico
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
	Aunque puede haber casos base de 3 elementos, no solo de 1, o de m�s

TEMA 3 BACKTRACKING
-A la hora de hacer backtracking actualizar la pos con pos + 1, no pos++ ni ++pos
	ASI SI
	resolver(m, n, sol, usadas, pos + 1);
	ASI NO
	resolver(m, n, sol, usadas, pos++);
	resolver(m, n, sol, usadas, ++pos);

-A la hora de hacer marcaje tenemos que desmarcar despues de imprimir la solucion
	if (esValida()) {
		if (casoFinal) {

			std::cout << solucion;
			cantidad[i]++;
		}
		else {
			resolver(juguetes, nNinos, tipos, posicion + 1, sol, encontroSolucion, cantidad, satisfaccionJuguetes, satisf);
			cantidad[i]++;
		}
	}

TEMA 5 TADS LINEALES
Para recoger una frase en un string hay que hacer:
	std::getline(std::cin, frase);		//Siendo frase un string

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

-COSTES
Operaci�n			Lista desordenada			Lista ordenada basada en vectores
Constructora		O(1)						O(1)
insert				O(n)						O(n)
erase				O(n)						O(n)
contains			O(n)						O(log n)
at					O(n)						O(log n)
empty				O(1)						O(1)


Operaci�n			�rboles de b�squeda
Constructora		O(1)
insert				O(log n)
count				O(log n)
at					O(log n)
erase				O(log n)
empty				O(1)



*/