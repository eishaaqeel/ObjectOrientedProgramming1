/*
 * File:   main.cpp
 * Author: Eisha Aqeel
 * Date: February 4, 2022
 * Description: This program is to practice logic structures and
 * in this program I prompt each archer (3) and calculate each
 * individuals end scores. Then display the total score for each archer,
 * and the calculated overall average end score.
 */

#include <iostream>

using namespace std;

int main() {

    int archer1Round1 = 0, archer1Round2 = 0, archer1Round3 = 0, archer1Round4 = 0,
        archer2Round1 = 0, archer2Round2 = 0, archer2Round3 = 0, archer2Round4 = 0,
        archer3Round1 = 0, archer3Round2 = 0, archer3Round3 = 0, archer3Round4 = 0,
        tempInput, ii, r;

    //get scores of each archer
    for (ii = 0; ii < 3; ii++) {//for loop runs 3 times (3 archers)
        for (r = 0; r < 4; r++) {//nested for loop runs 4 times (4 rounds)
            do {
                cout << "Please enter archer " << ii + 1 << "'s round " << r + 1 << " score: ";
                cin >> tempInput;
                if (tempInput < 0 || tempInput > 60) {
                    cout << "Error: Scores entered must be between 0 - 60" << endl;
                }
            } while (tempInput < 0 || tempInput > 60); //This is the acceptable range of scores
            if (ii == 0) {//archer number 1's turn
                if (r == 0) {
                    archer1Round1 = tempInput;
                }
                else if (r == 1) {
                    archer1Round2 = tempInput;
                }
                else if (r == 2) {
                    archer1Round3 = tempInput;
                }
                else if (r == 3) {
                    archer1Round4 = tempInput;
                }
            }
            else if (ii == 1) {//Second archer's turn
                if (r == 0) {
                    archer2Round1 = tempInput;
                }
                else if (r == 1) {
                    archer2Round2 = tempInput;
                }
                else if (r == 2) {
                    archer2Round3 = tempInput;
                }
                else if (r == 3) {
                    archer2Round4 = tempInput;
                }
            }
            else {//Third archer's turn
                if (r == 0) {
                    archer3Round1 = tempInput;
                }
                else if (r == 1) {
                    archer3Round2 = tempInput;
                }
                else if (r == 2) {
                    archer3Round3 = tempInput;
                }
                else if (r == 3) {
                    archer3Round4 = tempInput;
                }
            }
        }
    }
    // The total score for each archer
    int archer1Total = archer1Round1 + archer1Round2 + archer1Round3 + archer1Round4;
    cout << "The total score for archer 1 is: " << archer1Total << endl;
    int archer2Total = archer2Round1 + archer2Round2 + archer2Round3 + archer2Round4;
    cout << "The total score for archer 2 is: " << archer2Total << endl;
    int archer3Total = archer3Round1 + archer3Round2 + archer3Round3 + archer3Round4;
    cout << "The total score for archer 3 is: " << archer3Total << endl;
    // Overall average end score
    int overallAverage = ((archer1Total + archer2Total + archer3Total) / 3);
    cout << "Overall average is: " << overallAverage << endl;

    return 0;
}