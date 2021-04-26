#include "Product.h"

void _unexpected_to_bad()
{
    cerr << "bad_exception" << endl;
    throw;
}

Product makeProduct(int first, double second)
{
    Product P(first, second);
    return P;
}

void Call_Bad() throw(bad_exception)
{
    throw bad_exception();
}

int main()
{
    set_unexpected(_unexpected_to_bad);
    try
    {
        Product A = makeProduct(3, 3.5);
        Product B(2, 2.6);
        B = A;
        cout << A << endl;
        B++;
        cout << B << endl << endl;
        cout << "size of class = " << sizeof(B) << endl;
    }
    catch (invalid_argument a)
    {
        cerr << "Exception: " << a.what() << endl << endl;
    }

    Product C;
    try
    {
        cin >> C;
        cout << C << endl;
        cout << "Power = " << C.Power() << endl << endl;
        try
        {
            C--;
        }
        catch (MyDerivedException* c)
        {
            cerr << c->What() << endl << endl;
        }
        catch (MyDerivedException c)
        {
            cerr << c.What() << endl << endl;
        }
        cout << C << endl;
    }
    catch (invalid_argument b)
    {
        cerr << "Exception: " << b.what() << endl;
    }

    try
    {
        int first;
        double second;
        cout << "first: "; cin >> first;
        C.SetFirst(first);
        cout << "second: "; cin >> second;
        C.SetSecond(second);
    }
    catch (invalid_argument& d)
    {
        cerr << "Exception: " << d.what() << endl;
    }
    catch (MyException d)
    {
        cerr << "Exception: " << d.What() << endl;
    }

    try
    {
        Call_Bad();
    }
    catch (bad_exception)
    {
        cerr << "catch (bad_exception)" << endl;
    }
}