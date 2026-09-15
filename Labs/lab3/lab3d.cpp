/*
Title: lab_2b.cpp
Author: Cobain Irwin 
Date: 20260914
Purpose:Create a user a login username based off the information that they provide
First name: last: some number

*/
#include <iostream>
#include <string>


using namespace std;

int main(){

    string created_usr_name("");
    string usr_first_name("");
    string usr_last_name("");
    int usr_digits(0);
    string last_two_digits("");
    
    
    cout << "Please provide your login information.\n";
    cout << "First name: ";
    cin >> usr_first_name;
    cout << "Last name: ";
    cin >> usr_last_name;
    cout << "Four-to-Eight digit number: ";
    cin >> usr_digits;
    

    int last_two_nums = usr_digits % 100;
    
    if (usr_last_name.length() < 5) 
    {
        created_usr_name = usr_last_name.substr(0, usr_last_name.length()) + usr_first_name.at(0);
    }
    else
    {
        created_usr_name = usr_last_name.substr(0, 5) + usr_first_name.at(0);
    }
    
    if (last_two_nums < 10)
    {
        cout << created_usr_name << "0" << last_two_nums << endl;
    }
    else
    {
        cout << created_usr_name << last_two_nums << endl;
    }
    return 0;
}