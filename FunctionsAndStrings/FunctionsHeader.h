/*
 *  File name: FunctionsHeader.h
 *	Description: This file includes the functions IsNumeric & ReadDouble that are used in FunctionsAndStrings.cpp.
 *  Date: April 7, 2022
 *  @author	Eisha Aqeel
 */

//ensure that the code will only be included once, 
//which helps prevent duplicate definitions and other issues that can arise from multiple inclusions.
//first check if FUNCTIONSHEADER_H has not been defined before,
#ifndef FUNCTIONSHEADER_H
//if FUNCTIONSHEADER_H was not defined, define it now
#define FUNCTIONSHEADER_H

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>

namespace FunctionsHeader
{
	/**
	 * Checks if a given string represents a numeric value.
	 *
	 * @param theString The string to be checked.
	 * @return True if the string represents a numeric value, false otherwise.
	 */
	bool IsNumeric(const std::string& theString)
	{
		bool isNumeric = true; // assume the string is a valid int

		// Is the string empty?
		if (theString.empty())
		{
			// then it cannot be an int
			isNumeric = false;
		}
		else // the string is not empty
		{
			int digitCount = 0; // counts the digits
			int decimalPointCount = 0; // counts the decimal points
			char character;	// for examining each character
			char firstCharacter = theString.at(0);
			//If The first character of the string is NOT a digit, NOT a minus sign ('-'), or NOT a plus sign ('+'),
			if (!isdigit(firstCharacter) && firstCharacter != '-' && firstCharacter != '+')
			{
				isNumeric = false; // the string is not a number
			}
			else
			{
				//if the firstCharacter is - or +
				if (firstCharacter == '-' || firstCharacter == '+')
				{
					if (theString.length() == 1)
					{
						isNumeric = false; // the string is not a number (only contains the sign)
					}
					else
					{
						char secondCharacter = theString.at(1);
						if (!isdigit(secondCharacter))
						{
							isNumeric = false; // the string is not a number (no digit after the sign)
						}
					}
				}
			}

			// Process the rest of the characters
			for (size_t i = 1; isNumeric && i < theString.length(); i++)
			{
				char character = theString.at(i);
				
				if (isdigit(character))
				{
					digitCount++;
				}
				else if (character == '.')
				{
					decimalPointCount++;
				}
				else
				{
					//If any character is not a digit or a decimal point ('.'), the string is not considered numeric.
					isNumeric = false;
				}
			}

			// Check the digit and decimal point counts
			if (digitCount < -1 || decimalPointCount > 1)
			{
				isNumeric = false; // the string is not a number
			}
		}

		// return whether the string is a number or not
		return isNumeric;
	}

	/**
	 * Reads a double value from the user, ensuring that the input is within the specified range
	 *
	 * @param MIN
	 * @param MAX
	 * @return validNumber as a Double
	 */
	double ReadDouble(const double MIN, const double MAX)
	{
		std::string validNumber; // holds the user input

		while (true)
		{
			std::cin >> validNumber; // try to get input

			// if user input fails
			if (std::cin.fail())
			{
				std::cin.clear(); // Reset the fail() state of the cin object.
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // clear the buffer
				// report the problem to the user.
				std::cout << "* '" << validNumber << "' is not numeric. Please try again and enter a numeric value.\n";
			}
			else
			{
				//convert from string to double using std::stod
				// if value is lees then MIN or more then MAX
				if (std::stod(validNumber) < MIN || std::stod(validNumber) > MAX)
				{
					// report the problem to the user.
					std::cout << "* '" << std::stod(validNumber) << "' is out of range. Please try again and enter a value between "
						<< MIN << " and " << MAX << ".\n";
				}
			}
			return std::stod(validNumber);
		}
	}
}
#endif // FUNCTIONSHEADER_H