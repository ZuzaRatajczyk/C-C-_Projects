#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void show_element(int element)
{
    cout << element << endl;
}

vector<int>::iterator myfunction(vector<int> &vec, int i, int element)
{ 
    while(element < vec[i-1])
    {
        i--;
    }
    return vec.begin() + i;
}

int main()
{
    vector<int> B;
    srand(time(NULL));

    B.insert(B.begin(), rand() % (1000 + 1));
    for (int i = 0; i < 999; i++)
    {
        int el = rand() % (1000 + 1);
        B.insert(myfunction(B, i, el), el);
    }

    for_each(B.begin(), B.end(), show_element);
}