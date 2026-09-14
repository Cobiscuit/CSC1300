#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main(){

    //vars
    int user_year(0);
    int leap_yr_math_400(0);
    int leap_yr_math_4(0);

    //bools
    bool leap_year(false);

    cout << "Please provide the year that you want to know is a leap year or not!\n";
    cout << "Reponse: ";
    cin >> user_year;


    //leap_yr_math_400 = user_year % 400;
    //leap_yr_math_4 = user_year % 4;

    if ((user_year % 400 == 0) || 
        ((user_year % 4 == 0) && (user_year % 100 != 0)))
    {
        
        cout << "True. The year: " << user_year << " is a leap year\n";
    }
    else
    {
        cout << "False. The year: " << user_year << " isn't a leap year\n";
    }

    return 0;
}