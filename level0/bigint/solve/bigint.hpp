# include <boost/multiprecision/cpp_int.hpp>
# include <iostream>

using boost::multiprecision::cpp_int;


class bigint
{
	cpp_int a;

	public: 
	bigint();
	template <typename T>
	bigint(const T & n) : a(n)
	{
	
	};
	~bigint();

	operator cpp_int() const;

	bigint& operator=(const bigint& other);
	bigint& operator<<=(const bigint & other);
	bigint& operator>>=(const bigint & other);
	bigint& operator+=(const bigint& other);
	bigint& operator++();

	bigint operator++(int);

	bigint operator+(const bigint& other) const;
	bigint operator<<(const bigint & other)const;
	bigint operator>>(const bigint & other)const;

	bool operator==(const bigint& other)const;
	bool operator!=(const bigint& other)const;
	bool operator<=(const bigint & other)const;
	bool operator>=(const bigint & other)const;
	bool operator>(const bigint & other)const;
	bool operator<(const bigint & other)const;

	friend std::ostream& operator<<(std::ostream& os,const bigint& other)
	{
		return os << other.a;
	}
};

