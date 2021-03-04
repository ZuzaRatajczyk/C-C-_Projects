#include <iostream>

const int leap_year[12] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
const int non_leap_year[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
const int seconds_in_minute = 60;
const int seconds_in_hour = 60 * seconds_in_minute;
const int seconds_in_day = 24 * seconds_in_hour;

struct Date
{
    int year;
    int month;
    int day;
    int hour;
    int minute;
    int second;
};

void get_dates(Date Dates[2])
{
    for (int i = 0; i < 2; i++)
    {
        std:: cin >> Dates[i].year;
        std::cin >> Dates[i].month;
        std::cin >> Dates[i].day;
        std::cin >> Dates[i].hour;
        std::cin >> Dates[i].minute;
        std::cin >> Dates[i].second;
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
    Date Dates[2];
    int num_of_sets;

    std::cin >> num_of_sets;


    for (int i = 0; i < num_of_sets; i++)
    {
        int days_diff = 0;

        get_dates(Dates);

        if (Dates[0].year == Dates[1].year)   // jeśli obydwie chwile są w tym samym roku
        {
            bool is_leap = check_if_leap(Dates[0].year);
            int first_day_of_year = calc_day_of_year(Dates[0].month, Dates[0].day, is_leap);
            int second_day_of_year = calc_day_of_year(Dates[1].month, Dates[1].day, is_leap);
            days_diff = second_day_of_year - first_day_of_year;  // odjęcie liczby dni roku do chwili T1 od liczby dni roku do chwili T2
        }
        else
        {
            for (int year = Dates[0].year; year <= Dates[1].year; year++)
            {
                bool is_leap = check_if_leap(year);

                if (year == Dates[0].year)
                {
                    int day_of_year = calc_day_of_year(Dates[0].month, Dates[0].day, is_leap);
                    days_diff += is_leap ? 366 - day_of_year : 365 - day_of_year;  // obliczanie liczby dni od chwili T1 do końca roku
                }
                else if (year == Dates[1].year)
                {
                    days_diff += calc_day_of_year(Dates[1].month, Dates[1].day, is_leap); // obliczanie liczby dni od chwili T2 do początku roku
                }
                else
                {
                    days_diff += is_leap ? 366 : 365;  // dodawanie pełnych lat
                }
            }
        }

        int seconds_in_first_day = Dates[0].hour * seconds_in_hour + Dates[0].minute * seconds_in_minute + Dates[0].second;
        int seconds_in_last_day = Dates[1].hour * seconds_in_hour + Dates[1].minute * seconds_in_minute + Dates[1].second;

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
    
