/*File name: CelsiusToFahrenheit_ArraysAndPointers.cpp
*Author: Eisha Aqeel
*Date: March 24, 2022
*Description: This c++ program asks the user to enter Celsius temperature readings for anywhere between
*1 and 365 days, and stores them in a dynamically allocated array, then display a report showing both the
*Celsius and Fahrenheit temperatures for each day entered. This program usees pointers and dynamic memory allocation.
*/

#include <iostream>
#include <iomanip>

//Inline function for converting Celsius to Fahrenheit
inline double ConvertCelsiusToFahrenheit(double celsius) { return (celsius * (9.0 / 5.0)) + 32.0; }


// Output function receives an array of Celsius temperatures and the number of days, 
// and it displays a report showing the Celsius and Fahrenheit temperatures for each day.
void outputTemperature(double* temperatures, int days) {
	const char DEGREE_SYMBOL = static_cast<char>(248); // ASCII degree symbol

	std::cout << "\nDAILY TEMPERATURE REPORT";
	std::cout << "\n==========================\n";

	//keep loopng until all the days inputed are shown
	for (int index = 0; index < days; index++) {
		std::cout << "Day " << (index + 1) << ": " << temperatures[index] << DEGREE_SYMBOL << "C\t";
		std::cout << ConvertCelsiusToFahrenheit(temperatures[index]) << DEGREE_SYMBOL << "F" << std::endl;
	}
}

int main()
{
	//Declarations
	int userInputDays; // variable to represent the number of days the user wants to convert the temperature for
	double* ptrTemperature = nullptr; // initialized to nullptr at this point
	int returnValue = 0;

	//Ask for the amount of days
	std::cout << "How many days do you wish to enter? ";
	std::cin >> userInputDays;

	//as long as getting the input fails or the input is not in range, keep
	//showing this error message and repropting the user
	while (std::cin.fail() || userInputDays < 1 || userInputDays > 365)
	{
		//clear the input buffer and discard all remaining characters up to and including the newline character
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

		//show error message and reprompt
		std::cout << "Invalid input. Please enter a value between 1 and 365.\nHow many days do you wish to enter? ";
		std::cin >> userInputDays;
	}

	std::cout << "\nTEMPERATURE REPORTER";
	std::cout << "\n=====================";
	std::cout << "\nPlease enter the temperature for each day.\n";

	// Array allocation
	try {
		ptrTemperature = new double[userInputDays];

		for (int index = 0; index < userInputDays; index++) {
			// Prompt for and get the temperature for each day entered
			std::cout << "\nCelsius temperature for Day " << (index + 1) << ": ";
			std::cin >> ptrTemperature[index];
		}

		outputTemperature(ptrTemperature, userInputDays);

		// Done with the array. De-allocate the memory to avoid a memory leak.
		delete[] ptrTemperature;
	}
	catch (std::bad_alloc&) {
		std::cerr << "\nRUNTIME ERROR: Error allocating memory" << std::endl;
		returnValue = 1; // main returns 1 to indicate a problem
	}

	return returnValue; // either 0 or 1, depending on how the program ran.
}