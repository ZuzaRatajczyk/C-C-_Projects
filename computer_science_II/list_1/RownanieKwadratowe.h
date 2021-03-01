#ifndef RownanieKwadratowe_H
#define RownanieKwadratowe_H

#include <iostream>
#include <vector>

class RownanieKwadratowe
{
    public:
    float a, b, c;
    void czytaj_dane();
    std::vector<float> przetworz_dane();
    void wyswietl_wynik(std::vector<float> wynik);        
};

#endif