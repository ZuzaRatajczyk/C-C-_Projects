#ifndef Tdata_H
#define Tdata_H
#include "Tczas.hpp"


class Tdata
{
private:
    static int month_days[12];
    int year, month, day;
    Tczas time;

public:
Tdata();
Tdata(int y, int m, int d, int h, int min, int s);
void sprawdz_dane();
int rok();
int miesiac();
int dzien();
int godzina();
int minuta();
int sekunda();
void dodaj_dni(int days_to_add);
void dodaj_godziny(int hours_to_add);
void dodaj_minuty(int min_to_add);
void dodaj_sekundy(int sec_to_add);
void dodaj_dni_i_czas(int days_to_add, Tczas &t);
void pokaz_date();
void pokaz_date_i_godzine();
void policz_odstęp_czasu(Tdata date);
std::string dzien_tygodnia();
};

#endif