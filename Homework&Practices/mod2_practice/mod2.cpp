#include <iostream>
#include <iomanip>

using namespace std;


int main(){
    string user_color;
    int user_num; // Here I should likely use string user_num but since you directly asked for a int/number I figured Id limit to only ints.

    cout << "What is your Favorite color?\n";
    cout << "response: "; cin >> user_color;

    /*
     * I know I dont have to put a resposne section, but I prefer giving the person a indicator that they are giving a response.
     * Just trying to think as if they dont know that a blank empty line is meant for a response.
     */

    cout << "what is your favorite number?\n";
    cout << "response: "; cin >> user_num;

    cout << "Your favorite color is " << user_color << " and favorite number is " << user_num;

    return 0;

}
