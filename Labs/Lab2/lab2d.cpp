/*
Title: lab_2b.cpp
Author: Cobain Irwin & Calvin Miller
Date: 20260831
Purpose: we are calculating the cost of what seems to be a grocery hual of a few items.
we are taking in the name of an item, the amout of item bought and the price of said item.
we are getting the name of two items from the user then the price and providing the cost of items with sales tax.
*/

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

int main()
{
    // Variables
    // Each stolen bone results in 83 days in prison
    const int BONES_TO_DAYS(83);
    // a yr has 365 days :D
    const int DAYS_IN_YR(365);

    
    int stolen_bonez(0);
    int days_in_prison(0);
    int yrs_in_prison(0);
    int remainder_days_in_prison(0);

    cout << "How many bones has the defendant stolen? Answer the court: ";
    cin >> stolen_bonez;

    // Calculate total prison sentence in days
    days_in_prison = BONES_TO_DAYS * stolen_bonez;

    cout << "\n*Gasps echo throughout the courtroom*\n";
    cout << "How could anyone do such a thing? The defendant has stolen "
         << stolen_bonez << " bones!\n";

    cout << "The court must now determine the appropriate punishment...\n\n";

    // Convert total days into years and remaining days
    yrs_in_prison = days_in_prison / DAYS_IN_YR;
    remainder_days_in_prison = days_in_prison % DAYS_IN_YR;

    cout << "\n...after some deliberation...\n";
    cout << "...and some more deliberation...\n\n";

    cout << "*The judge enters the courtroom and takes a seat.*\n";
    cout << "\"We have found the defendant guilty on all charges.\"\n\n";

    cout << "The defendant is hereby sentenced to "
         << yrs_in_prison << " years and "
         << remainder_days_in_prison << " days in prison, "
         << "for a total sentence of " << days_in_prison << " days." << endl;

    return 0;
}