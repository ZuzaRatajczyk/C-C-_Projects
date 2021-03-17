
class Tzespol
{
    float Re, Im, Mod, Arg;
public:
Tzespol();
Tzespol(float set_Re, float set_Im);
Tzespol(float set_Re, float set_Im, float set_Mod, float set_Arg);
Tzespol add(const Tzespol &num_to_add) const;
Tzespol subtract(const Tzespol &num_to_subtract) const;
Tzespol multiply(const Tzespol &num_to_multiply) const;
Tzespol divide(const Tzespol &divider) const;
Tzespol operator+(const Tzespol &num_to_add) const;
Tzespol operator-(const Tzespol &num_to_sub) const;
Tzespol operator*(const Tzespol &num_to_multiply) const;
Tzespol operator/(const Tzespol &num_to_divide) const;
void operator+=(const Tzespol &num_to_add);
void operator-=(const Tzespol &num_to_sub);
void operator*=(const Tzespol &num_to_multiply);
void operator/=(const Tzespol &num_to_divide);
bool operator==(const Tzespol &num_to_compare);
bool operator!=(const Tzespol &num_to_compare);
Tzespol calc_pow(int n) const; 
void set_absolute_val(); // funcja wylicza moduł i jego nadaje wartość składowej Mod 
void set_argument(); // funcja wylicza argument i jego nadaje wartość skłądowej Arg
void show_number();
void show_absolute_val();
void show_argument();
};