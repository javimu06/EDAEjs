#include "Date.h"

Date::Date() {}

Date::~Date() {}



bool Date::esValida()const {
	return(dia >= 0 && dia <= 31) && (mes >= 0 && mes <= 11) && (anio >= 0);
}

bool Date::operator<(const Date& b) const
{
	if (anio < b.anio) {
		return true;
	}
	if (anio == b.anio && mes < b.mes) {
		return true;
	}
	if (anio == b.anio && mes == b.mes && dia <= b.dia) {
		return true;
	}
	//Si aqui no ha terminado el metodo, es porque la segunda fecha es anterior a la primera
	return false;
}


//Sobrecarga operadores cin cout
std::ostream& operator<<(std::ostream& out, const Date& d) {
	char caracter = '/';
	if (d.dia < 10)
		out << "0";
	out << d.dia << caracter;
	if (d.mes < 10)
		out << "0";
	out << d.mes << caracter;

	out << d.anio << "\n";

	return out;
}
std::istream& operator>>(std::istream& input, Date& d) {
	char c = '/';
	input >> d.dia >> c >> d.mes >> c >> d.anio;
	return input;
}
