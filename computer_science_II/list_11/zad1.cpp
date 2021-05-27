#include "Tbudynek.hpp"
#include <iostream>
#include <new>
using namespace std;


int main()
{
    for(long long int i = 0;;i+=10000)
    {
        try
        {
            int *array1 = new int[i];
            delete array1;
        }
        catch (bad_alloc)
        {
            cout << i << endl;
            break;
        }
    }

}
