#include "Tzespol.hpp"
#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;



Tzespol::Tzespol() 
{
    Re = 0;
    Im = 0;
}

Tzespol::Tzespol(float set_Re, float set_Im)
{
    Re = set_Re;
    Im = set_Im;
}

Tzespol::Tzespol(float set_Re, float set_Im, float set_Mod, float set_Arg)
{
    Re = set_Re;
    Im = set_Im;
    Mod = set_Mod;
    Arg = set_Arg;
}

Tzespol Tzespol::add(const Tzespol &num_to_add) const
{
    cout << fixed << setprecision(1);
    Tzespol result;
    result.Re = Re + num_to_add.Re;
    result.Im = Im + num_to_add.Im;
    return result;
}

Tzespol Tzespol::subtract(const Tzespol &num_to_subtract) const
{
    cout << fixed << setprecision(1);
    Tzespol result;
    result.Re = Re - num_to_subtract.Re;
    result.Im = Im - num_to_subtract.Im;
    return result;
}

Tzespol Tzespol::multiply(const Tzespol &num_to_multiply) const
{
    cout << fixed << setprecision(1);
    Tzespol result;
    result.Re = Re * num_to_multiply.Re + Im * num_to_multiply.Im * -1;
    result.Im = Re * num_to_multiply.Im + Im * num_to_multiply.Re; 
    return result;
}

Tzespol Tzespol::divide(const Tzespol &divider) const
{
    cout << fixed << setprecision(1);
    Tzespol result;
    Tzespol divider_conjugate(divider.Re, -divider.Im); // obiekt będący sprzężeniem mianownika
    Tzespol numerator = multiply(divider_conjugate); // mnożenie licznika przez sprzężenie mianownika
    Tzespol denominator = divider.multiply(divider_conjugate); // mnożenie mianownika przez sprzężenie mianownika
    result.Re = numerator.Re / denominator.Re;
    result.Im = numerator.Im / denominator.Re;
    return result;

}

Tzespol Tzespol::operator+(const Tzespol &num_to_add) const
{
    return add(num_to_add);
}

Tzespol Tzespol::operator-(const Tzespol &num_to_sub) const
{
    return subtract(num_to_sub);
}

Tzespol Tzespol::operator*(const Tzespol &num_to_multiply) const
{
    return multiply(num_to_multiply);
}

Tzespol Tzespol::operator/(const Tzespol &num_to_divide) const
{
    return divide(num_to_divide);
}

void Tzespol::operator+=(const Tzespol &num_to_add) 
{
    cout << fixed << setprecision(1);
    Re += num_to_add.Re;
    Im += num_to_add.Im;

}

void Tzespol::operator-=(const Tzespol &num_to_sub) 
{
    cout << fixed << setprecision(1);
    Re -= num_to_sub.Re;
    Im -= num_to_sub.Im;
}

void Tzespol::operator*=(const Tzespol &num_to_multiply) 
{
    cout << fixed << setprecision(1);
    Re *= num_to_multiply.Re;
    Im *= num_to_multiply.Im;
}

void Tzespol::operator/=(const Tzespol &num_to_divide) 
{
    cout << fixed << setprecision(1);
    Re /= num_to_divide.Re;
    Im /= num_to_divide.Im;
}

bool Tzespol::operator==(const Tzespol &num_to_compare)
{
    if(Re == num_to_compare.Re && Im == num_to_compare.Im)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool Tzespol::operator!=(const Tzespol &num_to_compare)
{
    if(Re != num_to_compare.Re || Im != num_to_compare.Im)
    {
        return true;
    }
    else
    {
        return false;
    }
}

Tzespol Tzespol::calc_pow(int n) const // funcja oblicza n-tą potęgę przy użyciu wzoru Moivre'a
{
    Tzespol result;
    result.Re = pow(Mod, n) * cos(n * Arg);
    result.Im = pow(Mod, n) * sin(n * Arg);
    return result;
}

void Tzespol::set_absolute_val()
{
    cout << fixed << setprecision(2);
    Mod = sqrt(pow(Re, 2) + pow(Im, 2));
}

void Tzespol::set_argument()
{
    if(Re > 0)
    {
        Arg = atan(Im / Re);
    }
    else
    {
        Arg = atan(Im / Re) + M_PI; 
    }
}


void Tzespol::show_number()
{
    if(Im > 0)
    {
        cout << "z = " << Re << "+" << Im << "i" << endl;
    }
    else
    {
        cout << "z = " << Re << Im << "i" << endl;
    }
}


void Tzespol::show_absolute_val()
{
    cout << "Moduł|z| = " << Mod << endl;
}

void Tzespol::show_argument()
{
    cout << "Argument arg(z) = " << Arg << " rad" << endl;
}