#include <iostream>
#include <cmath>
#include <vector>
#include "RownanieKwadratowe.h"

void RownanieKwadratowe::czytaj_dane()
{
    std::cout << "a=";
    std::cin >> a;
    std::cout << "b=";
    std::cin >> b;
    std::cout << "c=";
    std::cin >> c;
}

std::vector<float> RownanieKwadratowe::przetworz_dane()
{
    std::vector<float> wynik;
    float delta;
    if(a!=0)
    {
        delta = pow(b, 2) - 4 * a * c;
        if (delta > 0)
        {
            float x1 = (-b - sqrt(delta)) / (2 * a);
            wynik.push_back(x1);
            float x2 = (-b + sqrt(delta)) / (2 * a);
            wynik.push_back(x2);
        }
        else if (delta == 0)
        {
            float x1 = -b / (2 * a);
            wynik.push_back(x1);
        }
    }
    return wynik;
}

void RownanieKwadratowe::wyswietl_wynik(std::vector<float> wynik)
{
    if (a == 0 && b == 0 && c!=0)
    {
        std::cout << "Równanie sprzeczne" << std::endl;
    }
    else if (a == 0)
    {
        std::cout << "Równanie liniowe (a=0)" << std::endl;
    }
    else if (wynik.size() == 0)
    {
        std::cout << "Brak pierwiastków" << std::endl;
    }
    else
    {
        for (int i = 0; i < wynik.size(); i++)
        {
            std::cout << "x" << i+1 << "=" << wynik[i] << std::endl;
        }
    }
}