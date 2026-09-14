
#include <iostream>
#include <string>
using namespace std;
int main()
{
    //vars
    const double PI = 3.14159;
    string fullName("");
    double circumference, diameter;

    
    
    cout << "What is the diameter of the circle?\n";
    cin >> diameter;
    cout << "What is your first & last name?\n";

    //cal here
    circumference = PI * diameter ;

    cin.ignore();
    
    getline(cin, fullName);
    cout << "Hello, " << fullName << "! The circumference of your circle is: " << circumference;
    cout << endl << endl;
    return 0;
}
