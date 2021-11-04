#include <iostream>
#include <ostream>
#include <string>


class Date {
public:
	Date();
	~Date();

	bool esValida() const;

	int dia;
	int mes;
	int anio;

	//Sobrecarga operadores cin c
	friend std::ostream& operator<<(std::ostream& out, const Date& d);
	friend std::istream& operator>>(std::istream& input, Date& d);
	bool operator<(const Date& b) const;
};
