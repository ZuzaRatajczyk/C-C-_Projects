#include "Tzespol.hpp"
#include <iostream>
using namespace std;

int main()
{
    Tzespol num1(4, -7);
    Tzespol num2(4, -7);
    num1.show_number();
    num2.show_number();
    if (num1 == num2)
    {
        cout << "Liczby są sobie równe" << endl;
    }
    else
    {
        cout << "Liczby nie są sobie równe" << endl;
    }
    num1.show_number();
    num1 += num2;
    if (num1 != num2)
    {
        cout << "Liczby nie są sobie równe" << endl;
    }
    else
    {
        cout << "Liczby są sobie równe" << endl;
    }
    num1.show_number();
    num1 -= num2;
    num1.show_number();
    num1 *= num2;
    num1.show_number();
    num1 /= num2;
    num1.show_number();

}