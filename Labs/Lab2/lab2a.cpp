
/*
Title: lab_2a.cpp
Author: Cobain Irwin & Calvin Miller
Date: 20260831
Purpose: This program is written for waiters & waitresses at
TGI Fridays so that they can calculate total cost
of hot wings for their customers.
Note: This assignment was inspired by the movie
Zookeeper. I love this movie.
https://www.imdb.com/title/tt1222817/
*/



#include <iostream>
#include <iomanip>
using namespace std;
int main(){

    //define your variables here
    // consts
    const double WING_COST(.99);
    const double SALES_TAX(.085);

    //non-consts

    int wing_amount(0);
    double bill_total(0.00);
    double tax_amount(0.00);
    int width(15);
    /* The line below will allow floating point amounts to display
    two numbers after the decimal point. (it will make amounts pretty)
    */
    cout << setprecision(2) << fixed << showpoint;
    cout << "\n\nPlease input the number of hot wings purchased: ";

    //here we are getting the bill_amount from the user
    cin >> wing_amount;

    //Now we want to do the math to get wing_total
    bill_total = wing_amount * WING_COST;

    //wanted to make it a bit more user friendly and nice to look at.
    // we went over setw in class so I figured using it here wouldnt be an issue but incase
    // https://www.w3schools.com/cpp/ref_iostream_cout.asp - This is where I know it from
    cout << "Total before tax: " << setw(0) << right  << '$' << bill_total <<  endl;
    tax_amount = bill_total * SALES_TAX;
    cout << "____________________________" <<endl;

    cout << "Tax total: " << setw(8) << right << '$' << tax_amount << endl;
    bill_total += tax_amount;
    cout << "____________________________" <<endl;

    cout << "Bill total: " << setw(7) << right << '$' << bill_total << endl;
    cout << "____________________________" <<endl;


    // Fill in the input statement to bring in the quantity of hot wings.
    // Fill in the assignment statement to determine the total bill.
    // Fill in the output statement to print total bill as shown in

    return 0;
}
