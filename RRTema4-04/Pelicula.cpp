#include "Pelicula.h"

std::istream& operator>>(std::istream& input, Pelicula& a)
{
	input >> a.fechaInicio;
	input >> a.duracion;
	std::getline(input, a.name);
	return input;
}

std::ostream& operator<<(std::ostream& output, const Pelicula& a)
{
	Date aux = a.fechaInicio + a.duracion;
	output << aux << " " << a.name << "\n";
	return output;
}

bool Pelicula::operator<(const Pelicula& a) const
{
	Date auxA, auxB;
	auxA = fechaInicio + duracion;
	auxB = a.fechaInicio + a.duracion;

	if (auxA < auxB) return true;
	if (auxA == auxB) {
		if (name < a.name) return true;
	}

	return false;
}

bool Pelicula::operator==(const Pelicula& a)
{

	if (fechaInicio + duracion == a.fechaInicio + a.duracion) return true;
	else if (name == a.name) return true;
	else return false;
}
