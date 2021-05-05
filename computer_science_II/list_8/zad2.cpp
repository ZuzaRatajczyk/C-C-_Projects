#include <iostream>
#include <vector>
using namespace std;

template <typename T, int size>
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

template <typename T, int size>
int wektor<T, size>::ile_elementow()
{
    return liczba_elementow;
}

template <typename T, int size>
T &wektor<T, size>::co_na(int gdzie)
{
    return tablica[gdzie];
}

template <typename T, int size>
void wektor<T, size>::wstaw(T obiekt, int gdzie)
{
    if (liczba_elementow < size)
    {
        tablica.insert(tablica.begin() + gdzie, obiekt);
        liczba_elementow++;
    }
    else
    {
        cout << "Brak miejsca w tablicy" << endl;
    }
}

template <typename T, int size>
void wektor<T, size>::wstaw(T obiekt)
{
    if (liczba_elementow < size)
    {
        tablica.push_back(obiekt);
        liczba_elementow++;
    }
    else
    {
        cout << "Brak miejsca w tablicy" << endl;
    }
}

template <typename T, int size>
void wektor<T, size>::usun(int gdzie)
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

template <typename T, int size>
void wektor<T, size>::usun()
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
    wektor<int, 10> obj1;
    wektor<char, 5> obj2;
    wektor<float, 2> obj3;

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
    int &element_zero = obj1.co_na(0);
    int &element_siedem = obj1.co_na(7);
    cout << "Element na pozycji 0: " << element_zero << endl;
    cout << "Element na pozycji 7: " << element_siedem << endl;
    obj1.usun(1);
    cout << "Liczba elementow " << obj1.ile_elementow() << endl;
    cout << endl;

    cout << "Objekt 2" << endl;
    obj2.wstaw('a');
    obj2.wstaw('b');
    obj2.usun(0);
    cout << "Liczba elementow " << obj2.ile_elementow() << endl;
    cout << endl;

    cout << "Objekt 3" << endl;
    obj3.wstaw(1.2, 0);
    obj3.wstaw(3.1, 1);
    cout << "Liczba elementow " << obj3.ile_elementow() << endl;
    float &element0 = obj3.co_na(0);
    obj3.usun();
    obj3.usun();
    obj3.wstaw(100.1, 0);
    cout << "Element na pozycji 0: " << element0 << endl;
    cout << "Liczba elementow " << obj3.ile_elementow() << endl;
}