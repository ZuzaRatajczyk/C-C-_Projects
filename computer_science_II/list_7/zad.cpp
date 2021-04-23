
#include <iostream>
using namespace std;

template <typename T>
T MinTab(T array[], int size)
{
    T min = array[0];
    for(int i = 1; i < size; i++)
    {
        if(array[i] < min)
        {
            min = array[i];
        }
    }
    return min;
}

template <typename T>
void Zamiana(T &x, T &y)
{
    T array[2] = {x, y};
    y = array[0]; 
    x = array[1];

}

template <typename T>
class Schowek
{
    T wart;
    
    public:
    Schowek() {};
    Schowek(T wart);
    void set_wart();
    void show_wart();
};


template <typename T>
Schowek<T>::Schowek(T w)
{
    wart = w;
}

    template <typename T>
    void Schowek<T>::set_wart()
{
    cin >> wart;
}

template <typename T>
void Schowek<T>::show_wart()
{
    cout << "Wartość:" << wart << endl;
}

    int main()
{
    cout << "Najmniejsze wartosci w tablicach:" << endl;
    int array1[3] = {1, 2, 3};
    double array2[3] = {1.5, 1.4, 2.5};
    char array3[3] = {'a', 'b', 'c'};
    int min1 = MinTab(array1, 3);
    cout << min1 <<endl;
    double min2 = MinTab(array2, 3);
    cout << min2 << endl;
    char min3 = MinTab(array3, 3);
    cout << min3 << endl;

    cout << "Zamiana wartości zmiennych:" << endl;
    int val1 = 1;
    int val2 = 20;
    cout << val1 << "," << val2 << endl;
    Zamiana(val1, val2);
    cout << val1 << "," << val2 << endl;

    cout << "Obiekty klasy Schowek:" << endl;
    cout << "Podaj wartosc typu int:" << endl;
    Schowek<int> obj1;
    obj1.set_wart();
    obj1.show_wart();
    cout << "Podaj wartosc typu float:" << endl;
    Schowek<float> obj2;
    obj2.set_wart();
    obj2.show_wart();
    cout << "Podaj wartosc typu char:" << endl;
    Schowek<char> obj3;
    obj3.set_wart();
    obj3.show_wart();

    cout << "Zamiana obiektów typu Schowek<int>:" << endl;
    cout << "Podaj war5osc typu int:" << endl;
    Schowek<int> obj4;
    obj4.set_wart();
    obj4.show_wart();
    cout << "Podaj wartosc typu int:" << endl;
    Schowek<int> obj5;
    obj5.set_wart();
    obj5.show_wart();
    Zamiana(obj4, obj5);
    cout << "Po zamianie:" << endl;
    obj4.show_wart();
    obj5.show_wart();
}   

