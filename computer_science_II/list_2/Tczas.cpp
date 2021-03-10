#include <iostream>
#include <ctime>
#include "Tczas.hpp"

Tczas::Tczas()
{
    hours= 0;
    min = 0;
    sec = 0;
}

Tczas::Tczas(int h, int m, int s)
{
    hours = h;
    min = m;
    sec = s;
}

Tczas Tczas::operator+(const Tczas &t) // operator dodaje obiekty Tczas z uwzględnieniem przejścia do kolejnego dnia
{
    Tczas result;

    result.hours = t.hours + this->hours;
    if (result.hours > 24)
    {
        result.hours -= 24;
    }
    result.min = t.min + this->min;
    result.sec = t.sec + this->sec;
    return result;
}

int Tczas::godzina() 
{
    return hours;
}

int Tczas::minuta()
{
    return min;
}

int Tczas::sekunda()
{
    return sec;
}

void Tczas::pokaz_czas() //funkcja pokazuje czas w formacie gg:mm:ss
{
    char time_string[20];
    tm t = {.tm_sec = sec, .tm_min = min, .tm_hour = hours};
    strftime(time_string, 20, "%X", &t);
    std::cout << time_string << std::endl;
}

void Tczas::ustaw_godzine(int h)
{
    hours = h;
}
void Tczas::ustaw_minute(int m)
{
    min = m;
}
void Tczas::ustaw_sekunde(int s)
{
    sec = s;
}
