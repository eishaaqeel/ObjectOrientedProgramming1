/*
* Author: Eisha Aqeel
* Date: April 16, 2022
* File name: Enumerators.cpp
* Description: Enumerator example
*   Enumerators(enums) in C++ store values as integers, so it is a way to give names to a int values, in one place. 
* Code does not look like it is using numbers but behind the variables in an enum, it is numbers staring from 0. 
* If you do not want the enum to start with 0, you could assign different integers to the list. 
* You can use enumeration as an alternative to a constant data type, or when you have several objects that you want to group together. 
*/

#include <iostream>

using namespace std;

int main()
{
    //creating an enumerator named season
    enum season {
        fall, winter, spring, summer
    };

    cout << "Pick a season by typing:\n 0 for Fall \n 1 for Winter \n 2 for Spring \n 3 for Summer \n" << endl;
    int pick;
    cin >> pick;

    if (pick == fall) {
        cout << "Enjoy raking leaves\n";
    }
    else if (pick == winter) {
        cout << "Stay warm\n";
    }
    else if (pick == spring) {
        cout << "Look at the flowers outside\n";
    }
    else if (pick == summer) {
        cout << "Enjoy the sunshine\n";
    }
}
