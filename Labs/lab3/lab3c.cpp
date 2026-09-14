#include <iostream>
#include <cmath>
#include <string>

using namespace std;

int main(){

    //vars
    const double DOLLAR_AMOUNT(100);
    const double QUARTER_AMOUNT(25);
    const double DIME_AMOUNT(10);
    const double NICKEL_AMOUNT(5);
    const double PENNY_AMOUNT(1);

    //user refund amount
    double dollars_returned(0);
    double qtrs_returned(0);
    double dimes_returned(0);
    double nickels_returned(0);
    double pennies_returned(0);

    //user input
    int usr_input(0);

    cout << "Please provide the amount: ";
    cin >> usr_input;



    dollars_returned = usr_input / DOLLAR_AMOUNT;
    usr_input -= DOLLAR_AMOUNT;

    cout << dollars_returned << endl;
    cout << usr_input;

    return 0;
    
}   