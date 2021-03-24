#include "Tbudynek.hpp"
#include "Tbudynekmieszkalny.hpp"
#include "Tdata.hpp"
#include <iostream>
using namespace std;


int main()
{
    Tbudynek my_adress("Kasztanowa", 19, 2, 45061,"Katowice");
    Tbudynekmieszkalny building(my_adress);
    cout << "Adres budynku mieszkalnego:" << endl; 
    cout << building;
    building.set_num_of_tenant(56);
    building.set_date(1994,9, 20);
    Tdata date = building.get_date();
    cout << "Data zasiedlenia:" << endl;
    date.pokaz_date();
    cout << "Liczba mieszkańców" << endl;
    cout << building.get_num_of_tenant() << endl;

    return 0;
}