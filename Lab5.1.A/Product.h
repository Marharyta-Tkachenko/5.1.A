/////////////////////////////////////////////////////////////////////////////////////////// Product.h
// заголовний файл Ц визначенн€ класу

#pragma once
#pragma pack(1)
#include "MyException.h"
#include "MyDerivedException.h"

using namespace std;

class Product
{
private:
	int first;
	double second;

public:
	Product();
	Product(int first, double second) throw(invalid_argument);
	Product(const Product& v);

	int GetFirst() const { return first; }
	double GetSecond() const { return second; }
	void SetFirst(int value) throw(invalid_argument);
	void SetSecond(double value) throw(MyException);

	Product& operator = (const Product& r);
	operator string() const;

	Product& operator --() throw(out_of_range);
	Product& operator ++();
	Product operator --(int) throw(MyDerivedException);
	Product operator ++(int);

	friend ostream& operator <<(ostream& out, const Product& a);
	friend istream& operator >>(istream& in, Product& a) throw(invalid_argument);

	double Power();
};
