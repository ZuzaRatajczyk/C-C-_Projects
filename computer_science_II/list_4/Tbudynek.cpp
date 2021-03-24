#include "Tbudynek.hpp"

Tbudynek::Tbudynek()
{
    cout << "Uruchamiany konstruktor domyślny klasy Tbudynek" << endl;
    Street = "";
    House_Num = 0;
    Flat_Num = 0;
    Post_Code = 0;
    City = "";
}

Tbudynek::Tbudynek(string set_street, int set_house_num, int set_code, string set_city)
{
    cout << "Uruchamiany konstruktor klasy Tbudynek" << endl;
    Street = set_street;
    House_Num = set_house_num;
    Flat_Num = 0;
    Post_Code = set_code;
    City = set_city;
}

Tbudynek::Tbudynek(string set_street, int set_house_num, int set_flat_num, int set_code, string set_city)
{
    cout << "Uruchamiany konstruktor klasy Tbudynek" << endl;
    Street = set_street;
    House_Num = set_house_num;
    Flat_Num = set_flat_num;
    Post_Code = set_code;
    City = set_city;
}

Tbudynek::~Tbudynek()
{
    cout << "Uruchamiany destruktor klasy Tbudynek" << endl;
}

void Tbudynek::set_house_num(int num)
{
    House_Num = num;
}

void Tbudynek::set_flat_num(int num)
{
    Flat_Num = num;
}

void Tbudynek::set_post_code(int code)
{
    Post_Code = code;
}

void Tbudynek::set_street(string street)
{
    Street = street;
}

void Tbudynek::set_city(string city)
{
    City = city;
}

int Tbudynek::get_house_num()
{
    return House_Num;
}

int Tbudynek::get_flat_num()
{
    return Flat_Num;
}

int Tbudynek::get_post_code()
{
    return Post_Code;
}

string Tbudynek::get_street()
{
    return Street;
}

string Tbudynek::get_city()
{
    return City;
}

ostream &operator<<(ostream& stream, const Tbudynek &adress)
{
    if(adress.Flat_Num == 0)
    {
        stream << adress.Street << " " << adress.House_Num << " " << adress.Post_Code << " " << adress.City << endl;
    }
    else
    {
        stream << adress.Street << " " << adress.House_Num << "/" << adress.Flat_Num << " " << adress.Post_Code << " " << adress.City << endl;
    }


    return stream;
}