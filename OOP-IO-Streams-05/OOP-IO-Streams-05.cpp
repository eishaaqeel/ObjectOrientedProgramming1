/** OOP-IO-Streams-05.cpp
 *
 *	This program will attempt to read from a text file.
 *	Code a loop to read each item description and price and output them
 *	neatly in two columns.
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
	ifstream inFile;		// an ifstream object to connect to the file
	string description;		// holds the item description read from the file
	double price;			// holds the item price read from the file
	int returnValue = 0; 	// holds the return value for main()


	cout << "OOP IO Streams 05" << endl
		<< "=====================" << endl;

	// Open the file	 
	inFile.open(fileName.c_str());

	if (inFile.fail()) // If the input file could not be opened
	{
		// Inform the user
		cout << "\nThe file was NOT successfully opened. "
			<< "Check that the file exists" << endl;

		// set the return value of main() to '1' indicating the program did not execute successfully
		returnValue = 1; 
	}
	else
	{
		// All is good. We are ready to read from the file!
		// set the console output formatting
		cout << setiosflags(ios::fixed)
			<< setiosflags(ios::showpoint)
			<< setprecision(2);

		cout << left << setw(10) << "ITEM"
			<< right << setw(6) << "PRICE" << endl;

		// Use a loop to read each item description and price and
		// output them neatly in two columns.
		while (inFile.good()) {
			inFile >> description;
			inFile.ignore();
			inFile >> price;
			if (!inFile.eof())
				while (inFile.get() != '\n');
			cout << left << setw(10) << description
				<< right << setw(6) << price << endl;
		}

		inFile.close(); // close the file.

	}

	cout << endl << endl;
	return returnValue;
} // end of main
