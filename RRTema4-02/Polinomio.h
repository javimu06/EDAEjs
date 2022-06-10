#pragma once
#include <iostream>
#include <vector>
#include <math.h>

class Polinomio
{
public:
	Polinomio() {};
	~Polinomio() {};

	friend std::istream& operator>>(std::istream& input, Polinomio& a);
	int calculaValor(int a) const;

	std::vector<int> valores;
};

