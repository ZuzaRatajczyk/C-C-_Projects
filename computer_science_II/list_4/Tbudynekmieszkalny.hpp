#pragma once
#include "Tbudynek.hpp"
#include "Tdata.hpp"

class Tbudynekmieszkalny
    : public Tbudynek
{
    private:
    int Liczba_Mieszkancow;
    Tdata Data_Zasiedlenia;

    public : 
    Tbudynekmieszkalny();
    Tbudynekmieszkalny(string set_street, int set_house_num, int set_code, string set_city);
    Tbudynekmieszkalny(string set_street, int set_house_num, int set_flat_num, int set_code, string set_city);
    Tbudynekmieszkalny(Tbudynek adress);
    ~Tbudynekmieszkalny();
    void set_num_of_tenant(int num_of_tenant);
    void set_date(int year, int month, int day);
    int get_num_of_tenant();
    Tdata get_date();
};
