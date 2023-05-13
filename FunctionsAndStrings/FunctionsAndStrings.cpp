/*
 *  File name: FunctionsAndStrings.cpp
 *  Date: April 7, 2022
 *  @author	Eisha Aqeel
 *	Description: This program is to test that the IsNumeric() and ReadDouble() functions work correctly.

 */

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>

#include "FunctionsHeader.h"

int main()
{
	// Declarations
	const double MINIMUM = -99.9; // the minimum value accepted for user input
	const double MAXIMUM = 99.9;  // the maximum value accepted for user input
	const int COLUMN = 12;	// for output formatting
	double number; // to hold validated user input

	// strings to test the IsNumeric() function
	std::vector<std::string> testCases
	{
		"123.45",	// yes
		"chicken",  // no
		"+11.999",  // yes
		"2.3.3",	// no
		"-8.77"		// yes
	};

	// Output an information header
	std::cout << "Functions And Strings" << std::endl
		<< "=======================" << std::endl << std::endl;

	// Output column headings
	std::cout << std::left << std::setw(COLUMN) << "Test Case" << "Numeric?" << std::endl
		<< std::setw(COLUMN) << "=========" << "========" << std::endl << std::endl;

	// for each test string in the test cases vector
	for (const auto& testString : testCases)
	{
		// output the test string
		std::cout << std::left << std::setw(COLUMN) << testString;
		// if the test string is numeric output "yes"
		if (FunctionsHeader::IsNumeric(testString))
		{
			std::cout << "yes" << std::endl;
		}
		else
		{
			// else output "no"
			std::cout << "no" << std::endl;
		}
	}

	// Prompt the user to input something
	std::cout << "\nEnter a number between " << MINIMUM << " and " << MAXIMUM
		<< ", or enter anything else: ";

	try {
		// Call ReadDouble() function
		number = FunctionsHeader::ReadDouble(MINIMUM, MAXIMUM);

		//only do IsNumeric if the user input (number) is greater then or equal to MINIMUM
		//and less then or equal to MAXIMUM
		if (number >= MINIMUM && number <= MAXIMUM) {
			std::cout << "\nIf you entered '" << number;
			// if the test string is numeric, tell the user
			if (FunctionsHeader::IsNumeric(std::to_string(number)))
			{
				std::cout << "' that would be Numeric." << std::endl;
			}
			else
			{
				//else say:
				std::cout << "' that is Not Numeric." << std::endl;
			}
		}
	}
	catch (const std::exception& e)
	{
		std::cout << "\nThat was Not Numeric!" << std::endl;
	}

	// end of program.			 
	std::cout << std::endl << std::endl;
	return 0;
}
