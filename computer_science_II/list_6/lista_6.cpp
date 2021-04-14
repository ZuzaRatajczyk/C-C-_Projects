#include <iostream>
#include <string>
using namespace std;

class TZwierze
{
    string Nazwa;
    int Wiek;

    public:
    TZwierze();
    TZwierze(string nazwa, int wiek);
    ~TZwierze() {}; 
    void CzytajDane();
    void PiszDane();
    virtual void DajGlos();

};

class TPies : public TZwierze
{
    public:
    TPies();
    TPies(string nazwa, int wiek);
    ~TPies() {};
    void DajGlos();
};

class TKrowa : public TZwierze
{
    public:
    TKrowa();
    TKrowa(string nazwa, int wiek);
    ~TKrowa() {}; 
    void DajGlos();
};

class TKot : public TZwierze
{
    public:
    TKot();
    TKot(string nazwa, int wiek);
    ~TKot() {};
    void DajGlos();
};

TZwierze::TZwierze()
{
    Nazwa = "Brak nazwy";
    Wiek = 0;
}

TZwierze::TZwierze(string nazwa, int wiek)
{
    Nazwa = nazwa;
    Wiek = wiek;
}


void TZwierze::CzytajDane()
{
    cout << Nazwa;
    cout << Wiek;
}

void TZwierze::PiszDane()
{
    cin >> Nazwa;
    cin >> Wiek;
}

void TZwierze::DajGlos()
{
    cout << "..." << endl;
}


TPies::TPies() : TZwierze() {}

TPies::TPies(string nazwa, int wiek) : TZwierze(nazwa, wiek) {}

void TPies::DajGlos()
{
    cout << "HauHau" << endl;
}

TKot::TKot() : TZwierze() {}

TKot::TKot(string nazwa, int wiek) : TZwierze(nazwa, wiek) {}

void TKot::DajGlos()
{
    cout << "Miau" << endl;
}

TKrowa::TKrowa() : TZwierze() {}

TKrowa::TKrowa(string nazwa, int wiek) : TZwierze(nazwa, wiek) {}

void TKrowa::DajGlos()
{
    cout << "Muuu" << endl;
}

void Odglos(TZwierze &zwierze_domowe)
{
    zwierze_domowe.DajGlos();
}

int main()
{
    TZwierze JakiesZwierze;
    TPies Azor;
    TKrowa Krasula;
    TKot Mruczek;

    JakiesZwierze.DajGlos();
    Azor.DajGlos();
    Krasula.DajGlos();
    Mruczek.DajGlos();

    TZwierze *wsk;
    wsk = &JakiesZwierze;
    wsk->DajGlos();
    wsk = &Azor;
    wsk->DajGlos();
    wsk = &Krasula;
    wsk->DajGlos();
    wsk = &Mruczek;
    wsk->DajGlos();

    Odglos(JakiesZwierze);
    Odglos(Azor);
    Odglos(Krasula);
    Odglos(Mruczek);
    

    return 0;
}