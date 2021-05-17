#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void show_element(int element)
{
    cout << element << endl;
}

vector<int>::iterator find_position(vector<int> &vec, int element)
{
    int i = 0;
    while (element > vec[i])
    {
        i++;
        if (i == vec.size())
        {
            return vec.begin() + i;
        }
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
        B.insert(find_position(B, el), el);
    }

    for_each(B.begin(), B.end(), show_element);
}