#include <iostream>
#include <ctime>
#include <string>
#include "Tdata.hpp"



int Tdata::month_days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

Tdata::Tdata() : time()
{
    std::cout << "Uruchamiany konstruktor domyślny klasy Tdata" << std::endl;
    year = 0;
    month = 0;
    day = 0;
    
}

Tdata::Tdata(int y, int m, int d)
{
    std::cout << "Uruchamiany konstruktor klasy Tdata" << std::endl;
    year = y;
    month = m;
    day = d;
}

    Tdata::Tdata(int y, int m, int d, int h, int min, int s) : time(h, min, s)
{
    std::cout << "Uruchamiany konstruktor klasy Tdata" << std::endl;
    year = y;
    month = m;
    day = d;
}

Tdata::~Tdata()
{
    std::cout << "Uruchamiany destruktor klasy Tdata" << std::endl;
}

void Tdata::sprawdz_dane()
{
    if(year < 0 || month > 12 || day > 31)
    {
        std::cout << "Nieprawidłowa data" << std::endl;
    }
    if(time.godzina() > 24 || time.minuta() > 59 || time.sekunda() > 59)
    {
        std::cout << "Nieprawidłowy czas" << std::endl;
    }
}

int Tdata::rok()
{
    return year;
}

int Tdata::miesiac()
{
    return month;
}

int Tdata::dzien()
{
    return day;
}

int Tdata::godzina()
{
    return time.godzina();
}

int Tdata::minuta()
{
    return time.minuta();
}
int Tdata::sekunda()
{
    return time.sekunda();
}

void Tdata::ustaw_rok(int set_year)
{
    year = set_year;
}

void Tdata::ustaw_miesiac(int set_month)
{
    month = set_month;
}

void Tdata::ustaw_dzien(int set_day)
{
    day = set_day;
}

void Tdata::dodaj_dni(int days_to_add)
{
    day += days_to_add;
    int current_month_days = month_days[month - 1]; 
    while(day > current_month_days)  
    {
        day -= current_month_days;
        month ++;
        if(month > 12)
        {
            year ++;
            month = 1;
        }
        current_month_days = month_days[month - 1];
    }
}

void Tdata::dodaj_godziny(int hours_to_add)
{
    int hour = time.godzina();
    hour += hours_to_add;
    while(hour > 24)
    {
        hour-= 24;
        dodaj_dni(1);
    }
    time.ustaw_godzine(hour);
}

void Tdata::dodaj_minuty(int minutes_to_add)
{
    int min = time.minuta();
    min += minutes_to_add;
    while(min > 60)
    {
        min -= 60;
        dodaj_godziny(1);
    }
    time.ustaw_minute(min);
}

void Tdata::dodaj_sekundy(int secundes_to_add)
{
    int sec = time.sekunda();
    sec += secundes_to_add;
    while(sec > 60)
    {
        sec -= 60;
        dodaj_minuty(1);
    }
    time.ustaw_sekunde(sec);
}

void Tdata::dodaj_dni_i_czas(int days_to_add, Tczas& t)
{
    int hours_to_add = t.godzina();
    int min_to_add = t.minuta();
    int sec_to_add = t.sekunda();
    dodaj_dni(days_to_add);
    dodaj_godziny(hours_to_add);
    dodaj_minuty(min_to_add);
    dodaj_sekundy(sec_to_add);

}

void Tdata::pokaz_date() //funcja pokazująca datę i czas w formacie dd mmmm rrrr gg:mm:ss
{
    char time_string[20];
    tm t = {.tm_mday = day, .tm_mon = month - 1, .tm_year = year - 1900};
    strftime(time_string, 20, "%d %B %Y", &t);

    std::cout << time_string  << std::endl;
}

void Tdata::pokaz_date_i_godzine()
{
    pokaz_date();
    time.pokaz_czas();
}

void Tdata::policz_odstęp_czasu(Tdata date)
{
    const int seconds_in_minute = 60;
    const int seconds_in_hour = 60 * seconds_in_minute;
    const int seconds_in_day = 24 * seconds_in_hour;
    int days = 0;
    int hours = 0;
    int minutes = 0;
    tm t1 = {.tm_sec = time.sekunda(), .tm_min = time.minuta(), .tm_hour = time.godzina(), .tm_mday = day, .tm_mon = month - 1, .tm_year = year - 1900};
    time_t tt1 = mktime(&t1);
    tm t2 = {.tm_sec = date.sekunda(), .tm_min = date.minuta(), .tm_hour = date.godzina(), .tm_mday = date.day, .tm_mon = date.month - 1, .tm_year = date.year - 1900};
    time_t tt2 = mktime(&t2);
    double seconds = difftime(tt2, tt1);
    while(seconds >= seconds_in_day)
    {
        seconds-=86400;
        days++;
    }
    while (seconds >= seconds_in_hour)
    {
        seconds-=3600;
        hours++;
    }
    while (seconds >= seconds_in_minute)
    {
        seconds-=60;
        minutes ++;
    }
    std::cout << "Odstęp czasu wynosi " << days << " dni " << hours << " godzin " << minutes << " minut " << seconds << " sekund " << std::endl ;
}

std::string Tdata::dzien_tygodnia()
{
    std::string week_day[7] = {"Poniedzialek", "Wtorek", "Środa", "Czwartek", "Piątek", "Sobota", "Niedziela"};
    tm t = {.tm_mday = day, .tm_mon = month - 1, .tm_year = year - 1900};
    mktime(&t);
    return week_day[t.tm_wday - 1];
}
