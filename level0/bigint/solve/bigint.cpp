# include <boost/multiprecision/cpp_int.hpp>
# include "bigint.hpp"

bigint::bigint() : a(0) {}

//bigint::bigint(int n) : a(n) {}

//bigint::bigint(const cpp_int& n) : a(n) {}

//bigint::bigint(const bigint& other) : a(other.a) {}

bigint::~bigint() {}

//bigint::operator cpp_int() const {return a;}


bigint& bigint::operator=(const bigint& other)
{
	a = other.a;
	return *this;
}
bigint& bigint::operator+=(const bigint& other) 
{
	a += other.a;
	return *this;
}

bigint bigint::operator+(const bigint& other) const { return bigint(a + other.a);}

bigint& bigint::operator++()
{
	++a;
	return *this;
}
bigint bigint::operator++(int)
{
	return bigint(a++);
}


bigint& bigint::operator<<=(const bigint & other) 
{
	bigint i(0);
	while(i < other)
	{
		a*= 10;
		i++;
	}
	return *this;
}
bigint& bigint::operator>>=(const bigint & other)
{
	bigint i(0);
	while(i < other)
	{
		a/= 10;
		i++;
	}
	return *this;
}

bigint bigint::operator<<(const bigint & other) const { return bigint(*this) <<= other;}
bigint bigint::operator>>(const bigint & other) const { return bigint(*this) >>= other;}

bool bigint::operator==(const bigint& other) const {return a == other.a;}
bool bigint::operator!=(const bigint& other) const {return a != other.a;}
bool bigint::operator<=(const bigint& other) const {return a <=other.a;}
bool bigint::operator>=(const bigint& other) const {return a >=other.a;}
bool bigint::operator>(const bigint& other) const {return a >other.a;}
bool bigint::operator<(const bigint& other) const {return a <other.a;}
