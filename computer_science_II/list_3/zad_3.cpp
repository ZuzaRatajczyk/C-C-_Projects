#include "Tzespol.hpp"
using namespace std;

int main()
{
    Tzespol num1(12, 56);
    num1.show_number();
    num1.set_absolute_val();
    num1.show_absolute_val();
    num1.set_argument();
    num1.show_argument();
    Tzespol num1_pow = num1.calc_pow(2);
    num1_pow.show_number();
}