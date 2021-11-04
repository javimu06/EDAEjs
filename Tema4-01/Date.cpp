#include "Date.h"

Date::Date() {}

Date::~Date() {}



bool Date::esValida()const {
	return(Hora >= 0 && Hora <= 23) && (min >= 0 && min <= 59) && (seg >= 0 && seg <= 59);
}

bool Date::operator<(const Date& b) const
{
	if (Hora < b.Hora) {
		return true;
	}
	if (Hora == b.Hora && min < b.min) {
		return true;
	}
	if (Hora == b.Hora && min == b.min && seg <= b.seg) {
		return true;
	}
	//Si aqui no ha terminado el metodo, es porque la segunda fecha es anterior a la primera
	return false;
}


//Sobrecarga operadores cin cout
std::ostream& operator<<(std::ostream& out, const Date& d) {
	if (d.Hora < 10)
		out << "0";
	out << d.Hora << ":";
	if (d.min < 10)
		out << "0";
	out << d.min << ":";
	if (d.seg < 10)
		out << "0";
	out << d.seg << "\n";

	return out;
}
std::istream& operator>>(std::istream& input, Date& d) {
	char c = ':';
	input >> d.Hora >> c >> d.min >> c >> d.seg;
	return input;
}
