#include "Date.h"


Date::Date() {
	hora = 0;
	minuto = 0;
	segundo = 0;
}

Date::~Date() {}

std::ostream& operator<<(std::ostream& output, const Date& a) {
	if (a.hora < 10)
		output << "0";
	output << a.hora << ":";
	if (a.minuto < 10)
		output << "0";
	output << a.minuto << ":";
	if (a.segundo < 10)
		output << "0";
	output << a.segundo;

	return output;
};

std::istream& operator>>(std::istream& input, Date& a) {
	char c = ':';
	input >> a.hora >> c >> a.minuto >> c >> a.segundo;
	return input;
};

bool Date::operator<(const Date& a) const {
	if (hora < a.hora) return true;
	else if (hora == a.hora && minuto < a.minuto) return true;
	else if (hora == a.hora && minuto == a.minuto && segundo < a.segundo) return true;
	return false;
}
bool Date::operator==(const Date& a) const {

	if (hora == a.hora && minuto == a.minuto && segundo == a.segundo) return true;
	return false;
}

Date operator+(const Date& a, const Date& b)
{
	Date aux;

	aux.segundo += a.segundo + b.segundo;
	if (aux.segundo >= 60) {
		aux.minuto++;
		aux.segundo -= 60;
	}

	aux.minuto += a.minuto + b.minuto;
	if (aux.minuto >= 60) {
		aux.hora++;
		aux.minuto -= 60;
	}



	aux.hora += a.hora + b.hora;
	if (aux.hora >= 24)
		aux.hora -= 24;



	return aux;
}

void Date::operator+=(const Date& h)
{
	segundo += h.segundo;
	if (segundo > 59) {
		int extra = segundo / 60;
		segundo -= 60 * extra;
		minuto += extra;
	}
	minuto += h.minuto;
	if (minuto > 59) {
		int extra = minuto / 60;
		minuto -= 60 * extra;
		hora += extra;
	}
	hora += h.hora;
}

bool Date::esValida() const {
	return (hora >= 0 && hora <= 23) && (minuto >= 0 && minuto <= 59) && (segundo >= 0 && segundo <= 59);
}