#include "Polinomio.h"

std::istream& operator>>(std::istream& input, Polinomio& a) {
	int coef, exp;
	input >> coef >> exp;

	if (!std::cin)
		return input;

	while (coef != 0 || exp != 0) {
		bool contenido = false;
		for (int i = 0; i < a.valores.size(); ++i) {
			if (i % 2) {
				if (a.valores[i] == exp) {
					a.valores[i - 1] += coef;
					contenido = true;
				}
			}
		}

		if (!contenido) {
			a.valores.push_back(coef);
			a.valores.push_back(exp);
		}
		input >> coef >> exp;
	}
	return input;
}

int Polinomio::calculaValor(int a) const {
	int valor = 0;
	for (int i = 0; i < valores.size() - 1; ++i) {
		if (i % 2 == 0) {
			valor += valores[i] * pow(a, valores[i + 1]);
		}
	}
	return valor;
}