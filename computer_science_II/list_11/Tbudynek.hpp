 #pragma once
 #include <iostream>
 using namespace std;

 class Tbudynek
 {
    private:
     int House_Num, Flat_Num, Post_Code;
     string Street, City;

    public:
    Tbudynek();
    Tbudynek(string Street, int House_Num, int Post_Code, string City);
    Tbudynek(string Street, int House_Num, int Flat_Num, int Post_Code, string City);
    ~Tbudynek();
    void set_house_num(int num);
    void set_flat_num(int num);
    void set_post_code(int code);
    void set_street(string street);
    void set_city(string city);
    int get_house_num();
    int get_flat_num();
    int get_post_code();
    string get_street();
    string get_city();
    friend ostream &operator<<(ostream& stream, const Tbudynek &adress);
 };