// Author: Eisha Aqeel
// Date: March 31, 2022
// File name: Vectors.cpp
// Description: I created a vector with a type and size of my choosing, and put values inside it.
//              I also used 5 functions from the vector library, showing outputs when needed.

#include <vector>
#include <iostream>

using namespace std;

int main()
{
    //create vector of type string
    vector<string> colors{ "Red", "Orange", "Yellow", "Green", "Blue", "Indigo" };

    //vector::front()
    //gets the first element of the vector
    cout << "The rainbow starts with the color " << colors.front() << endl;

    //vector::push_back()
    //adds a value to the end of the vector
    colors.push_back("Violet");

    //vector::back()
    //gets the last element of the vector
    cout << "The rainbow ends with the color " << colors.back() << endl;

    //vector::size()
    //returns the size of the vector (the number of elements in the vector)
    cout << "Rainbows have " << colors.size() << " colors" << endl;

    //vector::at()
    //is used to reference the element at the position given 
    cout << "My favourite color is " << colors.at(4) << endl;

    return 0;
}