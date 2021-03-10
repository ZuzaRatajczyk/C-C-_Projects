#include <iostream>
#include "Tdata.hpp"

int main()
{
    Tdata date1(2021, 13, 8, 12, 40, 30);
    Tdata date2(2021, 3, 13, 10, 40, 31);
    date1.dodaj_dni(30);
    date1.dodaj_sekundy(70);
    date1.pokaz_date_i_godzine();


    return 0;
}