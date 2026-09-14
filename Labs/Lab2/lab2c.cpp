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


using namespace std;

int main(){

    //vars
    string student_name("");

    int first_score(0);
    int second_score(0);
    int third_score(0);
    double total_score;

    double avg_score(0.0);

    // getting the students name
    cout << "What is the student's name?: ";
    getline(cin,student_name);


    //getting the students test grades
    cout << "Enter "<< student_name << "'s First test grade: ";
    cin >> first_score;
    cout << endl;

    cout << "Enter "<< student_name << "'s Second test grade: ";
    cin >> second_score;
    cout << endl;

    cout << "Enter "<< student_name << "'s Third test grade: ";
    cin >> third_score;
    cout << endl;

    //calc'ing the grades
    total_score = first_score + second_score + third_score;
    avg_score = total_score / 3;

    // outputting the information that they user wants to know
    cout << "With a total test score of: " << total_score << endl;
    cout << "Your average score is: " << avg_score << endl;

}
