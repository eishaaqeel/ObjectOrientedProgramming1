/*
* Author: Eisha Aqeel
* Date: April 16, 2022
* File name: DataStructure.cpp
* Description: The aim of this program is to create a data structure to store basic pay record information.
			   I will use the structure to store raw pay record data, read from a data file, and produce a formatted report as a text file.
*/

#include <iostream>
#include <iomanip>
#include <fstream>	// needed to read from and write to files
#include <vector>
#include <iterator>

using namespace std;

struct PayRecord {
	string first_name;
	string last_name;
	double hours_worked; //number of hours worked this week
	double wage_per_hour;
};

int main()
{
	// DECLARATIONS
	string fileName = "hours.txt";
	ifstream inFile;  // an ifstream object to connect to the input file
	string fileName2 = "pay.txt";
	ofstream outFile;  // an ofstream object to connect to the output file
	int returnValue = 0;  // holds the return value for main()
	struct PayRecord record[5];  // struct array
	double totalPay = 0.0; // to store the total pay

	// Open the "hours.txt" file	 
	inFile.open(fileName.c_str());

	// If the input file "hours.txt" could not be opened
	if (inFile.fail())
	{
		// Inform the user
		cout << "\nThe file hours.txt was NOT successfully opened. "
			<< "Check that the file exists." << endl;

		// set the return value of main() to '1' indicating the program did not execute successfully
		returnValue = 1;
	}
	else
	{
		// Open file 2	 
		outFile.open(fileName2.c_str());

		// If this output file could not be opened
		if (outFile.fail())
		{
			// Inform the user
			cout << "\nThe file pay.txt was NOT successfully opened for output." << endl;
			// set the return value of main() to '1' indicating the program did not execute successfully
			returnValue = 1;   
		}
		else
		{
			// Write to the file "pay.txt"
			outFile << "PAY FOR THIS WEEK\n";
			outFile << "=========================\n\n";
			//for loop, while storing the data being read into the struct
			for (int i = 0; i < 5; i++) {
				inFile >> record[i].first_name;
				inFile >> record[i].last_name;
				inFile >> record[i].hours_worked;
				inFile >> record[i].wage_per_hour;

				//calculate the weeklyPay for each person
				double weeklyPay = record[i].hours_worked * record[i].wage_per_hour;

				// Keep addind the pay for each person to the totalPay variable
				totalPay += weeklyPay;

				//output the first letter of the first_name and then add a dot
				outFile << record[i].first_name.at(0) << ". " 
					//then output the full last_name
					<< record[i].last_name 
					//then output each persons weeklyPay 
					<< "  $ " << weeklyPay << endl;
			}
			outFile << "\n=========================\n";
			//finally output the total pay to the file
			outFile << "    Total:  $ " << totalPay << endl;

			outFile.close(); // close the pay.txt file when complete

			// Inform the user
			cout << "\nThe file pay.txt has been successfully written to." << endl;
		}

		inFile.close(); // close the hour.txt file when complete
	}

	cout << endl << endl;
	return returnValue;
}