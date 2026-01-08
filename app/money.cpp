#include "money.h"
#include <iostream>
#include <ostream>



namespace vsite::oop::v7
{
	money& money::operator-=(const money& other) {
		total_cents -= other.total_cents;
		return *this;
	}

	money& money::operator+=(const money& other) {
		total_cents += other.total_cents;
		return *this;
	}


	std::ostream& operator << (std::ostream& os, const money& other) {
		int euro; int cents;
		euro = other.total_cents / 100;
		cents = other.total_cents % 100;
		if (cents == 0) {
			os << euro << " eur";
			return os;
		}
		else if (euro == 0)
		{

			if (cents < 10)
				os << "0" << cents << " ct";
			else
				os << cents << " ct";
			return os;
		}
		else {
			if (cents < 10)
				os << euro << " eur, " << "0" << cents << " ct";
			else
				os << euro << " eur, " << cents << " ct";
			return os;
		}
	}

	std::istream& operator>>(std::istream& is, money& other) {
		int euros, cents;
		is >> euros >> cents;
		other.total_cents = euros * 100 + cents;
		return is;
	}


	money::money(int euro, int cents) {
		total_cents = euro * 100 + cents;
	}

	int money::get_total_cents() const {
		return total_cents;
	}
}