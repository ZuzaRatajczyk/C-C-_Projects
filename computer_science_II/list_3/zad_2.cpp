#include "Tzespol.hpp"


int main()
{
    Tzespol num1(4, -7);
    Tzespol num2(-3, 2);
    Tzespol add_result = num1 + num2;
    add_result.show_number();
    Tzespol sub_result = num1 - num2;
    sub_result.show_number();
    Tzespol multiply_result = num1 * num2;
    multiply_result.show_number();
    Tzespol division_result = num1 / num2;
    division_result.show_number();
}