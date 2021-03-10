#include <iostream>
#include "Tczas.hpp"


int main()
{
    Tczas time1(12, 30, 30);
    Tczas time2(8, 15, 15);
    time2.pokaz_czas();
    time1.pokaz_czas();
    Tczas result_time = time1 + time2;
    std::cout << "Wynik dodawania dwóch czasów to:" << std::endl;
    result_time.pokaz_czas();
}