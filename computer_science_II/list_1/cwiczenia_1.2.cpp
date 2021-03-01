#include <vector>
#include <iostream>
#include <iomanip>
#include "RownanieKwadratowe.h"

int main()
{
    std::cout << std::setprecision(3);
    RownanieKwadratowe *rownanie = new RownanieKwadratowe;
    rownanie->czytaj_dane();
    std::vector<float> wynik_rownania = rownanie->przetworz_dane();
    rownanie->wyswietl_wynik(wynik_rownania);
    delete rownanie;
    return 0;
}
