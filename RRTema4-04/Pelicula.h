#pragma once
#include "Date.h"
#include <istream>
#include <ostream>
#include <string>

class Pelicula
{
public:
	Pelicula() {};
	~Pelicula() {};


	friend std::istream& operator>>(std::istream& input, Pelicula& a);
	friend std::ostream& operator<<(std::ostream& output, const Pelicula& a);
	bool operator<(const Pelicula& a)const;
	bool operator==(const Pelicula& a);

	std::string name;

	Date fechaInicio;
	Date duracion;
};

