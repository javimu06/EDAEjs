
/*
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
	
	
	

	*/