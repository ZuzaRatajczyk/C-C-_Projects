#include <iostream>

const int leap_year[12] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
const int non_leap_year[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
const int seconds_in_minute = 60;
const int seconds_in_hour = 60 * seconds_in_minute;
const int seconds_in_day = 24 * seconds_in_hour;

void get_dates(int first_date[6], int second_date[6])
{
    for (int i = 0; i < 6; i++)
    {
        std::cin >> first_date[i];
    }

    for (int i = 0; i < 6; i++)
    {
        std::cin >> second_date[i];
    }    
    for (int i = 0; i < 6; i++)
    {
        first_date[i];
    }

    for (int i = 0; i < 6; i++)
    {
        second_date[i];
    }
}

bool check_if_leap(int year)
{
    bool is_div_by_four = (year % 4 == 0);
    bool exeption = (year % 100 == 0) && !(year % 400 == 0);
    return (is_div_by_four && !exeption);
}


int calc_day_of_year(int month, int day, bool is_leap)
{
    int num_of_days = 0;
    for(int m = 0; m < month; m++)
    {
        if (m == month - 1)
        {
            num_of_days += day;
        }
        else
        {
            num_of_days += is_leap ? leap_year[m] : non_leap_year[m];
        }
    }
    return num_of_days;
}



int main()
{

    int results[2000] = {0};
    int first_date[6] = {0};
    int second_date[6] = {0};
    int num_of_sets;

    std::cin >> num_of_sets;


    for (int i = 0; i < num_of_sets; i++)
    {
        int days_diff = 0;

        get_dates(first_date, second_date);

        if (first_date[0] == second_date[0])   // jeśli obydwie chwile są w tym samym roku
        {
            bool is_leap = check_if_leap(first_date[0]);
            int first_day_of_year = calc_day_of_year(first_date[1], first_date[2], is_leap);
            int second_day_of_year = calc_day_of_year(second_date[1], second_date[2], is_leap);
            days_diff = second_day_of_year - first_day_of_year;  // odjęcie liczby dni roku do chwili T1 od liczby dni roku do chwili T2
        }
        else
        {
            for (int year = first_date[0]; year <= second_date[0]; year++)
            {
                bool is_leap = check_if_leap(year);

                if (year == first_date[0])
                {
                    int day_of_year = calc_day_of_year(first_date[1], first_date[2], is_leap);
                    days_diff += is_leap ? 366 - day_of_year : 365 - day_of_year;  // obliczanie liczby dni od chwili T1 do końca roku
                }
                else if (year == second_date[0])
                {
                    days_diff += calc_day_of_year(second_date[1], second_date[2], is_leap);  // obliczanie liczby dni od chwili T2 do początku roku 
                }
                else
                {
                    days_diff += is_leap ? 366 : 365;  // dodawanie pełnych lat
                }
            }
        }

        int seconds_in_first_day = first_date[3] * seconds_in_hour + first_date[4] * seconds_in_minute + first_date[5];
        int seconds_in_last_day = second_date[3] * seconds_in_hour + second_date[4] * seconds_in_minute + second_date[5];
            
        if (seconds_in_day - seconds_in_first_day + seconds_in_last_day < seconds_in_day)
        {
            days_diff--;
        }

        results[i] = days_diff;
    }

    for (int i = 0; i < num_of_sets; i ++)
    {
        std::cout << results[i];
        std::cout << std::endl;
    }

    return 0;
}
    
