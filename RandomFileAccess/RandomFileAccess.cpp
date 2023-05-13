/** RandomFileAccess.cpp
 *
 *	Random File Access Example for C++ Programming. This program
 *  will read from a file by manipulating the file position marker
 *  and write to a different file.
 *
 *	@author		Eisha Aqeel, Professor Thom MacDonald
 *	@since		April 12, 2022
 *	@see 		Bronson, G. (2012).  Chapter 9 I/O Streams and Data Files.
 *					In A First Book of C++ (4th ed.).
 *					Boston, MA: Course Technology.
 *  @see		http://www.cplusplus.com/reference/istream/istream/seekg/
 *  @see		http://www.cplusplus.com/reference/istream/istream/tellg/
*/

#include <iostream>
#include <fstream>	// needed for ifstream class
using namespace std;

int main()
{
	// DECLARATIONS
	string sourceFileName = "source.txt";
	string targetFileName = "target.txt";

	ifstream inFile;		// an ifstream object to connect to the file
	int returnValue = 0; 	// holds the return value for main()

	ofstream outFile;

	cout << "Random File Access Example" << endl
		<< "============================" << endl;

	// Open the input file	 
	inFile.open(sourceFileName.c_str());

	if (inFile.fail()) // If the input file could not be opened
	{
		// Inform the user
		cout << "\nThe input file was NOT successfully opened. "
			<< "Check that the file exists" << endl;

		// set the return value of main() to '1' indicating the program did not execute successfully
		returnValue = 1;
	}
	else // input file is open
	{
		// Open the output file	 
		outFile.open(targetFileName.c_str());

		if (outFile.fail()) // If the output file could not be opened
		{
			// Inform the user
			cout << "\nThe output file was NOT successfully opened. " << endl;

			// close the input file
			inFile.close();
			// set the return value of main() to '1' indicating the program did not execute successfully
			returnValue = 1;  
		}
		else // output file is open
		{
			long lastPosition; 	 // will hold the last position from the input file
			char inputCharacter; // holds a single character of input

			// Move the file position marker to the end of the input file.
			inFile.seekg(0L, ios_base::end); // offset 0 bytes from the end of the input file
			// note: other positions to offset from: ios_base::cur, ios_base::beg

			// save that position 
			lastPosition = inFile.tellg(); // note: seekg/tellg for input, seekp/tellp for output

			// loop from 1 up to the end, with a counter called offset
			for (long offset = 1L; offset <= lastPosition; offset++)
			{
				// move to the input position we want: "offset" bytes to the left (-) of the end
				inFile.seekg(-offset, ios_base::end);
				// read the character at that position
				inputCharacter = inFile.get(); // inFile >> inputCharacter would skip whitespace
				// write the character to the output file.
				outFile << inputCharacter;
			}

			cout << "All done! Open " << targetFileName << " to see the result." << endl;
			// close the files.
			inFile.close();
			outFile.close();
		}

	}

	cout << endl << endl;
	return returnValue;
} // end of main
