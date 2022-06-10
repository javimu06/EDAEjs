#include "Date.h"


Date::Date() {}

Date::~Date() {}

std::ostream& operator<<(std::ostream& output, const Date& a) {
	if (a.hora < 10)
		output << "0";
	output << a.hora << ":";
	if (a.minuto < 10)
		output << "0";
	output << a.minuto << ":";
	if (a.segundo< 10)
		output << "0";
	output << a.segundo << "\n";

	return output;
};

std::istream& operator>>(std::istream& input, Date& a) {
	char c = ':';
	input >> a.hora >> c >> a.minuto >> c >> a.segundo;
	return input;
};

bool Date::operator<(const Date& a) const{
	if (hora < a.hora) return true;
	else if (hora == a.hora && minuto < a.minuto) return true;
	else if (hora == a.hora && minuto == a.minuto && segundo <= a.segundo) return true;
	return false;
}

bool Date::esValida() const {
	return (hora >= 0 && hora <= 23) && (minuto >= 0 && minuto <= 59) && (segundo >= 0 && segundo <= 59);
}