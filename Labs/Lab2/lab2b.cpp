/*
Title: lab_2b.cpp
Author: Cobain Irwin & Calvin Miller
Date: 20260831
Purpose: we are calculating the cost of what seems to be a grocery hual of a few items.
we are taking in the name of an item, the amout of item bought and the price of said item.
we are getting the name of two items from the user then the price and providing the cost of items with sales tax.
*/

#include <iostream>
#include <iomanip>
#include <string>


using namespace std;

int main(){ 

    //consts
    const double SALES_TAX(.0975);

    //regular vars
    string first_item("");
    int first_item_quantity(0);
    double first_item_cost(0.00);
    double first_item_total(0.00);

    string second_item("");
    int second_item_quantity(0);
    double second_item_cost(0.00);
    double second_item_total(0.00);

    double sales_tax_amount(0.0);
    double items_total(0);

    // getting user input on item one
    cout << "Please input the name of the first item: ";
    getline(cin,first_item);
    cout << "Please input the number of " << first_item << " bought: ";
    cin >> first_item_quantity;
    cout << "Please input the price of " << first_item << ": $";
    cin >> first_item_cost;


    // we spoke about this in class, since we are using getlin() we have to do a cin.ignore for you to be able to use a second one and so on
    cin.ignore();

    // we need to ensure we are working in doallahs(dollars...)
    cout << fixed << showpoint << setprecision(2);

    // we are calcing the first items info
    first_item_total = first_item_cost * first_item_quantity;
    cout << "First item cost: $" << first_item_total << endl << endl;

    // getting input of item two
    cout << "Please input the name of the Second item: ";
    
    getline(cin,second_item);
    cout << "Please input the number of " << second_item << " bought: ";
    cin >> second_item_quantity;
    cout << "Please input the price of " << second_item << ": $";
    cin >> second_item_cost;

    
    // we are calcing the second items info
    second_item_total = second_item_cost * second_item_quantity;
    cout << "Second item total cost: $" << second_item_total << endl << endl;

    cin.ignore();
    
    // here we are taking the total of the first item and adding it with the second items total

    items_total = first_item_total + second_item_total;

    // then we need to get the sales_tax_amount and make its own var in case we want to print just the sales tax amt
    sales_tax_amount = items_total * SALES_TAX;

    // this is the total of the items along with sales tax
    items_total += sales_tax_amount;
    
    // now we inform the user how much debt they are in for wanting to buy {insert item here}(I chose potatos)...
    cout << "The total bill is: $" << items_total << endl;

        



    return 0;
}