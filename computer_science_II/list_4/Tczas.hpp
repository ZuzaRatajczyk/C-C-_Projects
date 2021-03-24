#ifndef Tczas_H
#define Tczas_H

class Tczas
{
private:
    int hours, min, sec;

public:
    Tczas();
    Tczas(int h, int m, int s);
    Tczas operator+(const Tczas &t);
    int godzina();
    int minuta();
    int sekunda();
    void pokaz_czas();
    void ustaw_godzine(int h);
    void ustaw_minute(int m);
    void ustaw_sekunde(int s);
};

#endif