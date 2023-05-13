/** OOP-IO-Streams-04.cpp
 *
 *	This program will write the following text to an output prices.txt
 *		Kettle     23.95
 *		Toaster    25.49
 *		Stove      549.99
 *		Microwave  99.00
 *
 *	@author		Eisha Aqeel
 *	@since		April 12, 2022
 *	@see 		Bronson, G. (2012).  Chapter 9 I/O Streams and Data Files.
 *					In A First Book of C++ (4th ed.).
 *					Boston, MA: Course Technology.
*/

#include <iostream>
#include <iomanip>
#include <fstream>	// needed for ifstream class
using namespace std;

int main()
{
	// DECLARATIONS
	string fileName = "prices.txt";	// hold the file name to open
	ofstream outFile;		// an ofstream object to connect to the file
	int returnValue = 0; 	// holds the return value for main()

	cout << "OOP IO Streams 04" << endl
		<< "==================" << endl;

	// Open the file	 
	outFile.open(fileName.c_str());

	if (outFile.fail()) // If the output file could not be opened
	{
		// Inform the user
		cout << "\nThe file was NOT successfully opened for output." << endl;
		// set the return value of main() to '1' indicating the program did not execute successfully
		returnValue = 1; 
	}
	else
	{
		// All is good. We are ready to write to the file!
		outFile << "Kettle 23.95\n";
		outFile << "Toaster 25.49\n";
		outFile << "Stove 549.99\n";
		outFile << "Microwave 99.00";

		outFile.close(); // close the file.

		// Inform the user
		cout << "\nThe file has been successfully written to." << endl;
	}

	cout << endl << endl;
	return returnValue;
} // end of main

