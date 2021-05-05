#include <iostream>
#include <vector>
using namespace std;

template <typename T>
class wektor
{
    vector<T> tablica;
    int liczba_elementow = 0;

public:
    wektor(){};
    int ile_elementow();
    T &co_na(int gdzie);
    void wstaw(T obiekt, int gdzie);
    void wstaw(T obiekt);
    void usun(int gdzie);
    void usun();
};

template <typename T>
int wektor<T>::ile_elementow()
{
    return liczba_elementow;
}

template <typename T>
T &wektor<T>::co_na(int gdzie)
{
    return tablica[gdzie];
}

template <typename T>
void wektor<T>::wstaw(T obiekt, int gdzie)
{
    tablica.insert(tablica.begin() + gdzie, obiekt);
    liczba_elementow++;
}

template <typename T>
void wektor<T>::wstaw(T obiekt)
{
    tablica.push_back(obiekt);
    liczba_elementow++;
}

template <typename T>
void wektor<T>::usun(int gdzie)
{
    if (gdzie < liczba_elementow)
    {
        tablica.erase(tablica.begin() + gdzie);
        liczba_elementow--;
    }
    else
    {
        cout << "Brak elementu " << gdzie << endl;
    }
}

template <typename T>
void wektor<T>::usun()
{
    if (liczba_elementow > 0)
    {
        tablica.pop_back();
        liczba_elementow--;
    }
    else
    {
        cout << "Brak elementow do usuniecia" << endl;
    }
}

int main()
{
    wektor<int> obj1;
    wektor<char> obj2;
    wektor<float> obj3;

    cout << "Objekt 1" << endl;
    cout << "Liczba elementow " << obj1.ile_elementow() << endl;
    obj1.wstaw(1);
    obj1.wstaw(2);
    obj1.wstaw(3);
    obj1.wstaw(4);
    obj1.wstaw(5);
    obj1.wstaw(6);
    obj1.wstaw(7);
    obj1.wstaw(8, 7);
    obj1.wstaw(9);
    obj1.wstaw(10);
    obj1.wstaw(11);
    cout << "Liczba elementow " << obj1.ile_elementow() << endl;

}