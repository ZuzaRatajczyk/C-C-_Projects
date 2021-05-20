#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

bool check_order(string a, string b)
{
    return a < b;
}

int main()
{
    string input_file_name;
    string output_file_name;
    string word;
    ifstream input_file;
    ofstream output_file;
    vector<string> file_text_vec;
    cout << "Podaj nazwę pliku źródłowego: ";
    cin >> input_file_name;

    input_file.open(input_file_name);

    while (input_file >> word) // operator>>(string) Extracts a string from the input stream, storing the sequence in str, which is overwritten 
    {
        file_text_vec.push_back(word);
    }

    sort(file_text_vec.begin(), file_text_vec.end(), check_order);

    input_file.close();

    cout << "Podaj nazwę pliku wynikowego: ";
    cin >> output_file_name;

    output_file.open(output_file_name);

    for(int i = 0; i < file_text_vec.size(); i++)
    {
        output_file << file_text_vec[i] << " ";
    }

    output_file.close();

}