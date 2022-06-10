#pragma once
#include <iostream>
#include <ostream>
#include <iomanip>
#include <fstream>
#include <string>

class Date
{
public:
	Date();
	~Date();

	friend std::ostream& operator<<(std::ostream& output, const Date& a);
	friend std::istream& operator>>(std::istream& input, Date& a);
	bool operator<(const Date& a)const;
	bool operator==(const Date& a)const;
	friend Date operator+(const Date& a,const Date& b);
	void operator+=(const Date& h);

	bool esValida() const;

	int hora;
	int minuto;
	int segundo;
};

