#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void show_element(int element)
{ 
    cout << element << " ";
}

int main()
{
    srand(time(NULL));
    vector<int> A;

    for(int i = 0; i < 1000; i++)
    {
        A.push_back(rand() % (1000 + 1));
        cout << i << ".Pojemność: " << A.capacity() << endl;
    }

    cout << "Rozmiar: " << A.size() << endl; 

    for(int i = 0; i <100; i++)
    {
        A.pop_back();
    }

    cout << "Pojemność po usunięciu 100 ostatnich elementów: " << A.capacity() << endl;
    cout << "Rozmiar po usunięciu 100 ostatnich elementów: " << A.size() << endl;

    for (int i = 0; i < 100; i++)
    {
        A.erase(A.begin() + i);
    }

    cout << "Pojemność po usunięciu 100 pierwszych elementów: " << A.capacity() << endl;
    cout << "Rozmiar po usunięciu 100 pierwszych elementów: " << A.size() << endl;

    int el = A[400];
    cout << "Element na pozycji (o indeksie) 400: " << el << endl;
    cout << "Element na pozycji (o indeksie) 401: " << A[401] << endl;
    A.erase(A.begin() + 400);
    A.insert(A.begin() + 500, el);
    cout << "Element na pozycji (o indeksie) 400: " << A[400] << endl;
    cout << "Element na pozycji (o indeksie) 500: " << A[500] << endl;

    sort(A.begin(), A.end());    
    cout << "Zawartość posortowanego kontenera:" << endl;
    for_each(A.begin(), A.end(), show_element);
    cout << endl;
    cout << "Zawartość wymieszanego kontenera:" << endl;
    random_shuffle(A.begin(), A.end());
    for_each(A.begin(), A.end(), show_element);
    cout << endl;
}

