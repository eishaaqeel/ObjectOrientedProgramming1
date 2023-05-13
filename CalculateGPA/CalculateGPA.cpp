/*
 * File:   CalculateGPA.cpp
 * Author: Eisha Aqeel
 * Date: February 12, 2022
 * Description: This program is to practice functions and create
 *              a calculator that shows the GPA of the grade entered.
 */

#include <iostream>
#include <iomanip>
#include <cmath>
#include <limits>
#include <stdexcept>

using namespace std;

/// <summary>
/// GradePoints function
/// </summary>
/// <param name="grade"></param>
/// <returns>points</returns>
double GradePoints(double grade) {
    double points;
    grade = round(grade);

    if (grade < 50) {
        points = 0.0;
    }
    else if (grade <= 54) {
        points = 1.0;
    }
    else if (grade <= 59) {
        points = 1.5;
    }
    else if (grade <= 64) {
        points = 2.0;
    }
    else if (grade <= 69) {
        points = 2.5;
    }
    else if (grade <= 74) {
        points = 3.0;
    }
    else if (grade <= 79) {
        points = 3.5;
    }
    else if (grade <= 84) {
        points = 4.0;
    }
    else if (grade <= 89) {
        points = 4.5;
    }
    else {
        points = 5.0;
    }

    return points;
}

int main() {
    cout << "Enter percentage grades to convert to grade points. ";
    cout << "Enter '-1' to quit anytime." << endl;
    bool keepLooping = true;
    double grade;

    try {
        do {
            cout << "Percentage grade: ";
            cin >> grade;

            if (grade == -1) {
                cout << "Good-bye!" << endl;
                keepLooping = false;
            }
            else if (grade < 0 || grade > 100) {
                throw out_of_range("Grade must be between 0 and 100");
            }
            else {
                double points = GradePoints(grade);
                cout << fixed << setprecision(1);
                cout << grade << "% is " << points << " grade points." << endl;
            }
        } while (keepLooping);
    }
    catch (const out_of_range& ex) {
        cout << "Exception occurred: " << ex.what() << endl;
        return 1;
    }
    return 0;
}