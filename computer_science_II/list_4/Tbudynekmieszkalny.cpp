#include "Tbudynekmieszkalny.hpp"


Tbudynekmieszkalny::Tbudynekmieszkalny()
{
    cout << "Uruchamiany konstruktor domyślny klasy Tbudynekmieszkalny" << endl;
    Liczba_Mieszkancow = 0;

}

Tbudynekmieszkalny::Tbudynekmieszkalny(string street, int house_num, int code, string city) : Tbudynek(street, house_num, code, city)
{
    cout << "Uruchamiany konstruktor klasy Tbudynekmieszkalny" << endl;
}

Tbudynekmieszkalny::Tbudynekmieszkalny(string street, int house_num, int flat_num, int code, string city) : Tbudynek(street, house_num, flat_num, code, city)
{
    cout << "Uruchamiany konstruktor klasy Tbudynekmieszkalny" << endl;

}

Tbudynekmieszkalny::Tbudynekmieszkalny(Tbudynek adress) : 
Tbudynek(adress.get_street(), adress.get_house_num(), adress.get_flat_num(), adress.get_post_code(), adress.get_city())
{
    cout << "Uruchamiany konstruktor klasy Tbudynekmieszkalny" << endl;
}

Tbudynekmieszkalny::~Tbudynekmieszkalny()
{
    cout << "Uruchamiany destruktor klasy Tbudynekmieszkalny" << endl;
}

void Tbudynekmieszkalny::set_num_of_tenant(int num_of_tenant)
{
    Liczba_Mieszkancow = num_of_tenant;
}

void Tbudynekmieszkalny::set_date(int year, int month, int day)
{
    Data_Zasiedlenia.ustaw_rok(year);
    Data_Zasiedlenia.ustaw_miesiac(month);
    Data_Zasiedlenia.ustaw_dzien(day);
}


int Tbudynekmieszkalny::get_num_of_tenant()
{
    return Liczba_Mieszkancow;
}

Tdata Tbudynekmieszkalny::get_date()
{
    return Data_Zasiedlenia;
}

