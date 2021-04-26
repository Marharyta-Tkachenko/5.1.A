#include "Product.h"

Product::Product()
	: first(0), second(0)
{}

Product::Product(int x, double y) throw(invalid_argument)
{
	if (x < 0 || y < 0)
		throw invalid_argument("Argument is negative");

	this->first = x;
	this->second = y;
}

Product::Product(const Product& v)
{
	first = v.first;
	second = v.second;
}

void Product::SetFirst(int value) throw (invalid_argument)
{
	if (value <= 0)
		throw invalid_argument("Argument is negative");
	first = value;
}

void Product::SetSecond(double value) throw (MyException)
{
	if (value <= 0)
		throw MyException("Argument is negative");
	second = value;
}

Product& Product::operator = (const Product& r)
{
	first = r.first;
	second = r.second;
	return *this;
}

Product::operator string () const
{
	stringstream ss;
	ss << "first = " << first << endl;
	ss << "second = " << second << endl;
	return ss.str();
}

Product& Product::operator --() throw(MyDerivedException)
{
	--first;
	if (first == 0)
		throw new MyDerivedException();
	return *this;
}

Product& Product::operator ++()
{
	++first;
	return *this;
}

Product Product::operator --(int) throw(MyDerivedException)
{
	Product a(*this);
	first--;
	if (first == 0)
		throw MyDerivedException();
	return a;
}

Product Product::operator ++(int)
{
	Product a(*this);
	first++;
	return a;
}

ostream& operator <<(ostream& out, const Product& a)
{
	return out << a.first << ", " << a.second;
}

istream& operator >>(istream& in, Product& a) throw(invalid_argument)
{
	cout << "first = "; in >> a.first;
	cout << "second = "; in >> a.second;

	if (a.first < 0 || a.second < 0)
		throw invalid_argument("negative argument");

	return in;
}

double Product::Power()
{
	return first * second * 10;
}
