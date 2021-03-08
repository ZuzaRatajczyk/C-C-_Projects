#include <iostream>
#include <cmath>
#include <vector>
#include <iomanip>

class RownanieKwadratowe
{
public:
    float a, b, c;

    public:
    
    void czytaj_dane()
    {
        std::cout << "a=";
        std::cin >> a;
        std::cout << "b=";
        std::cin >> b;
        std::cout << "c=";
        std::cin >> c;
        if (a == 0)
        {
            exit(0);
        }
    }

    std::vector<float> przetworz_dane()
    {
        std::vector<float> wynik;
        float delta;
        delta = pow(b, 2) - 4 * a * c;
        if (delta > 0)
        {
            float x1 = (-b - sqrt(delta)) / (2 * a);
            wynik.push_back(x1);
            float x2 = (-b + sqrt(delta)) / (2 * a);
            wynik.push_back(x2);
        }
        else if (delta == 0)
        {
            float x0 = -b / (2 * a);
            wynik.push_back(x0);
        }
        return wynik;
    }

    void wyswietl_wynik(std::vector<float> wynik)
    {
        if (wynik.size() == 0)
        {
            std::cout << "Brak pierwiastków" << std::endl;
        }
        else
        {
            for (int i = 0; i < wynik.size(); i++)
            {
                std::cout << "x" << i << "=" << wynik[i] << std::endl;
            }
        }
    }
};



int main()
{
    std::cout << std::setprecision(3);
    RownanieKwadratowe rownanie;
    rownanie.czytaj_dane();
    std::vector<float> wynik_rownania = rownanie.przetworz_dane();
    rownanie.wyswietl_wynik(wynik_rownania);
    return 0;
}