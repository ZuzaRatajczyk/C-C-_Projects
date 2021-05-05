#include <iostream>
#include <vector>
using namespace std;

template <typename T>
class wektor
{
    vector<T*> tablica;
    int liczba_elementow = 0;

public:
    wektor(){};
    int ile_elementow();
    T* co_na(int gdzie);
    void wstaw(T* obiekt, int gdzie);
    void wstaw(T* obiekt);
    void usun(int gdzie);
    void usun();
};

template <typename T>
int wektor<T>::ile_elementow()
{
    return liczba_elementow;
}

template <typename T>
T* wektor<T>::co_na(int gdzie)
{
    return tablica[gdzie];
}

template <typename T>
void wektor<T>::wstaw(T* obiekt, int gdzie)
{
    if (liczba_elementow < 10)
    {
        tablica.insert(tablica.begin() + gdzie, obiekt);
        liczba_elementow++;
    }
    else
    {
        cout << "Brak miejsca w tablicy" << endl;
    }
}

template <typename T>
void wektor<T>::wstaw(T* obiekt)
{
    if (liczba_elementow < 10)
    {
        tablica.push_back(obiekt);
        liczba_elementow++;
    }
    else
    {
        cout << "Brak miejsca w tablicy" << endl;
    }
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

    cout << "Objekt 1" << endl;
    cout << "Liczba elementow " << obj1.ile_elementow() << endl;
    int val = 2;
    int* ptr = &val;
    obj1.wstaw(ptr);
    cout << "Liczba elementow " << obj1.ile_elementow() << endl;
    int* element_zero = obj1.co_na(0);
    cout << "Element na pozycji 0: " << element_zero << endl;
    cout << endl;

}