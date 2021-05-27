#include <iostream>
#include <exception>
#include <math.h>
using namespace std;

class ZeroDivisionError :  public exception
{
    public:
    const char *what() const throw()
    {
        return "Zero Division Error";
    }
};

class InvalidInput : public exception
{
public:
    const char *what() const throw()
    {
        return "Invalid Input";
    }
};

class NegativeValue : public exception
{
public:
    const char *what() const throw()
    {
        return "Negative Value Under Root";
    }
};

float division(int &a, int &b)
{
    if (b == 0)
    {
        throw ZeroDivisionError();
    }
    else
    {
        float result = a / b;
        return result;
    }
}

void take_input(int &a, int &b)
{

    cout << "Podaj licznik (liczba podpierwiastkowa): ";
    if(cin >> a){}
    else
    {
        throw InvalidInput();
    }
    cout << "Podaj mianownik: ";
    if (cin >> b){}
    else
    {
        throw InvalidInput();
    }
}

void calc_sqrt(int &a)
{
    if(a<0)
    {
        throw NegativeValue();
    }
    else
    {
        a = sqrt(a);
    }
}

int main()
{
    int a;
    int b;

    try
    {
        take_input(a, b);
        calc_sqrt(a);
        float result = division(a, b);
        cout << result << endl;
    }
    catch (ZeroDivisionError &e)
    {
        std::cout << e.what() << std::endl;
    }
    catch (InvalidInput &e)
    {
        std::cout << e.what() << std::endl;
    }
    catch (NegativeValue &e)
    {
        std::cout << e.what() << std::endl;
    }

}